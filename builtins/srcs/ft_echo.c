/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:45:53 by alewalla          #+#    #+#             */
/*   Updated: 2022/05/31 10:55:48 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_check_flags(char **arg)
{
	int	i;
	int	j;

	i = -1;
	while (arg[++i] != NULL)
	{
		j = 0;
		if (arg[i][j] == '-')
		{
			while ((arg[i][++j] == 'n') && arg[i][j])
				;
			if (arg[i][j])
				return (i);
			if (arg[i][0] == '-' && ft_strlen(arg[i]) == 1)
				return (i);
		}
		else
			return (i);
	}
	return (i);
}

int	ft_echo(int ac, char **arg)
{
	int	j;
	int	i;
	int	flags;

	if (ac == 1)
		{
			write(1, "\n", 1);
			return (1);
		}
	flags = ft_check_flags(arg);
	i = flags -1;
	while (arg[++i] != NULL)
	{
		j = -1;
		while (arg[i][++j])
			write(1, &arg[i][j], 1);
		if (arg[i + 1])
			write(1, " ", 1);
	}
	if (flags == 0)
		write(1, "\n", 1);
	return (0);
}

/*
int main(int ac, char **av)
{
    if(ac >= 2)
    {
        ft_echo(&av[1]);
    }
    if(ac == 1)
        write(1, "\n", 1);
    return(0);
}
*/