/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_state_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:38:50 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 18:10:48 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Swaps the top two elements of the specified stack in the given state.
 *
 * @param state Pointer to the state.
 * @param stk_type The type of the stack (STACK_A or STACK_B).
 *
 * @return TRUE if the swap was successful, FALSE otherwise.
 */
int	state_swap(t_state *state, t_stack_type stk_type)
{
	t_stack	*stack;
	int		size;

	if (!state)
		return (FALSE);
	if (stk_type == STACK_A)
		stack = state->stk_a;
	else
		stack = state->stk_b;
	size = stack->len;
	if (!stack || size < 2)
		return (FALSE);
	if (!swap(stack))
	{
		ft_printf("Error processing swap on %s\n",
			stack_type_to_string(stk_type));
		return (FALSE);
	}
	return (TRUE);
}

/**
 * Rotates the elements in the specified stack in the given state.
 *
 * @param state Pointer to the state.
 * @param stk_type The type of the stack (STACK_A or STACK_B).
 *
 * @return TRUE if the rotation was successful, FALSE otherwise.
 */
int	state_rot(t_state *state, t_stack_type stk_type)
{
	t_stack	*stack;
	int		size;

	if (!state)
		return (FALSE);
	if (stk_type == STACK_A)
		stack = state->stk_a;
	else
		stack = state->stk_b;
	size = stack->len;
	if (!stack || size < 2)
		return (FALSE);
	if (!rot(stack))
	{
		ft_printf("Error processing rotation on %s\n",
			stack_type_to_string(stk_type));
		return (FALSE);
	}
	return (TRUE);
}

/**
 * Reverse rotates the elements in the specified stack in the given state.
 *
 * @param state Pointer to the state.
 * @param stk_type The type of the stack (STACK_A or STACK_B).
 *
 * @return TRUE if the reverse rotation was successful, FALSE otherwise.
 */
int	state_rrot(t_state *state, t_stack_type stk_type)
{
	t_stack	*stack;
	int		size;

	if (!state)
		return (FALSE);
	if (stk_type == STACK_A)
		stack = state->stk_a;
	else
		stack = state->stk_b;
	size = stack->len;
	if (!stack || size < 2)
		return (FALSE);
	if (!rrot(stack))
	{
		ft_printf("Error processing rotation on %s\n",
			stack_type_to_string(stk_type));
		return (FALSE);
	}
	return (TRUE);
}

/**

	* Pushes the top element from the source 
	stack to the destination stack in the given state.
 *
 * @param state Pointer to the state.
 * @param stk_type The type of the destination stack (STACK_A or STACK_B).
 *
 * @return TRUE if the push was successful, FALSE otherwise.
 */
int	state_push_to(t_state *state, t_stack_type stk_type)
{
	t_stack	*source;
	t_stack	*destiny;

	if (!state)
		return (FALSE);
	if (stk_type == STACK_A)
	{
		destiny = state->stk_a;
		source = state->stk_b;
	}
	else
	{
		destiny = state->stk_b;
		source = state->stk_a;
	}
	if (!push(source, destiny))
	{
		ft_printf("Error processing push to  %s\n",
			stack_type_to_string(stk_type));
		return (FALSE);
	}
	destiny->len++;
	source->len--;
	return (TRUE);
}
