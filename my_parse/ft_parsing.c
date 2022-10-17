/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:20:08 by alewalla          #+#    #+#             */
/*   Updated: 2022/08/21 14:07:58 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_update_status(int status, t_tok *token)
{
	if (token->status == status)
		ft_create_empty_block(token);
	if (token->status == OUT)
	{
		if (token->data == NULL)
		{
			token->status = status;
			token->type = WORD;
		}
		else
			ft_create_quote_block(status, token);
	}
}

void	ft_parsing(char *cmd_line, t_tok *token)
{
	int	i;

	i = 0;
	ft_setup_first_block(token);
	while (ft_isspace(cmd_line[i]))
		i++;
	while (cmd_line[i])
	{
		if (ft_isspace(cmd_line[i]))
		{
			while (ft_isspace(cmd_line[i]))
				i++;
			i--;
			if (token->type != -1)
				ft_create_empty_block(token);
		}
		else if (cmd_line[i] == '"' && token->status != IN_SINGLE)
			ft_update_status(IN_DOUBLE, token);
		else if (cmd_line[i] == '\'' && token->status != IN_DOUBLE)
			ft_update_status(IN_SINGLE, token);
		else if (token->status == IN_DOUBLE || token->status == IN_SINGLE)
			token->data = ft_addchar(token->data, cmd_line[i]);
		else if (cmd_line[i] == '|')
			ft_create_type_block(token, PIPE);
		else if (cmd_line[i] == '<')
			ft_create_type_block(token, INFILE);
		else if (cmd_line[i] == '>')
			ft_create_type_block(token, OUTFILE);
		else if (token->type == WORD)
			token->data = ft_addchar(token->data, cmd_line[i]);
		else if (token->type == -1)
		{
			token->type = WORD;
			token->data = ft_addchar(token->data, cmd_line[i]);
		}
		else
			ft_create_word_block(token, cmd_line[i]);
		while (token->next_link != NULL)
			token = token->next_link;
		i++;
	}
}