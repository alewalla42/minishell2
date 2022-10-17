/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenl_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:12:34 by alewalla          #+#    #+#             */
/*   Updated: 2022/08/21 14:18:30 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_tokenl(t_tok *token)
{
	while (token->next_link != NULL)
	{
		free(token->data);
		token = token->next_link;
		free(token->previous_link);
	}
	free(token->data);
	free(token);
}