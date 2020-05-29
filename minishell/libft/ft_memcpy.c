/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:34:40 by sbriggs           #+#    #+#             */
/*   Updated: 2018/06/06 15:19:58 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*str;
	char	*dest;

	i = 0;
	str = (char *)src;
	dest = dst;
	while (n > 0)
	{
		dest[i] = str[i];
		n--;
		i++;
	}
	return (dest);
}
