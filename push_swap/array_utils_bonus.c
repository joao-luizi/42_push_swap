/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:37:50 by joaomigu          #+#    #+#             */
/*   Updated: 2024/10/05 14:53:04 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Checks if a given value exists in an integer array.
 *
 * @param arr The integer array to search.
 * @param size The size of the array.
 * @param value The value to search for.
 * @return TRUE if the value is found, FALSE otherwise.
 */
int	contains_value_in_stack(int *arr, int size, int value)
{
	int	i;

	if (!arr)
		return (FALSE);
	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

/**
 * Calculates the rank of a value in an integer array.
 *
 * @param arr The integer array.
 * @param size The size of the array.
 * @param value The value to find the rank for.
 * @return The rank of the value in the array.
 */
static int	get_rank(int *arr, int size, int value)
{
	int	j;
	int	rank;

	rank = 0;
	j = 0;
	while (j < size)
	{
		if (arr[j] < value)
			rank++;
		j++;
	}
	return (rank);
}

/**
 * Replaces elements in an integer array with their 
 * corresponding ranks.
 *
 * @param arr The integer array.
 * @param size The size of the array.
 */
void	index_array(int *arr, size_t size)
{
	size_t	i;
	int		*index;

	index = malloc(sizeof(int) * size);
	if (!index)
		return ;
	i = 0;
	while (i < size)
	{
		index[i] = get_rank(arr, size, arr[i]) + 1;
		i++;
	}
	i = 0;
	while (i < size)
	{
		arr[i] = index[i];
		i++;
	}
	free(index);
}

/**
 * Finds the index of a given element in an integer array.
 *
 * This function searches through the given array for the 
 * specified value. If the
 * value is found, its index is returned. Otherwise, -1 is returned.
 *
 * @param arr The array of integers to search.
 * @param size The size of the array.
 * @param value The value to search for.
 *
 * @return The index of the element if found, or -1 if not found.
 */
int	element_index(int *arr, size_t size, int value)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * Finds the smallest value in an array that
 *  is greater than a given value.
 *
 * This function searches through the given array 
 * for the smallest element that is
 * greater than the specified value. If such an 
 * element is found, its value is returned.
 * Otherwise, the function recursively searches 
 * for the smallest value in the entire
 * array.
 *
 * @param arr The array of integers to search.
 * @param size The size of the array.
 * @param value The value to compare against.
 *
 * @return The smallest value in the array that 
 * is greater than the given value, or
 *         the smallest value in the array if no 
 * such value exists.
 */
int	get_target_value(int *arr, size_t size, int value)
{
	size_t	i;
	int		index;

	index = INT_MAX;
	i = 0;
	while (i < size)
	{
		if (arr[i] > value && arr[i] < index)
			index = arr[i];
		i++;
	}
	if (index == INT_MAX)
		index = get_target_value(arr, size, INT_MIN);
	return (index);
}
