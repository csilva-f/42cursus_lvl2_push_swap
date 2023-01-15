/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:41:13 by csilva-f          #+#    #+#             */
/*   Updated: 2023/01/15 19:41:51 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap_bonus.h"

t_stack	*get_penult_node(t_stack *list)
{
	while (list && list->next && list->next->next != NULL)
		list = list->next;
	return (list);
}

void	free_s(t_stack **list)
{
	t_stack	*aux;

	if (!list || !(*list))
		return ;
	while (*list)
	{
		aux = (*list)->next;
		free(*list);
		*list = aux;
	}
	list = NULL;
}
