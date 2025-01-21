/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_state.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:41:33 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:49:41 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_STATE_H
# define T_STATE_H

# include "t_move.h"
# include "t_stack.h"

typedef struct s_state
{
	struct s_move	*mov_list;
	struct s_stack	*stk_a;
	struct s_stack	*stk_b;

}					t_state;

typedef enum e_save_option
{
	SAVE_ALLOW,
	SAVE_DENY
}					t_save_option;

int					state_push_to(t_state *state, t_stack_type stk_type);
int					state_rrot(t_state *state, t_stack_type stk_type);
int					state_rot(t_state *state, t_stack_type stk_type);
int					state_swap(t_state *state, t_stack_type stk_type);

t_state				*init_state_from_args(int argc, char **argv, int *error);
t_state				*init_state_from_array(int *arr, size_t arr_size);
void				free_t_state(t_state *state, int self_dispose);

int					is_state_sorted(t_state *state);
void				print_state(t_state *state);
int					execute_t_move(t_move *moves, t_state *state,
						t_save_option option);
int					perform_move(t_state *state, t_move_type move);

#endif
