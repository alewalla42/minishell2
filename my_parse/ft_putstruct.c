/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstruct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 20:11:06 by alewalla          #+#    #+#             */
/*   Updated: 2022/08/21 14:31:55 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putstruct(t_tok *token)
{
	t_tok	*tmp;

	tmp = token;
	while (tmp->next_link != NULL)
	{
		printf("data = %s\n", tmp->data);
		printf("type = %d\n", tmp->type);
		printf("status = %d\n\n", tmp->status);
		tmp = tmp->next_link;
	}
	printf("data = %s\n", tmp->data);
	printf("type = %d\n", tmp->type);
	printf("status = %d\n", tmp->status);
}