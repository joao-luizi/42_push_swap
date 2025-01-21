/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:41:15 by joaomigu          #+#    #+#             */
/*   Updated: 2024/10/05 14:48:55 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_MOVES 6000

# include "../lib/libft/include/libft.h"
# include "t_move.h"
# include "t_stack.h"
# include "t_state.h"
# include "parser.h"
# include <limits.h>
# include <unistd.h>

typedef struct s_element_info
{
	int			target_a;
	int			target_b;
	int			cost_a;
	int			cost_b;
	t_move_type	move_a;
	t_move_type	move_b;
}	t_element_info;

t_element_info	get_target_element_info(t_state *state);
int				contains_value_in_stack(int *stack, int size, int value);
void			index_array(int *arr, size_t size);
int				element_index(int *arr, size_t size, int value);
int				get_target_value(int *arr, size_t size, int value);

void			sort(t_state *state);
void			final_sort(t_state *state, t_move *moves);
t_move			*sort_three(t_stack *stack, t_stack_type stk_type,
					t_sort_order order);
t_move			*sort_two(t_stack *stack, t_stack_type stk_type,
					t_sort_order order);
t_move			*sort_big(t_state *state);
void			join_stack_b(t_state *state, t_move *moves);
void			sort_big_merge(t_state *state, t_move *moves);
void			sort_big_split(t_state *state, t_move *result);

void			fill_sa(t_move *moves, t_stack_type stk_type);
void			fill_sa_ra(t_move *moves, t_stack_type stk_type);
void			fill_sa_rra(t_move *moves, t_stack_type stk_type);
void			fill_ra(t_move *moves, t_stack_type stk_type);
void			fill_rra(t_move *moves, t_stack_type stk_type);

void			analyse_tops(t_state *state, t_move_type current);

#endif
