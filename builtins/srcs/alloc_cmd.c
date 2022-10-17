/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:14:01 by thbierne          #+#    #+#             */
/*   Updated: 2022/05/07 12:49:38 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*alloc_line_char_read1(char *line_read, int *i, char c)
{
	char	*str;
	int		z;
	int		y;

	*i = *i + 1;
	y = *i;
	while (line_read[y] && line_read[y] != c)
		y++;
	if (y == *i)
		return (NULL);
	else
	{
		str = malloc ((sizeof(char*)) * (y - *i + 1));
		if (str == NULL)
			return (NULL);
		z = 0;
		while (*i < y)
		{
			str[z] = line_read[*i];
			*i = *i + 1;
			z++;
		}
		str[z] = '\0';
		return (str);
	}
}

char	*alloc_line_char_read2(char *line_read, int *i)
{
	char	*str;
	int		y;
	int		z;

	y = *i;
	while (line_read[*i] != ' ' && line_read[*i] != '\0' && line_read[*i] != 34 && line_read[*i] != 39)
		*i = *i + 1;
	str = malloc(sizeof(char*) * (*i - y + 1));
	if (str == NULL)
		return (NULL);
	z = 0;
	while (y < *i)
	{
		str[z] = line_read[y];
		y++;
		z++;
	}
	str[z] = '\0';
	return (str);
}

char	**alloc_line_read(char **tab_line, char *line_read)
{
	int i;
	int	nbr_tab;

	i = 0;
	nbr_tab = 1;
	while (line_read[i])
	{
		while (line_read[i] == ' ')
			i++;
		if (line_read[i] == 34 || line_read[i] == 39)
		{
			tab_line[nbr_tab] = alloc_line_char_read1(line_read, &i, line_read[i]);
			nbr_tab++;
			i++;
		}
		else if (line_read[i])
		{
			tab_line[nbr_tab] = alloc_line_char_read2(line_read, &i);
			nbr_tab++;
		}
		//printf("line_read: %d\n", i);
	}
	//printf("nbr_tab: %d\n", nbr_tab);
	tab_line[nbr_tab] = NULL;
	return (tab_line);
}

int	count_line_char_read(char *line_read, int *i, int count, char c)
{
	*i = *i + 1;
	while (line_read[*i] != c)
	{
		if (line_read[*i] != c && line_read[*i + 1])
			return (-1);
		*i = *i + 1;
	}
	count++;
	*i = *i + 1;
	return (count);
}

int	count_line_read(char *line_read)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line_read[i])
	{
		if (line_read[i] == 34)
			count = count_line_char_read(line_read, &i, count, 34);
		else if (line_read[i] == 39)
			count = count_line_char_read(line_read, &i, count, 39);
		else if (line_read[i] != ' ')
		{
			while (line_read[i] != ' ' && line_read[i] && line_read[i] != 34 && line_read[i] != 39)
				i++;
			count++;
		}
		else
			i++;
		if (count == -1)
			break ;
	}
	return (count);
}

char	**alloc_cmd(char *line_read)
{
	char	**tab_line;
	int	i;

	i = count_line_read(line_read);
	tab_line = malloc(sizeof(char*) * (i + 2));
	tab_line[0] = ft_itoa(i);
	tab_line = alloc_line_read(tab_line, line_read);
	free(line_read);

	return (tab_line);
}
