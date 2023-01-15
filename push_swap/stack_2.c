/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:13:32 by csilva-f          #+#    #+#             */
/*   Updated: 2023/01/15 17:29:14 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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
