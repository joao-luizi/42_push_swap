/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_move_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:38:26 by joaomigu          #+#    #+#             */
/*   Updated: 2024/10/05 14:58:09 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * Prints the moves in a given move list.
 *
 * Outputs the string representation of each move in the list to the console.
 *
 * @param moves Pointer to the move list to print.
 */
void	print_moves(t_move *moves)
{
	size_t	i;

	if (!moves || moves->len == 0)
		return ;
	i = 0;
	while (i < moves->len)
	{
		ft_printf("%s\n", operation_name(moves->mov[i]));
		i++;
	}
}

/**
 * Prints the moves in a move list and the total count of moves.
 *
 * This function displays the names of each move in the list and the total number
 * of moves.
 *
 * @param moves The move list to print.
 */
void	print_moves_count(t_move *moves)
{
	size_t	i;

	if (!moves || moves->len == 0)
	{
		ft_printf("Move list is empty.\n");
		return ;
	}
	i = 0;
	while (i < moves->len)
	{
		ft_printf("%s\n", operation_name(moves->mov[i]));
		i++;
	}
	ft_printf("\nCount %d\n", moves->len);
}

/**
 * Registers a move in a move list.
 *
 * This function appends the given move character to the `destiny` move list and
 * increments the length of the list.
 *
 * @param destiny The move list to register the move in.
 * @param c The move character to register.
 *
 * @return TRUE if the registration was successful, FALSE otherwise.
 */
int	register_move(t_move *destiny, char c)
{
	if (!destiny)
		return (FALSE);
	destiny->mov[destiny->len] = c;
	destiny->len++;
	return (TRUE);
}
