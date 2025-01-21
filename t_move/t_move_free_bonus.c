/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_move_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:38:21 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 18:06:27 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Frees the memory allocated for a t_move structure.
 *
 * @param moves A pointer to the t_move structure to be freed.

	* @param self_dispose A flag indicating whether to 
	free the moves itself (1) or just the character array within it (0).
 */
void	free_t_move(t_move *moves, int self_dispose)
{
	if (!moves)
		return ;
	if (moves->mov)
		free(moves->mov);
	if (self_dispose)
		free(moves);
}
