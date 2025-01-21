/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_move_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:38:26 by joaomigu          #+#    #+#             */
/*   Updated: 2024/10/05 14:57:54 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Gets the mirror move of a given move.
 *
 * The mirror move is the same move applied to the 
 * opposite stack.
 * For example, the mirror move of `SA` is `SB`.
 *
 * @param move The input move.
 *
 * @return The mirror move of the input move,
	or `NO_MOVE` if the input is invalid.
 */
t_move_type	get_mirror_move(t_move_type move)
{
	if (move == SA)
		return (SB);
	else if (move == SB)
		return (SA);
	else if (move == SS)
		return (SS);
	else if (move == PA)
		return (PB);
	else if (move == PB)
		return (PA);
	else if (move == RA)
		return (RB);
	else if (move == RB)
		return (RA);
	else if (move == RR)
		return (RR);
	else if (move == RRA)
		return (RRB);
	else if (move == RRB)
		return (RRA);
	else if (move == RRR)
		return (RRR);
	else
		return (NO_MOVE);
}

/**
 * Gets the dual move of a given move.
 *

	* The dual move is the move that corresponds 
	to moving both stacks in the same manner.
 * For example, the dual move of `SA` is `SS`.
 *
 * @param move The input move.
 *
 * @return The dual move of the input move,
	or `NO_MOVE` if the input is invalid.
 */
t_move_type	get_dual_move(t_move_type move)
{
	if (move == SA)
		return (SS);
	else if (move == SB)
		return (SS);
	else if (move == SS)
		return (SS);
	else if (move == RA)
		return (RR);
	else if (move == RB)
		return (RR);
	else if (move == RR)
		return (RR);
	else if (move == RRA)
		return (RRR);
	else if (move == RRB)
		return (RRR);
	else if (move == RRR)
		return (RRR);
	else
		return (NO_MOVE);
}

/**
 * Gets the string representation of a given move type.
 *
 * Returns a human-readable string corresponding to 
 * the specified move type.
 *
 * @param move The input move type.
 *
 * @return A string representing the move type,
	or "no_move" if the input is invalid.
 */
char	*operation_name(t_move_type move)
{
	if (move == SA)
		return ("sa");
	else if (move == SB)
		return ("sb");
	else if (move == SS)
		return ("ss");
	else if (move == PA)
		return ("pa");
	else if (move == PB)
		return ("pb");
	else if (move == RA)
		return ("ra");
	else if (move == RB)
		return ("rb");
	else if (move == RR)
		return ("rr");
	else if (move == RRA)
		return ("rra");
	else if (move == RRB)
		return ("rrb");
	else if (move == RRR)
		return ("rrr");
	else
		return ("no_move");
}

/**
 * Determines the move type associated with a given 
 * string.
 *
 * This function compares the input string to known 
 * move types and returns the
 * corresponding move type if a match is found. If no
 *  match is found, NO_MOVE is
 * returned.
 *
 * @param str The input string to analyze.
 *
 * @return The move type associated with the input 
 * string, or NO_MOVE if no match is found.
 */
t_move_type	get_move_type(char *str)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		return (SA);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		return (SB);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		return (SS);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		return (PA);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		return (PB);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		return (RA);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		return (RB);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		return (RR);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		return (RRA);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		return (RRB);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		return (RRR);
	else
		return (NO_MOVE);
}
