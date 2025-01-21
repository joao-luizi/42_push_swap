/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_move.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:41:22 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:48:03 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MOVE_H
# define T_MOVE_H

typedef struct s_move
{
	char	*mov;
	size_t	len;
}			t_move;

typedef enum e_move_type
{
	NO_MOVE,
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}			t_move_type;

void		print_moves(t_move *moves);
void		merge_list(t_move *result, t_move *move_a, t_move *move_b);
int			register_move(t_move *destiny, char c);

t_move_type	get_mirror_move(t_move_type move);
t_move_type	get_dual_move(t_move_type move);
t_move_type	get_move_type(char *str);
char		*operation_name(t_move_type move);

void		free_t_move(t_move *moves, int self_dispose);
t_move		*t_move_init(void);
#endif
