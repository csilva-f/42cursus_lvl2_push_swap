/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 23:56:23 by csilva-f          #+#    #+#             */
/*   Updated: 2023/01/10 23:56:40 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	apply_pb(t_stack *s_a, t_stack *s_b)
{
	t_stack	*temp;

	if (!s_b)
		return ;
	temp = s_b->next;
	s_b->next = s_a;
	s_a = s_b;
	s_b = temp;
	write(1, "pb\n", 3);
}
