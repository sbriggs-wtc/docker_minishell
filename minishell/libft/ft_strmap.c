/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 08:29:25 by sbriggs           #+#    #+#             */
/*   Updated: 2018/07/01 09:05:04 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		size;
	char	*new_string;

	if (s == NULL)
	{
		return (NULL);
	}
	size = ft_strlen(s);
	new_string = (char *)malloc((size + 1) * sizeof(char));
	if (!(new_string))
	{
		return (NULL);
	}
	i = 0;
	while (s[i] != '\0')
	{
		new_string[i] = f(s[i]);
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
