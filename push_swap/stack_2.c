/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:13:32 by csilva-f          #+#    #+#             */
/*   Updated: 2023/01/08 19:15:13 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

t_stack	*get_penult_node(t_stack *list)
{
	while (list)
	{
		if (list->next->next == NULL && list->next == NULL)
			break ;
		list = list->next;
	}
	return (list);
}
