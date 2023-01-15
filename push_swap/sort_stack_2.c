/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 23:28:35 by csilva-f          #+#    #+#             */
/*   Updated: 2023/01/14 22:44:14 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

void	reduce_sa_to_3(t_stack **s_a, t_stack **s_b)
{
	int		i;
	int		pushed;
	int		n_nbrs;

	i = 0;
	pushed = 0;
	n_nbrs = count_stack_nbrs(*s_a);
	while (n_nbrs > 6 && i < n_nbrs && pushed < n_nbrs / 2)
	{
		if ((*s_a)->index <= n_nbrs / 2)
		{
			apply_pb(s_a, s_b);
			pushed++;
		}
		else
			apply_ra(s_a, 1);
		i++;
	}
	while (n_nbrs - pushed > 3)
	{
		apply_pb(s_a, s_b);
		pushed++;
	}
}

void	positions(t_stack **list)
{
	t_stack	*temp;
	int		i;

	temp = *list;
	i = 0;
	while (temp)
	{
		temp->posit = i;
		temp = temp->next;
		i++;
	}
}

int	find_pos2(int t_ind, int t_pos, int *sa_ind)
{
	int	sa_pos;

	sa_pos = -1;
	*sa_ind = t_ind;
	sa_pos = t_pos;
	return (sa_pos);
}

int	find_pos_sa(t_stack **s_a, int index_b)
{
	t_stack	*temp;
	int		sa_ind;
	int		sa_pos;

	temp = *s_a;
	sa_ind = INT_MAX;
	sa_pos = -1;
	while (temp)
	{
		if (temp->index > index_b && temp->index < sa_ind)
			sa_pos = find_pos2(temp->index, temp->posit, &sa_ind);
		temp = temp->next;
	}
	if (sa_ind == INT_MAX)
	{
		temp = *s_a;
		while (temp)
		{
			if (temp->index < sa_ind)
				sa_pos = find_pos2(temp->index, temp->posit, &sa_ind);
			temp = temp->next;
		}
	}
	return (sa_pos);
}

void	fill_right_pos_sa(t_stack **s_a, t_stack **s_b)
{
	t_stack	*temp;

	positions(s_a);
	positions(s_b);
	temp = *s_b;
	while (temp)
	{
		temp->t_posit = find_pos_sa(s_a, temp->index);
		temp = temp->next;
	}
}
