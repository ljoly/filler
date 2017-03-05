/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:33:09 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/05 20:49:22 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <stdio.h>

#ifndef FILLER_H
# define FILLER_H

# define ME specs->letter_me
# define ENEMY specs->letter_enemy
# define MAP_X specs->map_columns
# define MAP_Y specs->map_lines
# define MAP specs->map
# define PIECE_X specs->piece_columns
# define PIECE_Y specs->piece_lines
# define PIECE specs->piece
# define ENEMY_X specs->enemy_x
# define ENEMY_Y specs->enemy_y
# define ME_X specs->me_x
# define ME_Y specs->me_y
# define NO_SPACE specs->no_space
# define DIRECTION specs->direction
# define THE_END specs->the_end
# define X specs->answer_x
# define Y specs->answer_y

# define UP_LEFT 0
# define DOWN_RIGHT 1
# define UP_RIGHT 2
# define DOWN_LEFT 3

typedef struct	s_specs
{
	char		letter_me;
	char		letter_enemy;
	int			map_columns;
	int			map_lines;
	char		**map;
	int			piece_columns;
	int			piece_lines;
	char		**piece;
	int			enemy_x;
	int			enemy_y;
	int			me_x;
	int			me_y;
	int			no_space;
	int			direction;
	int			the_end;
	int			answer_x;
	int			answer_y;
}				t_specs;

void			ft_filler(char *line, t_specs *specs);
int				get_direction(t_specs *specs);
int				check_coordinates(t_specs *specs, int x, int y);
void			set_piece(t_specs *specs);

#endif
