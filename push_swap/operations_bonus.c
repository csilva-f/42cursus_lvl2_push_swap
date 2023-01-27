/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:34:39 by csilva-f          #+#    #+#             */
/*   Updated: 2023/01/26 23:55:33 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap_bonus.h"

void	apply_sa(t_stack **s_a)
{
	int	aux;
	
	if (count_stack_nbrs(*s_a) > 1)
	{
		aux = (*s_a)->value;
		(*s_a)->value = (*s_a)->next->value;
		(*s_a)->next->value = aux;
		aux = (*s_a)->index;
		(*s_a)->index = (*s_a)->next->index;
		(*s_a)->next->index = aux;
	}
}

void	apply_sb(t_stack **s_b)
{
	int	aux;

	if (count_stack_nbrs(*s_b))
	{
		aux = (*s_b)->value;
		(*s_b)->value = (*s_b)->next->value;
		(*s_b)->next->value = aux;
		aux = (*s_b)->index;
		(*s_b)->index = (*s_b)->next->index;
		(*s_b)->next->index = aux;
	}
}

void	apply_ss(t_stack **s_a, t_stack **s_b)
{
	apply_sa(s_a);
	apply_sb(s_b);
}

void	apply_ra(t_stack **s_a)
{
	t_stack	*temp_head;
	t_stack	*temp_tail;

	if (count_stack_nbrs(*s_a) > 1)
	{
		temp_head = *s_a;
		*s_a = (*s_a)->next;
		temp_tail = get_last_node(*s_a);
		temp_head->next = NULL;
		temp_tail->next = temp_head;
	}
}

void	apply_rb(t_stack **s_b)
{
	t_stack	*temp_head;
	t_stack	*temp_tail;

	if (count_stack_nbrs(*s_b) > 1)
	{
		temp_head = *s_b;
		*s_b = (*s_b)->next;
		temp_tail = get_last_node(*s_b);
		temp_head->next = NULL;
		temp_tail->next = temp_head;
	}
}
