/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 12:49:59 by alewalla          #+#    #+#             */
/*   Updated: 2022/05/07 15:19:28 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_test_cmd(t_core *core, char *arg)
{
	char	*join;
	char	*actual_path;
	t_env	*tmp;
	int		i;
	int		z;

	i = -1;
	z = -1;
	tmp = core->envl;
	actual_path = ft_get_value_from_envl(tmp, "PATH");
	if ((ft_strcmp(actual_path, core->path->path_env) != 0) || (ft_strcmp(actual_path, "\0") == 0))
	{
		free(core->path->path_tab);
		ft_alloc_path_tab(core);
	}
	while (core->path->path_tab[++i])
	{
		join = ft_strjoin(core->path->path_tab[i], arg);
		z = access(join, 0);
		if (z == 0)
		{
			free(arg);
			return (join);
		}
		free(join);
	}
	return (arg);
}