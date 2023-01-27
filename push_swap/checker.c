/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:04:14 by csilva-f          #+#    #+#             */
/*   Updated: 2023/01/26 23:48:15 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/get_next_line_bonus.h"
#include "libft/libft.h"
#include "push_swap_bonus.h"
#include <unistd.h>

void	handle_errors(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

int	is_sorted(t_stack *s_a)
{
	t_stack	*temp;

	temp = s_a;
	while (temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	check_integers(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1] != '\0')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_input(int argc, char **argv)
{
	int	i;

	while (argc > 1)
	{
		if (check_integers(argv[argc - 1]) == 0 || \
				ft_atoi(argv[argc - 1]) > INT_MAX || \
				ft_atoi(argv[argc - 1]) < INT_MIN)
			return (0);
		i = 1;
		while ((argc - 1 - i) >= 1)
		{
			if (ft_atoi(argv[argc - 1]) == ft_atoi(argv[argc - 1 - i]))
				return (0);
			i++;
		}
		argc--;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*s_a;
	t_stack	*s_b;

	if (argc < 2)
		return (0);
	if (check_input(argc, argv) == 0)
	{
		handle_errors();
		return (0);
	}
	s_a = nbrs_to_stack(argc, argv);
	s_b = NULL;
	read_moves(&s_a, &s_b);
	if (is_sorted(s_a) && !s_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
