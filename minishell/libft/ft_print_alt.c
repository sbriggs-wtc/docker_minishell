/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 14:25:51 by sbriggs           #+#    #+#             */
/*   Updated: 2018/07/22 14:48:39 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define HEX 0
#define OCT 1
#define UPPER 2
#define LOWER 3

void	ft_print_alt(char *s, int base, int cas)
{
	if (base == OCT)
		ft_putchar('0');
	else
	{
		if (cas == 2)
			ft_putstr("0X");
		else
			ft_putstr("0x");
	}
	ft_putstr(s);
}
