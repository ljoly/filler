/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:25:06 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/13 18:47:05 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		display_im(t_specs *specs, t_display dsp, int *im_ad, int color)
{
	int			x;
	int			y;

	y = 0;
	while (y < 720 / MAP_Y && y + LINES < 720)
	{
		x = 0;
		while (x < 720 / MAP_X && x + COLUMNS < 720 && y * x < 720 * 720)
		{
			im_ad[((y + LINES) * 720) + (x + COLUMNS)] = color;
			x++;
		}
		y++;
	}
}

static void		display(t_specs *specs, int *im_ad)
{
	int			x;
	int			y;
	t_display	dsp;

	LINES = 0;
	y = 0;
	while (y >= 0 && y < MAP_Y)
	{
		COLUMNS = 0;
		x = 0;
		while (x >= 0 && x < MAP_X)
		{
			if (MAP[y][x] == ME)
				display_im(specs, dsp, im_ad, 0x11A511);
			else if (MAP[y][x] == ENEMY)
				display_im(specs, dsp, im_ad, 0xAF0E0E);
			else
				display_im(specs, dsp, im_ad, 0x000000);
			COLUMNS += 720 / MAP_X;
			x++;
		}
		LINES += 720 / MAP_Y;
		y++;
	}
}

void			graph(t_specs *specs)
{
	int			bits;
	int			size;
	int			end;
	void		*image;
	int			*im_ad;

	bits = 24;
	size = 720;
	end = 0;
	image = mlx_new_image(specs->mlx, 720, 720);
	im_ad = (int*)mlx_get_data_addr(image, &bits, &size, &end);
	display(specs, im_ad);
	mlx_put_image_to_window(specs->mlx, specs->win, image, 0, 0);
	mlx_do_sync(specs->mlx);
}
