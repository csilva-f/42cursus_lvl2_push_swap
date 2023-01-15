/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:00:06 by csilva-f          #+#    #+#             */
/*   Updated: 2023/01/08 18:17:16 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

void	assign_indexes(t_stack *s_a, int size)
{
	int		low_nbr;
	t_stack	*temp;
	t_stack	*lowest;

	while (--size > 0)
	{
		lowest = NULL;
		temp = s_a;
		low_nbr = INT_MAX;
		while (temp)
		{
			if (temp->value < low_nbr && temp->index == 0)
			{
				low_nbr = temp->value;
				lowest = temp;
				temp = temp->next;
			}
			else if (temp->value == INT_MAX)
				temp->index = count_stack_nbrs(s_a);
			else
				temp = temp->next;
		}
		if (lowest)
			lowest->index = count_stack_nbrs(s_a) - size + 1;
	}
}
