/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:32:44 by alewalla          #+#    #+#             */
/*   Updated: 2022/05/07 13:32:25 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[++i])
		printf("%s\n", envp[i]);
}

/*
int main(int ac, char **av, char **envp)
{
    (void)ac;
    (void)av;

    ft_env(envp);
}
*/