/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:37:37 by joaomigu          #+#    #+#             */
/*   Updated: 2024/10/07 14:28:21 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Prints an error message to standard error and 
 * terminates the program.
 *
 * This function writes the message "Error\n" to 
 * standard error, indicating an error
 * condition. After printing the message, the program
 *  is terminated.
 */
void	exit_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
}

/**
 * Main entry point for the sorting program.
 *
 * This function sorts a set of integers using the 
 * specified algorithm and prints
 * the sequence of moves required to achieve the sorted
 *  state.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments.
 *
 * @return 0 if the program completes successfully, or 
 * a non-zero value if an error occurs.
 */
int	main(int argc, char **argv)
{
	int		error;
	t_state	*state;
	char	**temp_arg;

	if (argc < 2)
		return (0);
	error = FALSE;
	temp_arg = parse_command_line_arguments(&argc, argv, ' ');
	if (!temp_arg)
		return (0);
	state = init_state_from_args(argc, temp_arg, &error);
	free_args(temp_arg);
	if (error)
	{
		free_t_state(state, TRUE);
		exit_error();
		return (0);
	}
	if (!is_state_sorted(state))
	{
		sort(state);
		print_moves(state->mov_list);
	}
	free_t_state(state, TRUE);
	return (0);
}
