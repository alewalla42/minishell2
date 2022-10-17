/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:49:16 by alewalla          #+#    #+#             */
/*   Updated: 2022/05/31 11:39:59 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export_plus(t_env *envl, char *arg)
{
	char	*name;
	char	*value;

	name = ft_get_name(arg, '+');
	value = ft_get_value(arg);
	if (ft_strcmp(name, "_") == 0)
		return ;
	if (ft_is_in_envl(envl, name))
		ft_join_value(envl, name, value);
	else
		ft_add_to_envl(envl, name, value);
}

void	ft_export_equal(t_env *envl, char *arg)
{
	char	*name;
	char	*value;

	name = ft_get_name(arg, '=');
	value = ft_get_value(arg);
	if (ft_strcmp(name, "_") == 0)
		return ;
	if (ft_is_in_envl(envl, name))
		ft_change_value(envl, name, value);
	else
		ft_add_to_envl(envl, name, value);
}

int	ft_export(int ac, char **av, t_env *envl)
{
	int		i;
	int		ret;

	i = -1;
	ret = 0;
	if (ac == 1)
	{
		printf("man export\n");
		return (1);
	}
	while (av[++i] != NULL)
	{
		if (!ft_isalpha(av[i][0]) && av[i][0] != '_')
		{
			printf("`%s': not a valid  identifier\n", av[i]);
			ret = 1;
		}
		if ((ft_findstr(av[i], "+=") + 1) == ft_findstr(av[i], "="))
			ft_export_plus(envl, av[i]);
		else if (ft_findstr(av[i], "=") != -1)
		{
			if ((ft_findstr(av[i], "-=") + 1) != ft_findstr(av[i], "="))
				ft_export_equal(envl, av[i]);
			else
			{
				printf("`%s': not a valid  identifier\n", av[i]);
				ret = 1;
			}
		}
	}
	return (ret);
}
