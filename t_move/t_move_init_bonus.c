/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_move_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:38:24 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:45:42 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Initializes a new t_move structure.
 *
 * @return A pointer to the newly created t_move structure if successful,
	or NULL if an allocation error occurs.
 */
t_move	*t_move_init(void)
{
	t_move	*moves;

	moves = malloc(sizeof(t_move));
	if (!moves)
		return (NULL);
	moves->mov = malloc(MAX_MOVES);
	if (!moves->mov)
	{
		free(moves);
		return (NULL);
	}
	ft_memset(moves->mov, 0, MAX_MOVES);
	moves->len = 0;
	return (moves);
}
