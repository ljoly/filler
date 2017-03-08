/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tactics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 13:18:52 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/08 11:42:54 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int		go_down_right(t_specs *specs)
{
	int		x;
	int		y;
	int		ret;

	y = MAP_Y + PIECE_Y;
	while (y > -PIECE_Y)
	{
		x = MAP_X + PIECE_X;
		while (x > -PIECE_X)
		{
			if ((ret = check_coordinates(specs, x, y, 0)))
			{
				if (ret < DISTANCE_ENEMY)
				{
					DISTANCE_ENEMY = ret;
					X = x;
					Y = y;
				}
			}
			x--;
		}
		y--;
	}
	return ((DISTANCE_ENEMY < DISTANCE_MAX) ? 1 : 0);
}

static int		go_up_left(t_specs *specs)
{
	int		x;
	int		y;
	int		ret;

	y = -PIECE_Y;
	while (y < MAP_Y)
	{
		x = -PIECE_X;
		while (x < MAP_X)
		{
			if ((ret = check_coordinates(specs, x, y, 0)))
			{
				if (ret < DISTANCE_ENEMY)
				{
					DISTANCE_ENEMY = ret;
					X = x;
					Y = y;
				}
			}
			x++;
		}
		y++;
	}
	return ((DISTANCE_ENEMY < DISTANCE_MAX) ? 1 : 0);
}

int				get_direction(t_specs *specs)
{
	DISTANCE_MAX = (MAP_X > MAP_Y ? MAP_X : MAP_Y);
	DISTANCE_ENEMY = DISTANCE_MAX;
	if (DIRECTION == UP_LEFT)
		return (go_up_left(specs));
	else if (DIRECTION == DOWN_RIGHT)
		return (go_down_right(specs));
	return (0);
}
