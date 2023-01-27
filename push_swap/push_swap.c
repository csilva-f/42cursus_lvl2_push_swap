/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <csilva-f@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:42:08 by csilva-f          #+#    #+#             */
/*   Updated: 2023/01/26 22:14:39 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	handle_errors(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

int	abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
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
		handle_errors();
	s_a = nbrs_to_stack(argc, argv);
	assign_indexes(s_a, count_stack_nbrs(s_a) + 1);
	s_b = NULL;
	push_swap(&s_a, &s_b);
	free_s(&s_a);
	free_s(&s_b);
	return (0);
}
