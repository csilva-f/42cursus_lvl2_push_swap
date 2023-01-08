/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:58:44 by csilva-f          #+#    #+#             */
/*   Updated: 2023/01/08 18:59:14 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <unistd.h>

int	is_sorted(t_stack *s_a)
{
	t_stack	*temp;

	temp = s_a;
	while (temp)
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

void	sort_3(t_stack *s_a)
{
	if (s_a->index == get_bigger_index(s_a))
		apply_ra(s_a, 0);
	else if (s_a->next->index == get_bigger_index(s_a))
		apply_rra(s_a, 0);
	if (s_a->index > s_a->next->index)
		apply_sa(s_a, 0);
}

void	push_swap(t_stack *s_a)
{
	int	size;

	size = count_stack_nbrs(s_a);
	if (size == 2 && !is_sorted(s_a))
		apply_sa(s_a, 0);
	else if (size == 3 && !is_sorted(s_a))
		sort_3(s_a);
	else if (size > 3 && !is_sorted(s_a))
		sort_more_than_3(s_a);
}
