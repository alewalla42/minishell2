/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_dollar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:54:59 by thbierne          #+#    #+#             */
/*   Updated: 2022/06/19 11:08:03 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_line_read1(char *line_read, t_env *tmp, int i)
{
	char	*cpy;
	int		y;
	int		nbr_n;

	y = 0;
	while (line_read[y])
		y++;
	if (tmp)
		cpy = malloc(sizeof(char) * ((y - ft_strlen(tmp->name) - 1) + ft_strlen(tmp->value) + 1));
	else
	{
		y = i;
		while (line_read[y] && line_read[y] != ' ' && line_read[y] != '<' 
				&& line_read[y] != '>' && line_read[y] != '|' && line_read[y] != 34 && line_read[y] != 39)
			y++;
		nbr_n = y - i;
		while (line_read[y])
			y++;
		cpy = malloc(sizeof(char) * (y - nbr_n + 1));
	}
	return (cpy);
}

char	*join_line_read2(t_env *tmp, char *cpy, int *i, int *y)
{
	int		nbr_n;

	nbr_n = 0;
	while (tmp->value[nbr_n])
	{
		cpy[*y] = tmp->value[nbr_n];
		*y += 1;
		nbr_n++;
	}
	*i = *i + ft_strlen(tmp->name) + 1;
	return (cpy);
}

char	*join_line_read(char *line_read, t_env *tmp, int i)
{
	char	*cpy;
	int		y;

	cpy = join_line_read1(line_read, tmp, i);
	y = -1;
	while (++y < i)
		cpy[y] = line_read[y];
	if (tmp)
		cpy = join_line_read2(tmp, cpy, &i, &y);
	else
	{
		while (line_read[i] && line_read[i] != ' ' && line_read[i] != '<' 
			&& line_read[i] != '>' && line_read[i] != '|' && line_read[i] != 34 && line_read[i] != 39)
			i++;
	}
	while (line_read[i])
	{
		cpy[y] = line_read[i];
		y++;
		i++;
	}
	cpy[y] = '\0';
	free(line_read);
	return (cpy);
}

t_env	*check_dollar_t_env(char *line_read, t_env *envl)
{
	int		i;
	t_env	*tmp;

	tmp = envl->next_link;
	while (tmp)
	{
		i = 0;
		while (line_read[i] == tmp->name[i] && line_read[i] && tmp->name[i])
			i++;
		if (tmp->name[i] == '\0')
			if ((!ft_isalphanum(line_read[i]) || line_read[i] == '_' ) || !line_read[i])
				return (tmp);
		tmp = tmp->next_link;
	}
	return (NULL);
}

/* fonction remplace le '$', si la variable env du '$' n'existe pas, supprime '$' et 'NAME' */

char	*ft_replace_dollar(char *line, t_env *envl, int mode)
{
	int		i;
	int		check;
	t_env	*tmp;
	char	c;

	i = -1;
	check = 0;
	while (line[++i])
	{
		if ((line[i] == '\'' || line[i] == '\"') && mode == 0)	//mode: si 0, remplace '$' sans rentrer dans les quotes, si 1 remplace dans les quotes
		{
			c = line[i++];
			while (line[i] != c)
				i++;
		}
		else if (line[i] == '$')
		{
			if (line[i + 1] == ' ' || line[i +1] == '\0')
				;
			tmp = check_dollar_t_env(&line[i + 1], envl);
			if (tmp == NULL)
				line = join_line_read(line, tmp, i);
			else
			{
				line = join_line_read(line, tmp, i);
				i = i + ft_strlen(tmp->value);
			}
			i--;
		}
	}
	return (line);
}