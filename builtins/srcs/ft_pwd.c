/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:39:31 by alewalla          #+#    #+#             */
/*   Updated: 2022/05/31 11:05:22 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getcwd(void)
{
	long	i;
	char	*buff;

	i = 0;
	buff = NULL;
	buff = getcwd(buff, ++i);
	while (!buff && i <= 4096)
		buff = getcwd(buff, ++i);
	if (i > 4096)
		return (NULL);
	return (buff);
}

void	ft_pwd(void)
{
	char *buff;

	buff = ft_getcwd();
	if (buff != NULL)
		printf("%s\n", buff);
	else
		printf("pwd: error retrieving current directory: getcwd: cannot access parent directories: No such file or directory\n");
	return ;
}