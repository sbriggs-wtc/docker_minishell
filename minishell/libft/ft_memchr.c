/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:23:34 by sbriggs           #+#    #+#             */
/*   Updated: 2018/06/24 15:31:30 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;
	unsigned char	character;
	size_t			i;

	string = (unsigned char *)s;
	character = (unsigned char)c;
	i = 0;
	while ((int)n > 0)
	{
		if (string[i] == character)
		{
			return (&string[i]);
		}
		i++;
		n--;
	}
	return (NULL);
}
