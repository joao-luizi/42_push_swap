/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:38:09 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 18:04:38 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Fills a move list with a single `SA` or `SB` move.
 *
 * @param moves Pointer to the move list to fill.
 * @param stk_type The type of the stack (STACK_A or STACK_B).
 */
void	fill_sa(t_move *moves, t_stack_type stk_type)
{
	t_move_type	move_swap;

	move_swap = SA;
	if (stk_type == STACK_B)
		move_swap = get_mirror_move(move_swap);
	moves->mov[moves->len] = move_swap;
	moves->len++;
}

/**

	* Fills a move list with a `SA` move 
	followed by a `RA` (or a `SB` and `RB`) move.
 *
 * @param moves Pointer to the move list to fill.
 * @param stk_type The type of the stack (STACK_A or STACK_B).
 */
void	fill_sa_ra(t_move *moves, t_stack_type stk_type)
{
	t_move_type	move_swap;
	t_move_type	move_rot;

	move_swap = SA;
	move_rot = RA;
	if (stk_type == STACK_B)
	{
		move_swap = get_mirror_move(move_swap);
		move_rot = get_mirror_move(move_rot);
	}
	moves->mov[moves->len] = move_swap;
	moves->mov[moves->len + 1] = move_rot;
	moves->len += 2;
}

/**

	* Fills a move list with a `SA` move 
	followed by a `RRA` (or a `SB` and `RRB`) move.
 *
 * @param moves Pointer to the move list to fill.
 * @param stk_type The type of the stack (STACK_A or STACK_B).
 */
void	fill_sa_rra(t_move *moves, t_stack_type stk_type)
{
	t_move_type	move_swap;
	t_move_type	move_rrot;

	move_swap = SA;
	move_rrot = RRA;
	if (stk_type == STACK_B)
	{
		move_swap = get_mirror_move(move_swap);
		move_rrot = get_mirror_move(move_rrot);
	}
	moves->mov[moves->len] = move_swap;
	moves->mov[moves->len + 1] = move_rrot;
	moves->len += 2;
}

/**
 * Fills a move list with a single `RA` (or `RB`) move.
 *
 * @param moves Pointer to the move list to fill.
 * @param stk_type The type of the stack (STACK_A or STACK_B).
 */
void	fill_ra(t_move *moves, t_stack_type stk_type)
{
	t_move_type	move_rot;

	move_rot = RA;
	if (stk_type == STACK_B)
		move_rot = get_mirror_move(move_rot);
	moves->mov[moves->len] = move_rot;
	moves->len++;
}

/**
 * Fills a move list with a single `RRA` (or `RRB`) move.
 *
 * @param moves Pointer to the move list to fill.
 * @param stk_type The type of the stack (STACK_A or STACK_B).
 */
void	fill_rra(t_move *moves, t_stack_type stk_type)
{
	t_move_type	move_rrot;

	move_rrot = RRA;
	if (stk_type == STACK_B)
		move_rrot = get_mirror_move(move_rrot);
	moves->mov[moves->len] = move_rrot;
	moves->len++;
}
