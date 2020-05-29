/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_padding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 14:04:36 by sbriggs           #+#    #+#             */
/*   Updated: 2018/07/22 14:36:49 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define RIGHT 0
#define LEFT 1
#define ZERO 2

void	ft_print_padding(char *s, int width, int side, int fill)
{
	size_t		padding;

	padding = width - ft_strlen(s);
	if (padding > ft_strlen(s))
	{
		if (side == 1)
			ft_putstr(s);
		while (padding > 0)
		{
			if (fill == 2)
				ft_putchar('0');
			else
				ft_putchar(' ');
			padding--;
		}
		if (side == 0)
			ft_putstr(s);
	}
}
