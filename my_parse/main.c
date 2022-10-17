/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 20:27:20 by alewalla          #+#    #+#             */
/*   Updated: 2022/08/30 22:56:36 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*rl_gets(char *line_read)
{
	line_read = readline("minishell: ");
	if (line_read && *line_read)
		add_history(line_read);
	return (line_read);
}

int	main(int ac, char **av, char **envp)
{
	char	*line_read;
	t_tok	*token;

	(void)ac;
	(void)av;
	(void)envp;
	token = (t_tok *)malloc(sizeof(t_tok));
	//envl = (t_env *)malloc(sizeof(t_env));
	//ft_envp_to_envl(envp, envl);
	while (1)
	{
		line_read = NULL;
		line_read = rl_gets(line_read);
		if (line_read == NULL)
		{
			printf("exit\n");
			ft_free_tokenl(token);
			free(line_read);
			exit(0); //TMP
		}
		if (line_read != NULL)
		{
			ft_parsing(line_read, token);
			//ft_expand(token);
		}
		ft_putstruct(token);
		ft_free_tokenl(token);
		free(line_read);
	}
}