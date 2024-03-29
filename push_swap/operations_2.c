/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:08:55 by csilva-f          #+#    #+#             */
/*   Updated: 2023/01/26 23:57:11 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	apply_rr(t_stack **s_a, t_stack **s_b)
{
	apply_ra(s_a, 0);
	apply_rb(s_b, 0);
	write(1, "rr\n", 3);
}

void	apply_rra(t_stack **s_a, int is_rra)
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
	if (is_rra == 1)
		write(1, "rra\n", 4);
}

void	apply_rrb(t_stack **s_b, int is_rrb)
{
	t_stack	*temp_pen;
	t_stack	*temp_tail;
	t_stack	*temp;

	if (count_stack_nbrs(*s_b) > 1)
	{
		temp_pen = get_penult_node(*s_b);
		temp_tail = get_last_node(*s_b);
		temp = *s_b;
		*s_b = temp_tail;
		(*s_b)->next = temp;
		temp_pen->next = NULL;
	}
	if (is_rrb == 1)
		write(1, "rrb\n", 4);
}

void	apply_rrr(t_stack **s_a, t_stack **s_b)
{
	apply_rra(s_a, 0);
	apply_rrb(s_b, 0);
	write(1, "rrr\n", 4);
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
	write(1, "pa\n", 3);
}
