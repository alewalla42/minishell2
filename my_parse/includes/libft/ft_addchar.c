/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:18:25 by alewalla          #+#    #+#             */
/*   Updated: 2022/08/16 17:06:16 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_addchar(char *str, char c)
{
	int		i;
	char	*new;

	i = 0;
	new = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (str != NULL)
		while (str[i])
		{
			new[i] = str[i];
			i++;
		}
	new[i] = c;
	new[i + 1] = '\0';
	return (new);
}