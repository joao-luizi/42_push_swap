/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_move_merge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:38:26 by joaomigu          #+#    #+#             */
/*   Updated: 2024/10/05 15:45:39 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
/**
 * Assigns two move types to a move list.
 *
 * This function appends the given move types `a` 
 * and `b` to the `result` list, considering
 * their compatibility and potential conflicts.
 *
 * @param result The move list to append to.
 * @param a The first move type.
 * @param b The second move type.
 * @param i The current index in the `result` list.
 */
static	void	assign_moves(t_move *result, t_move_type a,
					t_move_type b, int *i)
{
	if (a == NO_MOVE || b == NO_MOVE)
	{
		if (a != NO_MOVE)
			result->mov[(*i)++] = a;
		if (b != NO_MOVE)
			result->mov[(*i)++] = b;
	}
	else
	{
		if (a == get_mirror_move(b))
			result->mov[(*i)++] = get_dual_move(a);
		else
		{
			result->mov[(*i)++] = a;
			result->mov[(*i)++] = b;
		}
	}
}

/**
 * Fills a move list with merged moves from two 
 * other move lists.
 *
 * This function iterates through the `move_a` and
 *  `move_b` lists, merging their moves
 * into the `result` list. The `max_size` parameter 
 * determines the maximum number of
 * moves to process from each list.
 *
 * @param result The resulting move list.
 * @param move_a The first move list.
 * @param move_b The second move list.
 * @param max_size The maximum number of moves to 
 * process from each list.
 */
static	void	fill_result(t_move *result, t_move *move_a,
					t_move *move_b, size_t max_size)
{
	size_t		index_a;
	size_t		index_b;
	int			i;
	t_move_type	a;
	t_move_type	b;

	index_a = 0;
	index_b = 0;
	i = result->len;
	while (index_a < max_size || index_b < max_size)
	{
		a = NO_MOVE;
		b = NO_MOVE;
		if (index_a < move_a->len)
			a = move_a->mov[index_a];
		if (index_b < move_b->len)
			b = move_b->mov[index_b];
		if (a == NO_MOVE && b == NO_MOVE)
			break ;
		assign_moves(result, a, b, &i);
		index_a++;
		index_b++;
	}
	result->len = i;
}

/**
 * Merges two move lists into a single list.
 *
 * This function calls `fill_result` to merge the 
 * given move lists into the `result` list.
 *
 * @param result The resulting move list.
 * @param move_a The first move list.
 * @param move_b The second move list.
 */
void	merge_list(t_move *result, t_move *move_a, t_move *move_b)
{
	size_t	max_size;

	if (move_a->len > move_b->len)
		max_size = move_a->len;
	else
		max_size = move_b->len;
	fill_result(result, move_a, move_b, max_size);
}
