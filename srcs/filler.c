/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:44:49 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/08 14:06:33 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		get_initial_positions(t_specs *specs)
{
	int			x;
	int			y;

	y = 0;
	while (MAP[y])
	{
		x = 0;
		while (MAP[y][x])
		{
			if (MAP[y][x] == ENEMY)
			{
				ENEMY_X = x;
				ENEMY_Y = y;
			}
			else if (MAP[y][x] == ME)
			{
				ME_X = x;
				ME_Y = y;
			}
			x++;
		}
		y++;
	}
	if (ENEMY_Y > ME_Y)
		DIRECTION = DOWN_RIGHT;
}

static void		get_piece(t_specs *specs)
{
	char		*line;
	int			i;

	get_next_line(0, &line);
	i = 6;
	PIECE_Y = ft_atoi(&line[i]);
	PIECE = ft_memalloc(sizeof(char*) * (PIECE_Y + 1));
	while (ft_isdigit(line[i]))
		i++;
	i++;
	PIECE_X = ft_atoi(&line[i]);
	free(line);
	i = 0;
	while (i < PIECE_Y)
	{
		get_next_line(0, &line);
		PIECE[i] = ft_strdup(line);
		free(line);
		i++;
	}
}

static void		get_map(t_specs *specs)
{
	char		*line;
	int			i;

	MAP = ft_memalloc(sizeof(char*) * (MAP_Y + 1));
	get_next_line(0, &line);
	free(line);
	i = 0;
	while (i < MAP_Y)
	{
		get_next_line(0, &line);
		MAP[i] = ft_strdup(line + 4);
		free(line);
		i++;
	}
	get_piece(specs);
	if (ENEMY_X == 0 && ENEMY_Y == 0 && ME_X == 0 && ME_Y == 0)
		get_initial_positions(specs);
}

static int		ft_end(t_specs *specs)
{
	int			i;

	i = 0;
	while (i < PIECE_Y)
	{
		free(PIECE[i]);
		PIECE[i] = NULL;
		i++;
	}
	i = 0;
	while (i < MAP_Y)
	{
		free(MAP[i]);
		MAP[i] = NULL;
		i++;
	}
	free(PIECE);
	free(MAP);
	if (NO_SPACE)
	{
		free(specs);
		return (1);
	}
	return (0);
}

void			ft_filler(t_specs *specs)
{
	char		*line;

	if (get_next_line(0, &line) > 0)
	{
		ME = (ft_atoi(line + 10) == 1) ? 'O' : 'X';
		ENEMY = (ME == 'O') ? 'X' : 'O';
		free(line);
		while (get_next_line(0, &line) > 0)
		{
			if (!MAP_X && !MAP_Y)
			{
				MAP_X = ft_atoi(line + 11);
				MAP_Y = ft_atoi(line + 8);
			}
			free(line);
			get_map(specs);
			if (!get_direction(specs))
				NO_SPACE = 1;
			set_piece(specs);
			if (GRAPH)
				graph(specs);
			if (ft_end(specs))
				break ;
		}
	}
}
