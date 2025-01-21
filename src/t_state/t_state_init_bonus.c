/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_state_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:38:48 by joaomigu          #+#    #+#             */
/*   Updated: 2024/10/09 19:12:46 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Checks if an argument is valid and adds it to a stack.
 *
 * @param argv The argument string.
 * @param stack The stack to add the argument to.
 * @param insert_index The index where to insert the argument.
 * @param error A pointer to an error flag.
 */
static void	check_argument(char *argv, int *stack, int insert_index, int *error)
{
	int	arg;

	arg = 0;
	arg = custom_atoi(argv, error);
	if (contains_value_in_stack(stack, insert_index, arg))
		*error = TRUE;
	stack[insert_index] = arg;
}

/**
 * Initializes a t_state structure from command-line arguments.
 *
 * @param argc The number of arguments.
 * @param argv An array of arguments.
 * @param error A pointer to an error flag.
 * @return A pointer to the newly created t_state structure if successful,
	or NULL if an error occurs.
 */
t_state	*init_state_from_args(int argc, char **argv, int *error)
{
	t_state	*state;
	int		i;
	int		insert_index;
	int		*arg_array;

	arg_array = malloc(sizeof(int) * (argc - 1));
	if (!arg_array)
		return (NULL);
	ft_memset(arg_array, 0, sizeof(int) * (argc - 1));
	i = 1;
	insert_index = 0;
	while (argv[i])
	{
		check_argument(argv[i++], arg_array, insert_index++, error);
		if (*error)
			break ;
	}
	index_array(arg_array, (argc - 1));
	state = init_state_from_array(arg_array, (argc - 1));
	free(arg_array);
	return (state);
}

/**
 * Initializes a t_state structure from an integer array.
 *
 * @param arr The integer array.
 * @param arr_size The size of the array.
 * @return A pointer to the newly created t_state structure if successful,
	or NULL if an error occurs.
 */
t_state	*init_state_from_array(int *arr, size_t arr_size)
{
	t_state	*state;

	if (!arr || arr_size == 0)
		return (NULL);
	state = malloc(sizeof(t_state));
	if (!state)
		return (NULL);
	state->mov_list = t_move_init();
	state->stk_a = init_stack_from_array(arr, arr_size);
	state->stk_b = init_empty_stack(arr_size);
	if (!state->mov_list || !state->stk_a || !state->stk_b)
	{
		if (state->mov_list)
			free_t_move(state->mov_list, TRUE);
		if (state->stk_a)
			free_t_stack(state->stk_a, TRUE);
		if (state->stk_b)
			free_t_stack(state->stk_b, TRUE);
		free(state);
		return (NULL);
	}
	return (state);
}
