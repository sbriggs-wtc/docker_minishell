/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:00:31 by sbriggs           #+#    #+#             */
/*   Updated: 2018/06/22 10:06:08 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int		i;
	int		j;
	char	*s;

	s = (char *)src;
	i = 0;
	while ((int)len > 0)
	{
		if (s[i] == '\0')
		{
			j = i;
			while (len > 0)
			{
				dst[j] = '\0';
				j++;
				len--;
			}
			return (dst);
		}
		dst[i] = s[i];
		i++;
		len--;
	}
	return (dst);
}
