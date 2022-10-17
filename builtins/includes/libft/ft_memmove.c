/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:14:08 by alewalla          #+#    #+#             */
/*   Updated: 2022/09/11 16:29:23 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*src_copy;
	unsigned char	*dst_copy;
	unsigned int	i;

	src_copy = (unsigned char *)src;
	dst_copy = (unsigned char *)dest;
	if (dest == NULL && src == NULL && n > 0)
		return (dest);
	i = 0;
	if (src_copy > dst_copy)
	{
		while (i < n)
		{
			dst_copy[i] = src_copy[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			dst_copy[n] = src_copy[n];
	}
	return (dest);
}
