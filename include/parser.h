/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomigu <joaomigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:41:15 by joaomigu          #+#    #+#             */
/*   Updated: 2024/10/07 14:37:29 by joaomigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

int		custom_atoi(char *str, int *error);
char	**parse_command_line_arguments(int *argc, char **argv, char separator);
char	*join_strings_with_separator(int start_index,
			char **argv, char separator);
void	free_args(char **str);

#endif
