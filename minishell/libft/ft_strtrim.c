/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 10:13:23 by sbriggs           #+#    #+#             */
/*   Updated: 2018/07/05 15:24:59 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	size_t	i;
	size_t	l;

	if (s == NULL)
		return (ft_strdup(""));
	l = ft_strlen((char *)s);
	if (l == 0)
		return (ft_strdup(""));
	l--;
	while (ft_isempty((char)s[l]) == 1)
	{
		if (l == 0)
			return (ft_strdup(""));
		l--;
	}
	i = 0;
	while (ft_isempty((char)s[i]) == 1)
		i++;
	/* new = (char *)malloc((l - i + 1) * sizeof(char));
	if (!new)
		return (NULL); */
	if((new = ft_strsub((char *)s, i, l - i + 1)))
	    return (new);
    else
        return (NULL);
}
