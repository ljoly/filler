/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:35:42 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/08 13:29:29 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int		malloc_error(void)
{
	ft_putendl_fd("Failed to allocate memory for struct.", 2);
	return (-1);
}

int				main(void)
{
	t_specs		*specs;

	if (!(specs = ft_memalloc(sizeof(t_specs))))
		return (malloc_error());
	if (GRAPH)
	{
		specs->mlx = mlx_init();
		specs->win = mlx_new_window(specs->mlx, 1080, 1080, "filler");
		mlx_do_sync(specs->mlx);
	}
	ft_filler(specs);
	return (0);
}
