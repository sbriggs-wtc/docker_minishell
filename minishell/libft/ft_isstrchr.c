/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstrchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 16:44:12 by sbriggs           #+#    #+#             */
/*   Updated: 2018/07/17 16:47:35 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int		ft_isstrchr(const char *s, int c)
{
	int		i;
	char	*str_in;

	str_in = (char *)s;
	i = 0;
	while (str_in[i] != '\0')
	{
		if (c == str_in[i])
		{
			return (1);
		}
		else
		{
			i++;
		}
	}
	if (c == '\0')
	{
		return (1);
	}
	return (0);
}
