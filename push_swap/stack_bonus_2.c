/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:41:13 by csilva-f          #+#    #+#             */
/*   Updated: 2023/01/28 19:22:06 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/get_next_line.h"
#include "libft/libft.h"
#include "push_swap_bonus.h"

t_stack	*get_penult_node(t_stack *list)
{
	while (list && list->next && list->next->next != NULL)
		list = list->next;
	return (list);
}

void	free_s(t_stack **list)
{
	t_stack	*aux;

	if (!list || !(*list))
		return ;
	while (*list)
	{
		aux = (*list)->next;
		free(*list);
		*list = aux;
	}
	list = NULL;
}

int	execute_moves(char *str, t_stack **s_a, t_stack **s_b)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		apply_sa(s_a);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		apply_sb(s_b);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		apply_ss(s_a, s_b);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		apply_ra(s_a);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		apply_rb(s_b);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		apply_rr(s_a, s_b);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		apply_rra(s_a);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		apply_rrb(s_b);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		apply_rrr(s_a, s_b);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		apply_pa(s_b, s_a);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		apply_pb(s_a, s_b);
	else
		return (0);
	return (1);
}

int	read_moves(t_stack **s_a, t_stack **s_b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(STDIN_FILENO);
		if (!str)
			break ;
		if (execute_moves(str, s_a, s_b) == 0)
		{
			free(str);
			return (0);
		}
		free(str);
	}
	return (1);
}

/*int	check_moves(char *str)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		return (1);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		return (1);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		return (1);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		return (1);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		return (1);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		return (1);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		return (1);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		return (1);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		return (1);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		return (1);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		return (1);
	return (0);
}*/
