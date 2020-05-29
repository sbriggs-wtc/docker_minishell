/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 15:24:29 by sbriggs           #+#    #+#             */
/*   Updated: 2018/07/01 09:42:38 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_dec_places(int n)
{
	int		i;

	i = 0;
	if (n == 0)
	{
		i++;
	}
	else if (n < 0)
	{
		n = n * -1;
		i = 0;
		while (n > 0)
		{
			n = n / 10;
			i++;
		}
		return (i + 1);
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_do_itoa(int n, char *number)
{
	int		sign;
	int		len;

	len = ft_count_dec_places(n);
	sign = 1;
	if (n == 0)
	{
		number[0] = '0';
	}
	else if (n < 0)
	{
		sign = -1;
		n = n * -1;
	}
	number[len] = '\0';
	len--;
	while (n > 0)
	{
		number[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	if (sign == -1)
		number[len] = '-';
	return (number);
}

char		*ft_itoa(int n)
{
	char	*number;

	if (n == -2147483648)
	{
		return (ft_strdup("-2147483648"));
	}
	number = ft_strnew(ft_count_dec_places(n));
	if (!number)
		return (NULL);
	return (ft_do_itoa(n, number));
}
