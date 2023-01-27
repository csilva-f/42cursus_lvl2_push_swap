/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:37:57 by csilva-f          #+#    #+#             */
/*   Updated: 2023/01/26 23:53:34 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap_bonus.h"

void	apply_rr(t_stack **s_a, t_stack **s_b)
{
	apply_ra(s_a);
	apply_rb(s_b);
}

void	apply_rra(t_stack **s_a)
{
	t_stack	*temp_pen;
	t_stack	*temp_tail;
	t_stack	*temp;
	
	if (count_stack_nbrs(*s_a) > 1)
	{
		temp_pen = get_penult_node(*s_a);
		temp_tail = get_last_node(*s_a);
		temp = *s_a;
		*s_a = temp_tail;
		(*s_a)->next = temp;
		temp_pen->next = NULL;
	}
}

void	apply_rrb(t_stack **s_b)
{
	t_stack	*temp_pen;
	t_stack	*temp_tail;
	t_stack	*temp;

	if (count_stack_nbrs(*s_b))
	{
		temp_pen = get_penult_node(*s_b);
		temp_tail = get_last_node(*s_b);
		temp = *s_b;
		*s_b = temp_tail;
		(*s_b)->next = temp;
		temp_pen->next = NULL;
	}
}

void	apply_rrr(t_stack **s_a, t_stack **s_b)
{
	apply_rra(s_a);
	apply_rrb(s_b);
}

void	apply_pa(t_stack **s_b, t_stack **s_a)
{
	t_stack	*temp;

	if (!(*s_b))
		return ;
	temp = (*s_b)->next;
	(*s_b)->next = *s_a;
	*s_a = *s_b;
	*s_b = temp;
}
