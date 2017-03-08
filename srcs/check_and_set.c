/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:44:00 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/07 19:11:59 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			set_piece(t_specs *specs)
{
	ft_putnbr(Y);
	ft_putchar(' ');
	ft_putnbr(X);
	ft_putchar('\n');
}

static int		get_enemy_distance(t_specs *specs, int x, int y)
{
	int			a;
	int			b;
	int			len;

	len = 0;
	while (++len)
	{
		b = y - len;
		while (b <= y + len)
		{
			a = x - len;
			while (a <= x + len)
			{
				if (a >= 0 && a < MAP_X && b >= 0 && b < MAP_Y)
					if (MAP[b][a] == ENEMY)
						return (len);
				a++;
			}
			b++;
		}
	}
	return (DISTANCE_MAX);
}

int				check_coordinates(t_specs *specs, int x, int y, int star)
{
	int			a;
	int			b;

	b = -1;
	while (++b < PIECE_Y)
	{
		a = -1;
		while (++a < PIECE_X)
		{
			if ((b >= 0 && a >= 0 && b < PIECE_Y && a < PIECE_X))
			{
				if (PIECE[b][a] == '*')
				{
					if (b + y < 0 || a + x < 0 || b + y >= MAP_Y
							|| a + x >= MAP_X)
						return (0);
					else if (MAP[b + y][a + x] == ME)
						star++;
					else if (MAP[b + y][a + x] == ENEMY)
						return (0);
				}
			}
		}
	}
	return ((star == 1) ? get_enemy_distance(specs, x, y) : 0);
}
