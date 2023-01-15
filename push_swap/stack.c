/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:30:06 by csilva-f          #+#    #+#             */
/*   Updated: 2023/01/15 14:53:47 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

t_stack	*create_node(int nbr)
{
	t_stack	*node;

	node = malloc(sizeof * node);
	if (!node)
		return (NULL);
	node->value = nbr;
	node->index = 0;
	node->posit = -1;
	node->t_posit = -1;
	node->cost_a = -1;
	node->cost_b = -1;
	node->next = NULL;
	return (node);
}

t_stack	*get_last_node(t_stack *list)
{
	while (list)
	{
		if (list->next == NULL)
			break ;
		list = list->next;
	}
	return (list);
}

void	add_node_to_list(t_stack **list, t_stack *node)
{
	t_stack	*last_node;

	if (!node || !(*list))
	{
		if (!(*list))
			*list = node;
		return ;
	}
	last_node = get_last_node(*list);
	last_node->next = node;
}

t_stack	*nbrs_to_stack(int argc, char **argv)
{
	t_stack	*s_a;
	int		i;

	s_a = NULL;
	i = 1;
	while (i < argc)
	{
		if (i == 1)
			s_a = create_node((int)ft_atoi(argv[i]));
		else
			add_node_to_list(&s_a, create_node((int)ft_atoi(argv[i])));
		i++;
	}
	return (s_a);
}

int	count_stack_nbrs(t_stack *list)
{
	int	c;

	c = 0;
	if (!list)
		return (0);
	while (list)
	{
		list = list->next;
		c++;
	}
	return (c);
}
