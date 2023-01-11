/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 23:28:35 by csilva-f          #+#    #+#             */
/*   Updated: 2023/01/11 23:02:29 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <limits.h>

void	reduce_sa_to_3(t_stack *s_a, t_stack *s_b)
{
	int	i;
	int	pushed;
	int	n_nbrs;

	i = 0;
	pushed = 0;
	n_nbrs = count_stack_nbrs(s_a);
	while (n_nbrs > 6 && i < n_nbrs && pushed < n_nbrs / 2)
	{
		if (s_a->index <= n_nbrs / 2)
		{
			apply_pb(s_a, s_b);
			pushed++;
		}
		else
			apply_ra(s_a, 1);
		i++;
	}
}

void	positions(t_stack *list)
{
	t_stack	*temp;
	int		i;

	temp = list;
	i = 0;
	while (temp)
	{
		temp->posit = i;
		temp = temp->next;
		i++;
	}
}

void	find_pos_sa(t_stack *s_a, int index_b)
{
	t_stack	*temp;

	temp = s_a;
	while (temp)
	{
		if (temp->index > index_b && temp->index < )
	}
}

void	fill_right_pos_sa(t_stack *s_a, t_stack *s_b)
{
	t_stack	*temp;
	int		pos_max;

	positions(s_a);
	positions(s_b);
	temp = s_b;
	pos_max = INT_MAX;
	while (temp)
	{
		temp->t_posit = find_pos_sa(s_a, temp->index);

	}
}
