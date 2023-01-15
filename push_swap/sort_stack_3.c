/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:40:02 by csilva-f          #+#    #+#             */
/*   Updated: 2023/01/15 14:54:21 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <limits.h>

void	find_cost_to_move(t_stack **s_b, int size_a)
{
	t_stack	*temp;

	temp = *s_b;
	while (temp)
	{
		if (temp->posit > count_stack_nbrs(*s_b) / 2)
			temp->cost_b = (temp->posit - count_stack_nbrs(*s_b));
		else
			temp->cost_b = temp->posit;
		if (temp->t_posit > size_a / 2)
			temp->cost_a = (temp->t_posit - size_a);
		else
			temp->cost_a = temp->t_posit;
		temp = temp->next;
	}
}

void	apply_rotate(t_stack **stack, int *cost, int is_sa)
{
	while (*cost != 0)
	{
		if (*cost < 0)
		{
			if (is_sa == 1)
				apply_rra(stack, 1);
			else
				apply_rrb(stack, 1);
			(*cost)++;
		}
		else
		{
			if (is_sa == 1)
				apply_ra(stack, 1);
			else
				apply_rb(stack, 1);
			(*cost)--;
		}
	}
}

void	apply_sim_rotate(t_stack **s_a, t_stack **s_b, int *ca, int *cb)
{
	if (*ca < 0 && *cb < 0)
	{
		apply_rrr(s_a, s_b);
		(*ca)++;
		(*cb)++;
	}
	else
	{
		apply_rr(s_a, s_b);
		(*ca)--;
		(*cb)--;
	}
}

void	execute_positioning(t_stack **s_a, t_stack **s_b)
{
	t_stack	*temp;
	int		l_cost;
	int		ca;
	int		cb;

	temp = *s_b;
	l_cost = INT_MAX;
	while (temp)
	{
		if (abs(temp->cost_a) + abs(temp->cost_b) < l_cost)
		{
			l_cost = abs(temp->cost_a) + abs(temp->cost_b);
			ca = temp->cost_a;
			cb = temp->cost_b;
		}
		temp = temp->next;
	}
	if ((ca < 0 && cb < 0) || (ca > 0 && cb > 0))
		apply_sim_rotate(s_a, s_b, &ca, &cb);
	apply_rotate(s_a, &ca, 1);
	apply_rotate(s_b, &cb, 0);
	apply_pa(s_b, s_a);
}

void	reorder(t_stack **s_a, int size_a, int l_ind)
{
	int		l_pos;
	t_stack	*temp;

	positions(s_a);
	temp = *s_a;
	l_pos = temp->posit;
	while (temp)
	{
		if (temp->index < l_ind)
		{
			l_ind = temp->index;
			l_pos = temp->posit;
		}
		temp = temp->next;
	}
	if (l_pos > size_a / 2)
	{
		while ((size_a - l_pos++) > 0)
			apply_rra(s_a, 1);
	}
	else
	{
		while (l_pos-- > 0)
			apply_ra(s_a, 1);
	}
}
