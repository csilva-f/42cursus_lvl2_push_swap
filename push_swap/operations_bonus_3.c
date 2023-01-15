/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:43:27 by csilva-f          #+#    #+#             */
/*   Updated: 2023/01/15 19:44:04 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap_bonus.h"

void	apply_pb(t_stack **s_a, t_stack **s_b)
{
	t_stack	*temp;

	if (*s_a == NULL)
		return ;
	temp = (*s_a)->next;
	(*s_a)->next = *s_b;
	*s_b = *s_a;
	*s_a = temp;
}
