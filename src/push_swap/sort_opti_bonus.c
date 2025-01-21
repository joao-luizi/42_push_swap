/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_opti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:59:14 by joaomigu          #+#    #+#             */
/*   Updated: 2024/10/05 14:55:38 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
/**
 * Checks for and performs potential swaps between
 *  the top elements of stacks A and B.
 *
 * This function examines the top two elements of 
 * each stack and determines if they
 * are consecutive integers in the correct order. 
 * If so, it performs a swap operation
 * to place them in their final relative positions.
 *
 * @param state The current state of the sorting process.
 * @param current The last move that was performed.
 */
static	void	check_swap(t_state *state, t_move_type current)
{
	if (current != SA && current != SS && state->stk_a->len >= 2)
	{
		if (state->stk_a->arr[0] == state->stk_a->arr[1] + 1)
		{
			state_swap(state, STACK_A);
			register_move(state->mov_list, SA);
		}
	}
	if ((current != SB && current != SS && state->stk_b->len >= 2))
	{
		if (state->stk_b->arr[0] == state->stk_b->arr[1] - 1)
		{
			state_swap(state, STACK_B);
			register_move(state->mov_list, SB);
		}
	}
}

/**
 * Analyzes the top elements of stacks A and B and 
 * performs potential swaps.
 *
 * This function calls `check_swap` to analyze the 
 * top elements of each stack and
 * perform any necessary swaps.
 *
 * @param state The current state of the sorting process.
 * @param current The current move that is to be performed.
 */
void	analyse_tops(t_state *state, t_move_type current)
{
	check_swap(state, current);
}
