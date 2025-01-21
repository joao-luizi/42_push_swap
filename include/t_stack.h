/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:41:31 by joaomigu          #+#    #+#             */
/*   Updated: 2024/09/30 17:48:56 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_STACK_H
# define T_STACK_H

typedef struct s_stack
{
	int		*arr;
	size_t	len;
}			t_stack;

typedef enum e_stack_type
{
	STACK_A,
	STACK_B
}			t_stack_type;

typedef enum e_sort_order
{
	ASCENDING,
	DESCENDING
}			t_sort_order;

void		free_t_stack(t_stack *stack, int self_dispose);

t_stack		*init_stack_from_array(int *arr, size_t arr_size);
t_stack		*init_empty_stack(size_t maxsize);

int			is_stack_sorted(t_stack *stack, t_sort_order order);
void		print_stack(t_stack *stack);
char		*stack_type_to_string(t_stack_type stk_type);

int			swap(t_stack *stack);
int			rot(t_stack *stack);
int			rrot(t_stack *stack);
int			push(t_stack *source, t_stack *destiny);

#endif
