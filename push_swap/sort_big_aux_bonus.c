/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:59:14 by joaomigu          #+#    #+#             */
/*   Updated: 2024/10/05 14:56:36 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
/**
 * Assigns the values from one element info 
 * structure to another.
 *
 * This function copies the fields of the `src` 
 * structure to the corresponding fields
 * of the `dest` structure.
 *
 * @param src The source element info structure.
 * @param dest The destination element info structure.
 */
static	void	set_target_info(t_element_info src, t_element_info *dest)
{
	dest->target_a = src.target_a;
	dest->target_b = src.target_b;
	dest->cost_a = src.cost_a;
	dest->cost_b = src.cost_b;
	dest->move_a = src.move_a;
	dest->move_b = src.move_b;
}

/**
 * Determines whether an element in an array is 
 * above the median.
 *
 * This function calculates the median index of 
 * the array and compares the given
 * index to it. If the index is greater than the 
 * median index, TRUE is returned.
 * Otherwise, FALSE is returned.
 *
 * @param index The index of the element to check.
 * @param len The length of the array.
 *
 * @return TRUE if the element is above the median, 
 * FALSE otherwise.
 */
static	int	is_above_median(int index, size_t len)
{
	return ((size_t)index > (len / 2));
}

/**
 * Calculates the cost (in moves) to place a target
 *  element from stack B on top of
 * the correct element in stack A.
 *
 * This function determines the positions of the target
 *  elements in stacks A and B,
 * calculates the cost of moving them to their correct
 *  positions, and updates the
 * element info structure accordingly.
 *
 * @param state The current state of the sorting process.
 * @param info The element info structure to update.
 */
static	void	calc_cost(t_state *state, t_element_info *info)
{
	int	pos_a;
	int	pos_b;

	pos_a = element_index(state->stk_a->arr, state->stk_a->len, info->target_a);
	pos_b = element_index(state->stk_b->arr, state->stk_b->len, info->target_b);
	info->move_a = RA;
	info->move_b = RB;
	if (is_above_median(pos_a, state->stk_a->len))
	{
		info->cost_a = state->stk_a->len - pos_a;
		info->move_a = RRA;
	}
	else
		info->cost_a = pos_a;
	if (is_above_median(pos_b, state->stk_b->len))
	{
		info->cost_b = state->stk_b->len - pos_b;
		info->move_b = RRB;
	}
	else
		info->cost_b = pos_b;
}

/**
 * Finds the element pair from stack A and stack B 
 * with the smallest combined cost.
 *
 * This function iterates through stack B, calculates 
 * the cost of placing each
 * element on top of the correct element in stack A, 
 * and updates the element info
 * structure with the pair that has the smallest 
 * combined cost.
 *
 * @param state The current state of the sorting process.
 *
 * @return The element info structure containing 
 * the target elements and their
 *         combined cost.
 */
t_element_info	get_target_element_info(t_state *state)
{
	t_element_info	info;
	t_element_info	current;
	size_t			i;

	info.cost_a = state->stk_a->len + state->stk_b->len + 1;
	info.cost_b = state->stk_a->len + state->stk_b->len + 1;
	info.target_a = state->stk_a->len + state->stk_b->len + 1;
	info.target_b = state->stk_a->len + state->stk_b->len + 1;
	i = 0;
	while (i < state->stk_b->len)
	{
		current.target_b = state->stk_b->arr[i];
		current.target_a = get_target_value(state->stk_a->arr,
				state->stk_a->len, current.target_b);
		calc_cost(state, &current);
		if ((current.cost_a + current.cost_b) < (info.cost_a + info.cost_b))
			set_target_info(current, &info);
		i++;
	}
	return (info);
}

/**
 * Performs the final sorting steps after the elements
 *  are returned from stack B.
 *
 * This function finds the smallest element in stack A,
 *  calculates the cost of
 * rotating it to the top, and executes the necessary 
 * moves to achieve the sorted
 * state.
 *
 * @param state The current state of the sorting process.
 * @param moves The list of moves to be executed.
 */
void	final_sort(t_state *state, t_move *moves)
{
	int			smallest;
	int			position;
	int			cost;
	t_move_type	move;

	moves->len = 0;
	smallest = get_target_value(state->stk_a->arr, state->stk_a->len, INT_MIN);
	position = element_index(state->stk_a->arr, state->stk_a->len, smallest);
	if (is_above_median(position, state->stk_a->len))
	{
		move = RRA;
		cost = state->stk_a->len - position;
	}
	else
	{
		move = RA;
		cost = position;
	}
	while (cost)
	{
		moves->mov[moves->len++] = move;
		cost--;
	}
	execute_t_move(moves, state, SAVE_ALLOW);
}
