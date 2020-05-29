/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 15:06:17 by sbriggs           #+#    #+#             */
/*   Updated: 2018/08/04 16:09:56 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

static int		ft_measure(long dup, int base, int l)
{
	while (dup > 0)
	{
		dup /= base;
		l++;
	}
	return (l);
}

char			*ft_itoa_base(int n, int base)
{
	char		*tab;
	char		*s;
	long		dup;
	int			l;

	tab = (char *)malloc(17 * sizeof(char));
	ft_bzero(tab, 17);
	tab = "0123456789ABCDEF";
	l = 0;
	dup = n;
	l = (base == 10 && dup < 0) ? 1 : 0;
	dup = (dup < 0) ? -dup : dup;
	l = ft_measure(dup, base, l);
	s = (char *)malloc((l) * sizeof(char));
	bzero(s, l);
	dup = n;
	dup = (dup < 0) ? -dup : dup;
	while (l-- >= 0)
	{
		*(s + l) = *(tab + (dup % base));
		dup /= base;
	}
	s[0] = (n < 0 && base == 10) ? '-' : s[0];
	return (s);
}
