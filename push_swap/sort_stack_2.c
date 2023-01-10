/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 23:28:35 by csilva-f          #+#    #+#             */
/*   Updated: 2023/01/10 23:43:02 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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

		}
	}
}
