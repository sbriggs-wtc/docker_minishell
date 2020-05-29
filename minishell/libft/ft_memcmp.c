/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 14:23:45 by sbriggs           #+#    #+#             */
/*   Updated: 2018/06/22 09:52:33 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_char;
	unsigned char	*s2_char;

	s1_char = (unsigned char *)s1;
	s2_char = (unsigned char *)s2;
	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (n > 0)
	{
		if (s1_char[i] != s2_char[i])
		{
			return (s1_char[i] - s2_char[i]);
		}
		n--;
		i++;
	}
	return (0);
}
