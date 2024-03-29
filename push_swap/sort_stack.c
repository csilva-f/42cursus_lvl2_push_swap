/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:58:44 by csilva-f          #+#    #+#             */
/*   Updated: 2023/01/14 21:46:09 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <limits.h>

int	is_sorted(t_stack *s_a)
{
	t_stack	*temp;

	temp = s_a;
	while (temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	get_bigger_index(t_stack *s_a)
{
	int	ind;

	ind = s_a->index;
	while (s_a)
	{
		if (s_a->index > ind)
			ind = s_a->index;
		s_a = s_a->next;
	}
	return (ind);
}

void	sort_3(t_stack **s_a)
{
	if ((*s_a)->index == get_bigger_index(*s_a))
		apply_ra(s_a, 1);
	else if ((*s_a)->next->index == get_bigger_index(*s_a))
		apply_rra(s_a, 1);
	if ((*s_a)->index > (*s_a)->next->index)
		apply_sa(s_a, 1);
}

void	sort_more_than_3(t_stack **s_a, t_stack **s_b)
{
	reduce_sa_to_3(s_a, s_b);
	sort_3(s_a);
	while (count_stack_nbrs(*s_b) > 0)
	{
		fill_right_pos_sa(s_a, s_b);
		find_cost_to_move(s_b, count_stack_nbrs(*s_a));
		execute_positioning(s_a, s_b);
	}
	if (!is_sorted(*s_a))
		reorder(s_a, count_stack_nbrs(*s_a), INT_MAX);
}

void	push_swap(t_stack **s_a, t_stack **s_b)
{
	int	size;

	size = count_stack_nbrs(*s_a);
	if (size == 2 && !is_sorted(*s_a))
		apply_sa(s_a, 0);
	else if (size == 3 && !is_sorted(*s_a))
		sort_3(s_a);
	else if (size > 3 && !is_sorted(*s_a))
		sort_more_than_3(s_a, s_b);
}
