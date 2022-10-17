/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:38:09 by alewalla          #+#    #+#             */
/*   Updated: 2022/09/11 14:40:08 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	j = -1;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen((char *)src);
	if (size == 0)
		return (src_len);
	if (size <= dst_len)
		return (src_len + size);
	i = dst_len;
	while (src[++j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}