/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 13:22:38 by sbriggs           #+#    #+#             */
/*   Updated: 2018/07/05 16:00:25 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_sign(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

static int		ft_check_max_min(unsigned long long total, int sign)
{
	if ((sign == -1) && (total > 9223372036854775807))
		return (0);
	if (total >= 9223372036854775807)
		return (-1);
	return (total * sign);
}

static int		pre(const char *str)
{
	int i;

	i = 0;
	while (ft_isdigit((char)str[i]) == 0 && (char)str[i] != '\0')
	{
		if (!ft_isempty(str[i]))
		{
			if ((char)str[i] == '-' || ((char)str[i] == '+'))
			{
				if (ft_isdigit((char)str[i + 1]) == 0)
					return (-1);
			}
			else
				return (-1);
		}
		i++;
	}
	return (i);
}

int				ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	number;
	unsigned long long	total;
	int					i;

	total = 0;
	i = pre(str);
	if (i < 0)
		return (0);
	sign = ft_check_sign(str[i - 1]);
	while (ft_isdigit(str[i]) == 1 && (str[i] != '\0'))
	{
		total = total * 10;
		number = (char)str[i] - '0';
		total = total + number;
		i++;
	}
	return (ft_check_max_min(total, sign));
}
