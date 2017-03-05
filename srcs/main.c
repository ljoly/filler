/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:35:42 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/03 14:35:22 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int		ft_malloc_error(void)
{
	ft_putendl_fd("Failed to allocate memory for struct.", 2);
	return (-1);
}

int				main(void)
{
	char		*line;
	t_specs		*specs;

	if (!(specs = ft_memalloc(sizeof(t_specs))))
		return (ft_malloc_error());
	line = NULL;
	ft_filler(line, specs);
	return (0);
}
