/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:30:45 by alewalla          #+#    #+#             */
/*   Updated: 2022/05/31 11:04:42 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_change_dir(char *name, t_env *envl)
{
	if (ft_strcmp(name, "-") == 0)
		name = ft_get_value_from_envl(envl, "OLDPWD");
	if (access(name, F_OK) == 0)
	{
		if (access(name, X_OK) == 0)
		{
			if (ft_is_in_envl(envl, "OLDPWD"))
				ft_change_value(envl, "OLDPWD", ft_getcwd());
			chdir(name);
			if (ft_is_in_envl(envl, "PWD"))
				ft_change_value(envl, "PWD", ft_getcwd());
		}
		else
		{
			printf("cd: permission denied: %s\n", name);
			return (1);
		}
		return (0);
	}
	printf("cd: no such file or directory: %s\n", name);
	return (1);
}

int	ft_cd(int ac, char **av, t_env *envl)
{
	if (ac > 2)
	{
		printf("cd: too many arguments\n");
		//ret_value = 1;
		return (1);
	}
	if (av[1] == NULL)
		av[1] = ft_get_value_from_envl(envl, "HOME");
	if (av[1] == NULL)
	{
		printf("HOME not set\n");
		return (1);
	}
	return (ft_change_dir(av[1], envl));
}