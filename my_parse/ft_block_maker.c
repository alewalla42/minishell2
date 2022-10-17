/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_block_maker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:57:19 by alewalla          #+#    #+#             */
/*   Updated: 2022/08/21 13:51:33 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_create_empty_block(t_tok *token)
{
	t_tok	*new;

	new = malloc(sizeof(t_tok));
	new->data = NULL;
	new->type = -1;
	new->status = OUT;
	new->previous_link = token;
	new->next_link = NULL;
	token->next_link = new;
}

void	ft_create_type_block(t_tok *token, int type)
{
	t_tok	*new;

	if (token->type == -1)
		new = token;
	else
	{
		new = malloc(sizeof(t_tok));
		token->next_link = new;
	}
	if (token->type != -1)
		new->previous_link = token;
	new->data = NULL;
	new->type = type;
	new->status = OUT;
	new->next_link = NULL;
	ft_create_empty_block(new);
}

void	ft_create_word_block(t_tok *token, char data)
{
	t_tok	*new;

	new = malloc(sizeof(t_tok));
	new->data = ft_addchar(new->data, data);
	new->type = WORD;
	new->status = OUT;
	new->previous_link = token;
	new->next_link = NULL;
	token->next_link = new;
}

void	ft_create_quote_block(int status, t_tok *token)
{
	t_tok	*new;

	new = malloc(sizeof(t_tok));
	new->data = NULL;
	new->type = WORD;
	new->status = status;
	new->previous_link = token;
	new->next_link = NULL;
	token->next_link = new;
}