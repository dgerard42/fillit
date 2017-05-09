/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfill.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 11:36:03 by dgerard           #+#    #+#             */
/*   Updated: 2017/05/09 11:42:56 by dgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFILL_H
# define LIBFILL_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>

int				**translator(char *file, int tetrominoes);
int				file_checker(char *filename);
bool			solver(char **board, int *board_size, int **pieces);
void			remove_piece(char **board);
void			add_piece(char **board, int *piece, int *place);
bool			check_piece(char **board, int size, int *piece, int *place);
void			display_board(char **board, int board_size);
char			check_alpha(char **board);

#endif
