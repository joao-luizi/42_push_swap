/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:59:22 by joaomigu          #+#    #+#             */
/*   Updated: 2024/10/05 14:55:22 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
/**
 * Fills a move list with the necessary moves to 
 * position elements in stacks A and B.
 *
 * This function determines the moves required to 
 * bring the target elements to their
 * correct positions based on the calculated costs 
 * and the relationship between the
 * moves.
 *
 * @param moves The list of moves to be filled.
 * @param info The element info structure containing 
 * the target elements and their costs.
 */
static	void	fill_moves(t_move *moves, t_element_info info)
{
	moves->len = 0;
	if (info.move_a == get_mirror_move(info.move_b))
	{
		while (info.cost_b > 0 && info.cost_a > 0)
		{
			moves->mov[moves->len++] = get_dual_move(info.move_a);
			info.cost_a--;
			info.cost_b--;
		}
	}
	while (info.cost_b > 0 || info.cost_a > 0)
	{
		if (info.cost_b > 0)
		{
			moves->mov[moves->len++] = info.move_b;
			info.cost_b--;
		}
		if (info.cost_a > 0)
		{
			moves->mov[moves->len++] = info.move_a;
			info.cost_a--;
		}
	}
}

/**
 * Sorts the elements in stack A and pushes them to 
 * stack B in a presorted order.
 *
 * This function iterates through stack A, identifies 
 * the elements that should be
 * pushed to the top or bottom of stack B, and executes
 *  the necessary moves.
 *
 * @param state The current state of the sorting process.
 * @param result The list of moves to be executed.
 */
void	sort_big_split(t_state *state, t_move *result)
{
	size_t	i;
	size_t	size;
	t_stack	*stack_a;

	stack_a = state->stk_a;
	size = stack_a->len;
	i = 0;
	while (i < state->stk_a->len)
	{
		if ((size_t)stack_a->arr[i] > (size - 3))
			result->mov[result->len++] = RA;
		else if ((size_t)stack_a->arr[i] > (size / 2))
		{
			result->mov[result->len++] = PB;
			result->mov[result->len++] = RB;
		}
		else
			result->mov[result->len++] = PB;
		i++;
	}
	execute_t_move(result, state, SAVE_ALLOW);
	result->len = 0;
}

/**
 * Frees the memory allocated for two move lists 
 * if necessary.
 *
 * This function checks if the given move lists 
 * are not NULL and frees their memory
 * if they are.
 *
 * @param sort_a The first move list.
 * @param sort_b The second move list.
 */
static void	free_on_error(t_move *sort_a, t_move	*sort_b)
{
	if (sort_a)
		free_t_move(sort_a, TRUE);
	if (sort_b)
		free_t_move(sort_b, TRUE);
}

/**
 * Sorts the remaining elements in stack A and stack B.
 *
 * This function sorts the elements in stack A and 
 * stack B using the appropriate
 * sorting function based on the number of elements, 
 * merges the resulting move lists,
 * and executes the merged moves.
 *
 * @param state The current state of the sorting process.
 * @param moves The list of moves to be executed.
 */
void	sort_big_merge(t_state *state, t_move *moves)
{
	t_move	*sort_a;
	t_move	*sort_b;

	if (state->stk_a->len >= 3)
		sort_a = sort_three(state->stk_a, STACK_A, ASCENDING);
	else if (state->stk_a->len == 2)
		sort_a = sort_two(state->stk_a, STACK_A, ASCENDING);
	else
		sort_a = t_move_init();
	if (state->stk_b->len >= 3)
		sort_b = sort_three(state->stk_b, STACK_B, DESCENDING);
	else if (state->stk_b->len == 2)
		sort_b = sort_two(state->stk_b, STACK_B, DESCENDING);
	else
		sort_b = t_move_init();
	if (!sort_a || !sort_b)
	{
		free_on_error(sort_a, sort_b);
		return ;
	}
	merge_list(moves, sort_a, sort_b);
	execute_t_move(moves, state, SAVE_ALLOW);
	free_t_move(sort_a, TRUE);
	free_t_move(sort_b, TRUE);
	moves->len = 0;
}

/**
 * Joins stack B with stack A in a sorted manner.
 *
 * This function repeatedly finds the element pair 
 * with the smallest combined cost,
 * moves the elements to their correct positions, 
 * and pushes them from stack B to
 * stack A.
 *
 * @param state The current state of the sorting 
 * process.
 * @param moves The list of moves to be executed.
 */
void	join_stack_b(t_state *state, t_move *moves)
{
	t_element_info	info;

	while (state->stk_b->len > 0)
	{
		info = get_target_element_info(state);
		fill_moves(moves, info);
		moves->mov[moves->len++] = PA;
		execute_t_move(moves, state, SAVE_ALLOW);
		moves->len = 0;
	}
}
