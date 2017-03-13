/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoly <ljoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:14:35 by ljoly             #+#    #+#             */
/*   Updated: 2017/03/10 12:01:54 by ljoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_abs(ssize_t nb)
{
	nb < 0 ? nb *= -1 : nb;
	return (nb);
}
