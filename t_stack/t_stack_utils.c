/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:38:42 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 18:05:47 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Checks if a stack is sorted in the specified order.
 *
 * @param stack Pointer to the stack to check.
 * @param order The desired sorting order (ASCENDING or DESCENDING).
 *
 * @return TRUE if the stack is sorted, FALSE otherwise.
 */
int	is_stack_sorted(t_stack *stack, t_sort_order order)
{
	size_t	i;

	if (!stack)
		return (FALSE);
	if (stack->len < 2)
		return (TRUE);
	i = 1;
	while (i < stack->len)
	{
		if (order == DESCENDING && (stack->arr[i] > stack->arr[i - 1]))
			return (FALSE);
		if (order == ASCENDING && (stack->arr[i] < stack->arr[i - 1]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/**
 * Gets the string representation of a given stack type.
 *
 * Returns a human-readable string corresponding to the specified stack type.
 *
 * @param stk_type The input stack type.
 *
 * @return A string representing the stack type.
 */
char	*stack_type_to_string(t_stack_type stk_type)
{
	if (stk_type == STACK_A)
		return ("STACK A");
	else if (STACK_B)
		return ("STACK B");
	else
		return ("STACK A&B");
}

/**
 * Prints a given stack and its element count.
 *
 * Outputs the elements of the stack to the console,
	followed by the element count.
 *
 * @param stack Pointer to the stack to print.
 */
void	print_stack(t_stack *stack)
{
	size_t	i;

	if (!stack || stack->len == 0)
	{
		ft_printf("Stack is empty.\n");
		return ;
	}
	i = 0;
	while (i < stack->len)
	{
		ft_printf("%d ", stack->arr[i]);
		i++;
	}
	ft_printf("\nCount %d\n", stack->len);
}
