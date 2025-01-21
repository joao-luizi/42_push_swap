/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:38:18 by joaomigu          #+#    #+#             */
/*   Updated: 2024/10/07 14:27:54 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
	* Sorts the numbers in the state's `stk_a` 
	stack by returning the necessary moves.
 *
 * The sorting algorithm used depends on the number 
 * of numbers in the stack:
 * - If there are 2 numbers, `sort_two` is used.
 * - If there are 3 numbers, `sort_three` is used.
 * - If there are more than 3 numbers, `sort_big` is used.
 *
 * The returned moves are then executed to sort the stack.
 *
 * @param state Pointer to the state to be sorted.
 *
 * @return A list of moves required to sort the stack,
	or NULL if no moves are needed.
 */
void	sort(t_state *state)
{
	t_move	*result_moves;

	result_moves = NULL;
	if (state->stk_a->len == 2)
	{
		result_moves = sort_two(state->stk_a, STACK_A, ASCENDING);
		execute_t_move(result_moves, state, SAVE_ALLOW);
	}
	else if (state->stk_a->len == 3)
	{
		result_moves = sort_three(state->stk_a, STACK_A, ASCENDING);
		execute_t_move(result_moves, state, SAVE_ALLOW);
	}
	else if (state->stk_a->len > 3)
		result_moves = sort_big(state);
	if (result_moves)
		free_t_move(result_moves, TRUE);
}

/**
 * Sorts a stack with more than 3 elements.
 *
 * This function orchestrates the sorting process 
 * for stacks with more than 3 elements,
 * calling the necessary functions to split the stack,
 *  sort the smaller parts,
 * join the stacks, and perform the final sorting steps.
 *
 * @param state The current state of the sorting process.
 *
 * @return A list of moves representing the sorting 
 * process, or NULL if an error occurs.
 */
t_move	*sort_big(t_state *state)
{
	t_move	*result_moves;

	if (!state)
		return (NULL);
	result_moves = t_move_init();
	if (!result_moves)
		return (NULL);
	sort_big_split(state, result_moves);
	sort_big_merge(state, result_moves);
	join_stack_b(state, result_moves);
	final_sort(state, result_moves);
	return (result_moves);
}
