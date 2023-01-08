/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:15:15 by csilva-f          #+#    #+#             */
/*   Updated: 2023/01/08 19:08:40 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	apply_sa(t_stack *s_a, int is_ss)
{
	int	aux;
	int	ind;

	aux = s_a->value;
	s_a->value = s_a->next->value;
	s_a->next->value = aux;
	ind = s_a->index;
	s_a->index = s_a->next->index;
	s_a->next->index = ind;
	if (is_ss == 0)
		write(1, "sa\n", 3);
}

void	apply_sb(t_stack *s_b, int is_ss)
{
	int	aux;
	int	ind;

	aux = s_b->value;
	s_b->value = s_b->next->value;
	s_b->next->value = aux;
	ind = s_b->index;
	s_b->index = s_b->next->index;
	s_b->next->index = ind;
	if (is_ss == 0)
		write(1, "sb\n", 3);
}

void	apply_ss(t_stack *s_a, t_stack *s_b)
{
	apply_sa(s_a, 1);
	apply_sb(s_b, 1);
	write(1, "ss\n", 3);
}

void	apply_ra(t_stack *s_a, int is_rr)
{
	t_stack	*temp_head;
	t_stack	*temp_tail;

	temp_head = s_a;
	temp_tail = get_last_node(s_a);
	temp_head->next = NULL;
	temp_tail->next = temp_head;
	if (is_rr == 0)
		write(1, "ra\n", 3);
}

void	apply_rb(t_stack *s_b, int is_rr)
{
	t_stack	*temp_head;
	t_stack	*temp_tail;

	temp_head = s_b;
	temp_tail = get_last_node(s_b);
	temp_head->next = NULL;
	temp_tail->next = temp_head;
	if (is_rr == 0)
		write(1, "rb\n", 3);
}
