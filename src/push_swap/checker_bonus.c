/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:37:37 by joaomigu          #+#    #+#             */
/*   Updated: 2024/10/07 14:30:19 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/checker.h"

/**
 * Prints an error message to standard error and terminates the program.
 *
 * This function writes the message "Error\n" to standard 
 * error, indicating an error
 * condition. After printing the message, the program is 
 * terminated.
 */
void	exit_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
}

/**
 * Reads input from stdout and performs the identified move.
 *
 * This function continuously reads lines from standard 
 * input and attempts to
 * identify the move type. If a valid move is recognized,
 * it is performed on the
 * given state. If no valid move is found, an error 
 * message is printed and the program
 * terminates.
 *
 * @param state The current state of the sorting process.
 */
void	read_input(t_state *state)
{
	t_move_type	current_move;
	char		*input;

	input = NULL;
	while (1)
	{
		input = get_next_line(0);
		if (input == NULL)
			break ;
		else
		{
			current_move = get_move_type(input);
			if (!current_move)
			{
				exit_error();
				break ;
			}
			perform_move(state, current_move);
		}
		free(input);
	}
	if (input)
		free(input);
}

/**
 * Main entry point for the checker program.
 *
 * This function verifies the moves performed on 
 * a set of integers and determines
 * whether the resulting state is sorted.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments.
 *
 * @return 0 if the program completes successfully.
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
	read_input(state);
	if (is_state_sorted(state))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_t_state(state, TRUE);
	return (0);
}
