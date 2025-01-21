/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:38:35 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 18:06:03 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Swaps the top two elements of a given stack.
 *
 * @param stack Pointer to the stack.
 *
 * @return TRUE if the swap was successful, FALSE otherwise.
 */
int	swap(t_stack *stack)
{
	int	first;

	if (!stack)
		return (FALSE);
	first = stack->arr[0];
	stack->arr[0] = stack->arr[1];
	stack->arr[1] = first;
	return (TRUE);
}

/**
 * Rotates the elements in a given stack.
 *
 * @param stack Pointer to the stack.
 *
 * @return TRUE if the rotation was successful, FALSE otherwise.
 */
int	rot(t_stack *stack)
{
	int		first;
	size_t	i;

	if (!stack)
		return (FALSE);
	first = stack->arr[0];
	i = 1;
	while (i < stack->len)
	{
		stack->arr[i - 1] = stack->arr[i];
		i++;
	}
	stack->arr[stack->len - 1] = first;
	return (TRUE);
}

/**
 * Reverse rotates the elements in a given stack.
 *
 * @param stack Pointer to the stack.
 *
 * @return TRUE if the reverse rotation was successful, FALSE otherwise.
 */
int	rrot(t_stack *stack)
{
	int		last;
	size_t	i;

	if (!stack)
		return (FALSE);
	last = stack->arr[stack->len - 1];
	i = stack->len - 1;
	while (i > 0)
	{
		stack->arr[i] = stack->arr[i - 1];
		i--;
	}
	stack->arr[0] = last;
	return (TRUE);
}

/**
 * Pushes the top element from one stack to another.
 *
 * @param source Pointer to the source stack.
 * @param destiny Pointer to the destination stack.
 *
 * @return TRUE if the push was successful, FALSE otherwise.
 */
int	push(t_stack *source, t_stack *destiny)
{
	int		from_source;
	size_t	i;

	if (!source)
		return (FALSE);
	from_source = source->arr[0];
	i = 0;
	while (i < source->len)
	{
		source->arr[i] = source->arr[i + 1];
		i++;
	}
	i = destiny->len;
	while (i > 0)
	{
		destiny->arr[i] = destiny->arr[i - 1];
		i--;
	}
	destiny->arr[0] = from_source;
	return (TRUE);
}
