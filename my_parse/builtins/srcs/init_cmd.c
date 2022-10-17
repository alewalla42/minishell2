/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:30:36 by thbierne          #+#    #+#             */
/*   Updated: 2022/04/08 12:24:29 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*init_cmd(void)
{
	t_list	*tab_list;
	t_cmd		*tab_cmd;

	tab_list = malloc(sizeof(*tab_list));
	tab_cmd = malloc(sizeof(*tab_cmd));
	if (tab_list == NULL || tab_cmd == NULL)
		exit(EXIT_FAILURE);
	tab_cmd->nbr = 0;
	tab_cmd->next_cmd = NULL;
	tab_cmd->next_arg = NULL;
	tab_list->first = tab_cmd;
	return (tab_list);
}

t_cmd	*add_nbr_cmd(t_list *tab_list, int new_nbr)
{
	t_cmd		*new;

	new = malloc(sizeof(*new));
	if (tab_list == NULL || new == NULL)
		exit(EXIT_FAILURE);
	new->nbr = new_nbr;
	new->next_arg = NULL;
	new->next_cmd = NULL;
	return (new);
}

void	delete_nbr_cmd(t_list *tab_list)
{
	t_cmd	*nbr_delete;

	if (tab_list == NULL)
		exit(EXIT_FAILURE);
	if (tab_list->first)
	{
		nbr_delete = tab_list->first;
		tab_list->first = tab_list->first->next_cmd;
		free(nbr_delete);
	}
}

void	print_cmd(t_list *tab_list)
{
	t_cmd	*now;

	if (tab_list == NULL)
		exit(EXIT_FAILURE);
	now = tab_list->first;
	while (now != NULL)
	{
		printf("%d -> ", now->nbr);
		now = now->next_cmd;
	}
	printf("NULL\n");
}