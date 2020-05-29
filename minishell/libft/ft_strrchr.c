/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 07:24:12 by sbriggs           #+#    #+#             */
/*   Updated: 2018/06/06 07:54:05 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str_in;

	str_in = (char *)s;
	i = 0;
	while (str_in[i] != '\0')
	{
		i++;
	}
	if (c == '\0')
	{
		return (&str_in[i]);
	}
	while (i >= 0)
	{
		if (str_in[i] == c)
		{
			return (&str_in[i]);
		}
		i--;
	}
	return (NULL);
}
