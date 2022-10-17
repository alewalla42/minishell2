/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:10:38 by alewalla          #+#    #+#             */
/*   Updated: 2022/09/13 14:38:12 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_heredoc(char *str)
{
	char	*line_read;
	int		fd;
	int		i;

	i = 0;
	fd = open("/tmp/heredoc", O_RDWR | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		line_read = readline("heredoc> ");
		if (line_read == NULL)
		{
			write(1, "exit\n", 5);
			return (fd);
		}
		if (ft_strcmp(line_read, str) == 0)
		{
			free(line_read);
			return (fd);
		}
		ft_putstr_fd(line_read, fd);
		ft_putchar_fd('\n', fd);
		free(line_read);
	}
}
