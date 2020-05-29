/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 14:52:02 by sbriggs           #+#    #+#             */
/*   Updated: 2018/08/04 11:33:47 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*pointer_to_char;
	size_t	i;

	if (!(pointer_to_char = (char *)malloc((size + 1) * sizeof(char))))
	{
		return (NULL);
	}
	i = 0;
	while (i <= size)
	{
		pointer_to_char[i] = '\0';
		i++;
	}
	return (pointer_to_char);
}
