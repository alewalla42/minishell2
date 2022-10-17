/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_first_block.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:32:25 by alewalla          #+#    #+#             */
/*   Updated: 2022/08/21 13:41:32 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_set_status(char c)
{
	if (c == '"')
		return (IN_DOUBLE);
	else if (c == '\'')
		return (IN_SINGLE);
	else
		return (OUT);
}

int		ft_set_type(char c)
{
	if (c == '|')
		return (PIPE);
	else if (c == '<')
		return (INFILE);
	else if (c == '>')
		return (OUTFILE);
	else
		return (WORD);
}

void	ft_setup_first_block(t_tok *token)
{
	token->status = OUT;
	token->type = -1;
	token->data = NULL;
	token->next_link = NULL;
	token->previous_link = NULL;
}