/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 11:54:01 by sbriggs           #+#    #+#             */
/*   Updated: 2018/06/06 15:53:34 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	size_t	j;

	j = n - 1;
	i = 0;
	if (s1 == NULL || s2 == NULL || n == 0)
	{
		return (1);
	}
	while (s1[i] == s2[i])
	{
		if (((s1[i] == '\0') && (s2[i] == '\0')) || ((s1[i] == s2[i]) && (i == j)))
		{
			return (1);
		}
		else
		{
			i++;
		}
	}
	return (0);
}