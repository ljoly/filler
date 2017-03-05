/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coordinates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 17:57:29 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/05 20:53:18 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int				check_coordinates(t_specs *specs, int x, int y)
{
	int			a;
	int			b;
	int			star;

	if ( PIECE_X + x > MAP_X || PIECE_Y + y > MAP_Y)
		return (0);
	star = 0;
	b = 0;
	while (b < PIECE_Y)
	{
		a = 0;
		while (a < PIECE_X)
		{
			if ((MAP[b + y][a + x] == ME) && PIECE[b][a] == '*')
				star++;
			if ((MAP[b + y][a + x] == ENEMY) && PIECE[b][a] == '*')
				return (0);
			a++;
		}
		b++;
	}
	return ((star == 1) ? 1 : 0);
}
