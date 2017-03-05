/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 17:57:46 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/05 20:53:21 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void				set_piece(t_specs *specs)
{
	if (DIRECTION == UP_LEFT)
		DIRECTION = DOWN_LEFT;
	else if (DIRECTION == DOWN_RIGHT)
		DIRECTION = UP_RIGHT;
	else if (DIRECTION == UP_RIGHT)
		DIRECTION = DOWN_RIGHT;
	else if (DIRECTION == DOWN_LEFT)
		DIRECTION = UP_LEFT;
	if (NO_SPACE)
	{
		THE_END = 1;
		ft_putnbr(Y);
		ft_putchar(' ');
		ft_putnbr(X);
		ft_putchar('\n');
	}
	else
	{
		ft_putnbr(Y);
		ft_putchar(' ');
		ft_putnbr(X);
		ft_putchar('\n');
	}
}
