/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_state_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:38:45 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 18:06:41 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Frees the memory allocated for a t_state structure.
 *
 * @param state A pointer to the t_state structure to be freed.

	* @param self_dispose A flag indicating whether to 
	free the state itself (1) or just the members within it (0).
 */
void	free_t_state(t_state *state, int self_dispose)
{
	if (!state)
		return ;
	if (state->mov_list)
		free_t_move(state->mov_list, TRUE);
	if (state->stk_a)
		free_t_stack(state->stk_a, TRUE);
	if (state->stk_b)
		free_t_stack(state->stk_b, TRUE);
	if (self_dispose)
		free(state);
}
