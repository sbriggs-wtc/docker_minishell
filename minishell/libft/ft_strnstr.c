/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 12:56:58 by sbriggs           #+#    #+#             */
/*   Updated: 2018/07/05 15:50:34 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	int		k;

	if (needle[0] == '\0')
		return ((char*)haystack);
	i = 0;
	while (i < (int)len && haystack[i])
	{
		k = i;
		j = 0;
		while (haystack[k] == needle[j] && k < (int)len)
		{
			if (needle[j + 1] == '\0')
				return ((char*)haystack + k - j);
			j++;
			k++;
		}
		i++;
	}
	return (NULL);
}
