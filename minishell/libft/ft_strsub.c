/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 15:36:41 by sbriggs           #+#    #+#             */
/*   Updated: 2018/06/28 18:25:45 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_string;
	size_t	i;
	size_t	j;

	if (s == NULL)
	{
		return (NULL);
	}
	new_string = (char *)malloc((len + 1) * sizeof(char));
	if (!(new_string))
	{
		return (NULL);
	}
	i = start;
	j = 0;
	while (len > 0)
	{
		new_string[j] = s[i];
		i++;
		j++;
		len--;
	}
	new_string[j] = '\0';
	return (new_string);
}
