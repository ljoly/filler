/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:44:49 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/05 18:33:31 by ljoly            ###   ########.fr       */
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

static void		get_piece(t_specs *specs, char *line)
{
	char		*tmp;
	int			i;
//	int			a;

	get_next_line(0, &line); // PIECE FIRST LINE
	PIECE_Y = ft_atoi(&line[6]);
	PIECE = ft_memalloc(sizeof(char*) * (PIECE_Y + 1));
	tmp = line + 6;
	while (ft_isdigit(*tmp))
		tmp++;
	tmp++;
	PIECE_X = ft_atoi(tmp);
	i = 0;
	while (i < PIECE_Y)
	{
		get_next_line(0, &line);
		PIECE[i] = ft_strdup(line);
		i++;
	}
/*	ft_putstr_fd("PIECE :\n", 2);
	a = 0;
	while (a < PIECE_Y)
	{
		ft_putendl_fd(PIECE[a], 2);
		a++;
	}*/
}

static void		get_map(t_specs *specs)
{
	char		*line;
	int			i;
//	int			a;

	if (!MAP)
		MAP = ft_memalloc(sizeof(char*) * (MAP_Y + 1));
	get_next_line(0, &line); // PLATEAU FIRST LINE (DIGIT)
	i = 0;
	while (i < MAP_Y)
	{
		get_next_line(0, &line); // MAP FIRST LINE
		if (ft_isdigit(line[0]))
		{
			line += 4;
			MAP[i] = ft_strdup(line);
		}
		i++;
	}
/*	ft_putstr_fd("MAP :\n", 2);
	a = 0;
	while (MAP[a])
	{
		ft_putendl_fd(MAP[a], 2);
		a++;
	}*/
	get_piece(specs, line);
	if (ENEMY_X == 0 && ENEMY_Y == 0 && ME_X == 0 && ME_Y == 0)
		get_initial_positions(specs);
}

static int		ft_end(__unused char *line, t_specs *specs)
{
//	free(line);
	if (THE_END)
	{
//		free(MAP);
//		free(PIECE);
//		free(specs);
		return (1);
	}
	return (0);
}

void			ft_filler(char *line, t_specs *specs)
{
	if (get_next_line(0, &line) > 0) // GET PLAYER NUMBER
	{
		ME = (ft_atoi(line + 10) == 1) ? 'O' : 'X';
		ENEMY = (ME == 'O') ? 'X' : 'O';
		while (1)
		{
			if (get_next_line(0, &line) > 0) // GET PLATEAU SIZE
			{
				if (!MAP_X && !MAP_Y)
				{
					MAP_X = ft_atoi(line + 11);
					MAP_Y = ft_atoi(line + 8);
				}
				get_map(specs);
				if (!get_direction(specs))
					NO_SPACE = 1;
				set_piece(specs);
				if (ft_end(line, specs))
				{
					ft_putstr_fd("THE END\n", 2);
					return ;
				}
			}
		}
	}
}
