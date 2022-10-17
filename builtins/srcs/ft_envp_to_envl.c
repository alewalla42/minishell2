/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp_to_envl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:13:39 by alewalla          #+#    #+#             */
/*   Updated: 2022/06/20 13:44:34 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

void	ft_add_to_envl(t_env *envl, char *name, char *value)
{
	t_env	*tmp;
	t_env	*new;

	tmp = envl;
	while (tmp->next_link != NULL)
		tmp = tmp->next_link;
	new = (t_env *)malloc(sizeof(t_env));
	if (new == NULL)
		return ;
	new->name = name;
	new->value = value;
	new->next_link = NULL;
	tmp->next_link = new;
}

void	ft_set_base_env(t_env *envl)
{
	envl->name = NULL;
	envl->value = NULL;
	envl->next_link = NULL;
	ft_add_to_envl(envl, ft_get_name("PWD=", '='), ft_getcwd());
 	ft_add_to_envl(envl, ft_get_name("SHLVL=", '='), ft_get_value("=1"));
	ft_add_to_envl(envl, ft_get_name("_=", '='), ft_get_value("=usr/bin/env"));
}

void	ft_envp_to_envl(char **envp, t_env *envl)
{
	int	i;

	i = -1;
	if (envp[0] == NULL)
	{
		ft_set_base_env(envl);
		return ;
	}
	envl->name = NULL;
	envl->value = NULL;
	envl->next_link = NULL;
	while (envp[++i])
		ft_add_to_envl(envl, ft_get_name(envp[i], '='), ft_get_value(envp[i]));
	return ;
}

void	ft_remove_from_envl(t_env *envl, char *name)
{
	t_env	*tmp;
	t_env	*buff;

	tmp = envl->next_link;
	buff = envl;
	while (tmp->next_link != NULL && (ft_strcmp(tmp->name, name) != 0))
	{
		buff = tmp;
		tmp = tmp->next_link;
	}
	if (ft_strncmp(tmp->name, name, ft_strlen(name)) != 0)
		return ;
	buff->next_link = tmp->next_link;
	free(tmp->name);
	free(tmp->value);
	free(tmp);
}

void	ft_free_envl(t_env *envl)
{
	t_env	*tmp;

	tmp = envl;
	while (tmp->next_link != NULL)
	{
		tmp = tmp->next_link;
		free(envl->name);
		free(envl->value);
		free(envl);
		envl = tmp;
	}
	free(envl->name);
	free(envl->value);
	free(envl);
	return ;
}

//int     main(int ac, char **av, char **envp)
//{
//    (void)ac;
//    (void)av;
//    int     i;
//    t_env   *envl;
//
//    envl = (t_env *)malloc(sizeof(t_env));
//    ft_envp_to_envl(envp, envl);
//    ft_remove_from_envl(envl, "USER");
//    ft_add_to_envl(envl, ft_get_name("WOOF=chat"), ft_get_value("WOOF=chat"));
//    ft_add_to_envl(envl, ft_get_name("ZOOM=chat"), ft_get_value("ZOOM=chat"));
//    ft_print_envl(envl);
//    ft_free_envl(envl);
//    return(0);
//}