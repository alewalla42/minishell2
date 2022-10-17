/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:19:46 by alewalla          #+#    #+#             */
/*   Updated: 2022/07/12 00:38:37 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_alloc_path_tab(t_core *core)
{
	int		i;
	char *str;
	t_env *tmp;

	i = -1;
	tmp = core->envl;
	str = ft_get_value_from_envl(tmp, "PATH");
	core->path->path_env = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	core->path->path_env = str;
	core->path->path_tab = ft_split(core->path->path_env, ':');
	while (core->path->path_tab[++i] != NULL)
		core->path->path_tab[i] = ft_strjoin(core->path->path_tab[i], "/");
}