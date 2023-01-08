/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:46:42 by csilva-f          #+#    #+#             */
/*   Updated: 2023/01/08 19:27:42 by csilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				posit;
	int				t_posit;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

void		error(void);
int			check_integers(char *str);
int			check_input(int argc, char **argv);
t_stack		*create_node(int nbr);
t_stack		*get_last_node(t_stack *list);
t_stack		*get_penult_node(t_stack *list);
void		add_node_to_list(t_stack **list, t_stack *node);
t_stack		*nbrs_to_stack(int argc, char **argv);
int			count_stack_nbrs(t_stack *list);
void		assign_indexes(t_stack *s_a, int size);
int			is_sorted(t_stack *s_a);
void		apply_sa(t_stack *s_a, int is_ss);
void		apply_sb(t_stack *s_b, int is_ss);
void		apply_ss(t_stack *s_a, t_stack *s_b);
void		apply_ra(t_stack *s_a, int is_rr);
void		apply_rb(t_stack *s_b, int is_rr);
void		apply_rr(t_stack *s_a, t_stack *s_b);
void		apply_rra(t_stack *s_a, int is_rrr);
void		apply_rrb(t_stack *s_b, int is_rrr);
void		apply_rrr(t_stack *s_a, t_stack *s_b);

void		push_swap(t_stack *s_a);

#endif
