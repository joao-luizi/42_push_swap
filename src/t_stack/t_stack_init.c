/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:38:31 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 18:05:31 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Initializes an empty stack with a specified maximum size.
 *
 * @param maxsize The maximum number of elements the stack can hold.
 * @return A pointer to the newly created stack if successful,
	or NULL if an allocation error occurs.
 */
t_stack	*init_empty_stack(size_t maxsize)
{
	t_stack	*stack;

	if (maxsize == 0)
		return (NULL);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->arr = malloc((sizeof(int) * maxsize) + 1);
	if (!stack->arr)
	{
		free(stack);
		return (NULL);
	}
	ft_memset(stack->arr, 0, (sizeof(int) * maxsize) + 1);
	stack->len = 0;
	return (stack);
}

/**
 * Initializes a stack from a given array.
 *
 * @param arr A pointer to the array to be copied.
 * @param len The length of the array.
 * @return A pointer to the newly created stack if successful,
	or NULL if an allocation error occurs.
 */
t_stack	*init_stack_from_array(int *arr, size_t len)
{
	t_stack	*stack;
	size_t	i;

	stack = init_empty_stack(len);
	if (!stack)
		return (NULL);
	stack->len = len;
	i = 0;
	while (i < len)
	{
		stack->arr[i] = arr[i];
		i++;
	}
	return (stack);
}
