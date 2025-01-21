/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:38:12 by joaomigu          #+#    #+#             */
/*   Updated: 2024/10/07 14:26:29 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**

	* Fills a move list with the moves required to 
	sort a stack with three elements in ascending order.
 *
 * @param moves Pointer to the move list to fill.
 * @param stack Pointer to the stack to sort.
 * @param stk_type The type of the stack (STACK_A or STACK_B).
 */
static void	fill_three_ascending(t_move *moves, t_stack *stack,
		t_stack_type stk_type)
{
	int	pos_0;
	int	pos_1;
	int	pos_2;

	pos_0 = stack->arr[0];
	pos_1 = stack->arr[1];
	pos_2 = stack->arr[2];
	if (pos_0 > pos_1 && pos_1 < pos_2 && pos_2 > pos_0)
		fill_sa(moves, stk_type);
	else if (pos_0 > pos_1 && pos_1 > pos_2 && pos_2 < pos_0)
		fill_sa_rra(moves, stk_type);
	else if (pos_0 > pos_1 && pos_1 < pos_2 && pos_2 < pos_0)
		fill_ra(moves, stk_type);
	else if (pos_0 < pos_1 && pos_1 > pos_2 && pos_2 < pos_0)
		fill_rra(moves, stk_type);
	else if (pos_0 < pos_1 && pos_1 > pos_2 && pos_2 > pos_0)
		fill_sa_ra(moves, stk_type);
}

/**

	* Fills a move list with the moves required to 
	sort a stack with three elements in descending order.
 *
 * @param moves Pointer to the move list to fill.
 * @param stack Pointer to the stack to sort.
 * @param stk_type The type of the stack (STACK_A or STACK_B).
 */
static void	fill_three_descending(t_move *moves, t_stack *stack,
		t_stack_type stk_type)
{
	int	pos_0;
	int	pos_1;
	int	pos_2;

	pos_0 = stack->arr[0];
	pos_1 = stack->arr[1];
	pos_2 = stack->arr[2];
	if (pos_0 > pos_1 && pos_1 < pos_2 && pos_2 > pos_0)
		fill_rra(moves, stk_type);
	else if (pos_0 < pos_1 && pos_1 < pos_2 && pos_2 > pos_0)
		fill_sa_rra(moves, stk_type);
	else if (pos_0 > pos_1 && pos_1 < pos_2 && pos_2 < pos_0)
		fill_sa_ra(moves, stk_type);
	else if (pos_0 < pos_1 && pos_1 > pos_2 && pos_2 < pos_0)
		fill_sa(moves, stk_type);
	else if (pos_0 < pos_1 && pos_1 > pos_2 && pos_2 > pos_0)
		fill_ra(moves, stk_type);
}

/**
 * Sorts a stack with exactly three elements.
 *
 * Determines the necessary moves to sort the stack 
 * in the specified order.
 *
 * @param stack Pointer to the stack to sort.
 * @param stk_type The type of the stack (STACK_A or STACK_B).
 * @param order The desired sorting order (ASCENDING or DESCENDING).
 *
 * @return A list of moves required to sort the stack,
	or NULL if no moves are needed.
 */
t_move	*sort_three(t_stack *stack, t_stack_type stk_type, t_sort_order order)
{
	t_move	*result_moves;

	if (!stack)
		return (NULL);
	result_moves = t_move_init();
	if (!result_moves)
		return (NULL);
	if (order == ASCENDING)
		fill_three_ascending(result_moves, stack, stk_type);
	if (order == DESCENDING)
		fill_three_descending(result_moves, stack, stk_type);
	return (result_moves);
}

/**
 * Sorts a stack with exactly two elements.
 *
 * Determines the necessary move to sort the stack 
 * in the specified order.
 *
 * @param stack Pointer to the stack to sort.
 * @param stk_type The type of the stack (STACK_A or STACK_B).
 * @param order The desired sorting order (ASCENDING or DESCENDING).
 *
 * @return A list of moves required to sort the stack,
	or NULL if no moves are needed.
 */
t_move	*sort_two(t_stack *stack, t_stack_type stk_type, t_sort_order order)
{
	t_move		*result_moves;
	t_move_type	move;
	int			first;
	int			second;

	if (!stack)
		return (NULL);
	result_moves = t_move_init();
	if (!result_moves)
		return (NULL);
	move = SA;
	if (stk_type == STACK_B)
		move = get_mirror_move(move);
	first = stack->arr[0];
	second = stack->arr[1];
	if (order == ASCENDING && first > second)
		result_moves->mov[result_moves->len] = move;
	if (order == DESCENDING && first < second)
		result_moves->mov[result_moves->len] = move;
	result_moves->len++;
	return (result_moves);
}
