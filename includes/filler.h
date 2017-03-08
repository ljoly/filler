/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:33:09 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/08 12:14:46 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include "mlx.h"

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
# define DISTANCE_MAX specs->distance_enemy_max
# define DISTANCE_ENEMY specs->distance_enemy
# define X specs->answer_x
# define Y specs->answer_y

# define UP_LEFT 0
# define DOWN_RIGHT 1
# define UP_RIGHT 2
# define DOWN_LEFT 3

# define GRAPH 1
# define COLUMNS dsp.columns
# define LINES dsp.lines

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
	int			distance_enemy_max;
	int			distance_enemy;
	int			answer_x;
	int			answer_y;
	void		*mlx;
	void		*win;
}				t_specs;

void			ft_filler(t_specs *specs);
void			get_enemy_last_position(t_specs *specs);
int				get_direction(t_specs *specs);
int				check_coordinates(t_specs *specs, int x, int y, int star);
void			set_piece(t_specs *specs);

/*
** Graph
*/

typedef struct	s_display
{
	int			columns;
	int			lines;
}				t_display;

void			graph(t_specs *specs);

#endif
