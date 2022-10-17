/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:22:02 by thbierne          #+#    #+#             */
/*   Updated: 2022/09/13 13:37:18 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ret_value;

char	*rl_gets(char *line_read)
{
	line_read = readline("minishell: ");
	if (line_read == NULL)
	{
		printf("exit\n");
		exit(0); //TMP
	}
	if (line_read && *line_read)
		add_history(line_read);
	return (line_read);
}

int	ft_check(char *arg, char *str)
{
	int	i;

	i = 0;
	while (arg[i] && str[i])
	{
		if (arg[i] != str[i])
			return (0);
		i++;
	}
	if (arg[i] != str[i])
		return (0);
	else
		return (1);
}

int	ft_builtin(int ac, char **arg, t_env *envl)
{
	if (ft_check(arg[1], "cd"))
	{
		ft_cd(ac, &arg[1], envl);
		return (1);
	}
	else if (ft_check(arg[1], "echo"))
	{
		ret_value = ft_echo(ac, &arg[2]);
		return (1);
	}
	else if (ft_check(arg[1], "pwd"))
	{
		ft_pwd();
		return (1);
	}
	else if (ft_check(arg[1], "export"))
	{
		ret_value = ft_export(ac, &arg[2], envl);
		return (1);
	}
	else if (ft_check(arg[1], "unset"))
	{
		ft_unset(&arg[2], envl);
		return (1);
	}
	else if (ft_check(arg[1], "env"))
	{
		ft_print_envl(envl);
		return (1);
	}
	else if (ft_check(arg[1], "exit"))
	{
		if (arg[2] != NULL)
			ft_exit(atoi(arg[2]), envl, arg);
		ft_exit(0, envl, arg);
		return (1);
	}
	else
		return (0);
}

int	ft_execution(int ac, char **arg, t_core *core)
{
	int		pid;
	char	**envp;
	int		i;

	i = -1;
	envp = NULL;
	if (ac == 0)
		return (0);
	if (ft_builtin(ac, arg, core->envl))
		;
	else
	{
		arg[1] = ft_test_cmd(core, arg[1]);
		pid = fork();
		if (pid < 0)
			return (1);
		if (pid == 0)
		{
			envp = ft_envl_to_envp(core->envl);
			execve(arg[1], &arg[1], envp);
			printf("%s: command not found\n", arg[1]);
			ft_free_envp(envp);
			ft_exit(0, core->envl, arg);
		}
		waitpid(pid, NULL, 0);
	}
	return (ret_value);
}

void	ft_exit(int nbr, t_env *envl, char **arg)
{
	ft_free_envl(envl);
	clear_history();
	free(arg);
	exit(nbr);
	return ;
}

int	main(int ac, char **av, char **envp)
{
	char				*line_read;
	char				**tab_line;
	t_core				*core;
	//	struct sigaction	s_sigaction;

	(void)ac;
	(void)av;
	signal(SIGQUIT, SIG_IGN);
	//s_sigaction.sa_handler = inthandler;
	//sigaction(SIGINT, &s_sigaction, 0);
	signal(SIGINT, inthandler);
	core = (t_core *)malloc(sizeof(t_core));
	core->envl = (t_env *)malloc(sizeof(t_env));
	core->path = (t_path *)malloc(sizeof(t_path));
	ft_envp_to_envl(envp, core->envl);
	ft_alloc_path_tab(core);
	//printf("tab_env: %s\n", core->path->path_env);
	//ft_puttab(core->path->path_tab);
	while (1)
	{
		line_read = NULL;
		line_read = rl_gets(line_read);
		if (line_read)
			line_read = ft_replace_dollar(line_read, core->envl, 0);
		tab_line = alloc_cmd(line_read);
		ret_value = ft_execution(atoi(tab_line[0]), &tab_line[0], core);
		//printf("ret : %d\n", ret_value);
		free(tab_line);
	}
	ft_exit(0, core->envl, av);
	return (0);
}
