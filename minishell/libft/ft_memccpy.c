/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:27:52 by sbriggs           #+#    #+#             */
/*   Updated: 2018/07/01 09:53:00 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*str_src;
	unsigned char	*str_dst;

	str_src = (unsigned char *)src;
	str_dst = (unsigned char *)dst;
	i = 0;
	if (n == 0)
	{
		return (NULL);
	}
	while (i < n)
	{
		str_dst[i] = str_src[i];
		if (str_dst[i] == (unsigned char)c)
		{
			return (str_dst + (i + 1));
		}
		i++;
	}
	return (NULL);
}
