/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 11:12:15 by sbriggs           #+#    #+#             */
/*   Updated: 2018/06/25 14:34:12 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*pointer_to_char;

	pointer_to_char = (char *)malloc(size * sizeof(char));
	if (!(pointer_to_char))
	{
		return (NULL);
	}
	else
	{
		ft_memset(pointer_to_char, '\0', size);
		return ((void *)pointer_to_char);
	}
}
