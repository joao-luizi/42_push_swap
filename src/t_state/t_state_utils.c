/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_state_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:38:53 by joaomigu          #+#    #+#             */
/*   Updated: 2024/10/09 18:51:16 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Checks if a state is sorted.
 *
 * A state is considered sorted if:
 * - The `stk_b` stack is empty.
 * - The `stk_a` stack has at most one element.
 * - The `stk_a` stack is sorted in ascending order.
 *
 * @param state Pointer to the state to check.
 *
 * @return TRUE if the state is sorted, FALSE otherwise.
 */
int	is_state_sorted(t_state *state)
{
	if (!state)
		return (FALSE);
	if (state->stk_b->len > 0)
		return (FALSE);
	if (state->stk_a->len < 2)
		return (TRUE);
	return (is_stack_sorted(state->stk_a, ASCENDING));
}

/**
 * Prints a given state, including its move list and stacks.
 *
 * Outputs the move list, stack A, and stack B to the console.
 *
 * @param state Pointer to the state to print.
 */
void	print_state(t_state *state)
{
	if (!state)
		return ;
	ft_printf("Move list:\n");
	print_moves(state->mov_list);
	ft_printf("Stack A:\n");
	print_stack(state->stk_a);
	ft_printf("Stack B:\n");
	print_stack(state->stk_b);
}

/**
 * Performs a given move on the specified state.
 *
 * This function executes the specified move type 
 * on the given state, updating the
 * stacks and other relevant state information.
 *
 * @param state The current state of the sorting process.
 * @param move The move type to perform.
 *
 * @return TRUE if the move was executed successfully, FALSE otherwise.
 */
int	perform_move(t_state *state, t_move_type move)
{
	if (move == SA)
		return (state_swap(state, STACK_A));
	else if (move == SB)
		return (state_swap(state, STACK_B));
	else if (move == SS)
		return (state_swap(state, STACK_A) && state_swap(state, STACK_B));
	else if (move == PA)
		return (state_push_to(state, STACK_A));
	else if (move == PB)
		return (state_push_to(state, STACK_B));
	else if (move == RA)
		return (state_rot(state, STACK_A));
	else if (move == RB)
		return (state_rot(state, STACK_B));
	else if (move == RR)
		return (state_rot(state, STACK_A) && state_rot(state, STACK_B));
	else if (move == RRA)
		return (state_rrot(state, STACK_A));
	else if (move == RRB)
		return (state_rrot(state, STACK_B));
	else if (move == RRR)
		return (state_rrot(state, STACK_A) && state_rrot(state, STACK_B));
	else
		return (FALSE);
}

/**
 * Executes a list of moves on a state.
 *
 * This function iterates through the given move list, executes each move on the
 * state, and optionally registers the executed moves in the state's move list.
 *
 * @param moves The list of moves to execute.
 * @param state The current state of the sorting process.
 * @param option The option to save or not save the executed moves.
 *
 * @return TRUE if all moves were executed successfully, FALSE otherwise.
 */
int	execute_t_move(t_move *moves, t_state *state, t_save_option option)
{
	size_t	i;

	if (!moves || moves->len == 0 || !state)
		return (FALSE);
	i = 0;
	while (i < moves->len)
	{
		analyse_tops(state, moves->mov[i]);
		if (perform_move(state, moves->mov[i]))
		{
			if (option == SAVE_ALLOW)
				register_move(state->mov_list, moves->mov[i]);
		}
		i++;
	}
	return (TRUE);
}
