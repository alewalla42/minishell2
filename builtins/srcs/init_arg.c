/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:01:59 by thbierne          #+#    #+#             */
/*   Updated: 2022/04/08 12:48:28 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_arg	*init_arg(void)
{
	t_arg		*tab_arg;

	tab_arg = malloc(sizeof(*tab_arg));
	if (tab_arg == NULL)
		exit(EXIT_FAILURE);
	tab_arg->nbr_arg = 1;
	tab_arg->next = NULL;
	return (tab_arg);
}

t_arg	*add_nbr_arg(t_cmd *tab_list, int new_nbr)
{
	t_arg	*new;

	new = malloc(sizeof(*new));
	if (tab_list == NULL || new == NULL)
		exit(EXIT_FAILURE);
	new->nbr_arg = new_nbr;
	new->next = NULL;
	return (new);
}

void	delete_nbr_arg(t_cmd *tab_list)
{
	t_arg	*nbr_delete;

	if (tab_list == NULL)
		exit(EXIT_FAILURE);
	if (tab_list->next_arg)
	{
		nbr_delete = tab_list->next_arg;
		tab_list->next_arg = tab_list->next_arg->next;
		free(nbr_delete);
	}
}

void	print_arg(t_cmd *tab_list)
{
	t_arg	*now;

	if (tab_list == NULL)
		exit(EXIT_FAILURE);
	now = tab_list->next_arg;
	while (now != NULL)
	{
		printf("%d: %s-> ", now->nbr_arg, now->argument);
		now = now->next;
	}
	printf("NULL\n");
}
