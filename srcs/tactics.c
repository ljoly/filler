/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tactics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 13:18:52 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/05 20:58:55 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int		go_down_left(t_specs *specs)
{
	int		x;
	int		y;

	y = MAP_Y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < MAP_X)
		{
			if (check_coordinates(specs, x, y) == 1)
			{
				X = x;
				Y = y;
				return (1);
			}
			x++;
		}
		y--;
	}
	return (0);
}

static int		go_up_right(t_specs *specs)
{
	int		x;
	int		y;

	y = 0;
	while (y < MAP_Y)
	{
		x = MAP_X - 1;
		while (x >= 0)
		{
			if (check_coordinates(specs, x, y) == 1)
			{
				X = x;
				Y = y;
				return (1);
			}
			x--;
		}
		y++;
	}
	return (0);
}

static int		go_down_right(t_specs *specs)
{
	int		x;
	int		y;

	y = MAP_Y - 1;
	while (y >= 0)
	{
		x = MAP_X - 1;
		while (x >= 0)
		{
			if (check_coordinates(specs, x, y) == 1)
			{
				X = x;
				Y = y;
				return (1);
			}
			x--;
		}
		y--;
	}
	return (0);
}

static int		go_up_left(t_specs *specs)
{
	int		x;
	int		y;

	y = 0;
	while (y < MAP_Y)
	{
		x = 0;
		while (x < MAP_X)
		{
			if (check_coordinates(specs, x, y) == 1)
			{
				X = x;
				Y = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int				get_direction(t_specs *specs)
{
	if (DIRECTION == UP_LEFT)
		return (go_up_left(specs));
	else if (DIRECTION == DOWN_RIGHT)
		return (go_down_right(specs));
	else if (DIRECTION == UP_RIGHT)
		return (go_up_right(specs));
	else if (DIRECTION == DOWN_LEFT)
		return (go_down_left(specs));
	return (0);
}
