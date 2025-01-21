/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:38:29 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 18:05:22 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Frees the memory allocated for a t_stack structure.
 *
 * @param stack A pointer to the t_stack structure to be freed.

	* @param self_dispose A flag indicating whether to 
	free the stack itself (1) or just the array within it (0).
 */
void	free_t_stack(t_stack *stack, int self_dispose)
{
	if (!stack)
		return ;
	if (stack->arr)
		free(stack->arr);
	if (self_dispose)
		free(stack);
}
