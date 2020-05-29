/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:35:53 by sbriggs           #+#    #+#             */
/*   Updated: 2018/06/09 12:56:49 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*hays;
	char	*need;
	int		i;
	int		j;
	int		k;

	hays = (char *)haystack;
	need = (char *)needle;
	if (need[0] == '\0')
		return (hays);
	i = 0;
	while (hays[i] != '\0')
	{
		k = i;
		j = 0;
		while (hays[k] == need[j])
		{
			if (need[j + 1] == '\0')
				return (&hays[k - j]);
			k++;
			j++;
		}
		i++;
	}
	return (NULL);
}
