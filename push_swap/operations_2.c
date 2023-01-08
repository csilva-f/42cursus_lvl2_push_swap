/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:08:55 by csilva-f          #+#    #+#             */
/*   Updated: 2023/01/08 19:22:50 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	apply_rr(t_stack *s_a, t_stack *s_b)
{
	apply_ra(s_a, 1);
	apply_rb(s_b, 1);
	write(1, "rr\n", 3);
}

void	apply_rra(t_stack *s_a, int is_rrr)
{
	t_stack	*temp_pen;
	t_stack	*temp_tail;

	temp_pen = get_penult_node(s_a);
	temp_tail = get_last_node(s_a);
	temp_tail->next = s_a;
	temp_pen->next = NULL;
	if (is_rrr == 0)
		write(1, "rra\n", 4);
}

void	apply_rrb(t_stack *s_b, int is_rrr)
{
	t_stack	*temp_pen;
	t_stack	*temp_tail;

	temp_pen = get_penult_node(s_b);
	temp_tail = get_last_node(s_b);
	temp_tail->next = s_b;
	temp_pen->next = NULL;
	if (is_rrr == 0)
		write(1, "rrb\n", 4);
}

void	apply_rrr(t_stack *s_a, t_stack *s_b)
{
	apply_rra(s_a, 1);
	apply_rrb(s_b, 1);
	write(1, "rrr\n", 4);
}
