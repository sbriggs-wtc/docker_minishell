/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:33:38 by sbriggs           #+#    #+#             */
/*   Updated: 2018/06/19 15:47:04 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(const char *s, char c)
{
	int		i;
	int		wc;

	wc = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
		{
			i++;
		}
		while (s[i] != c && s[i])
		{
			i++;
		}
		wc++;
	}
	return (wc);
}

static char	**ft_split(char **an, char const *s, char c)
{
	int		i;
	int		end;
	int		start;

	i = 0;
	end = 0;
	while (s[end])
	{
		while (s[end] == c)
		{
			end++;
		}
		start = end;
		while ((s[end] != c) && s[end])
		{
			end++;
		}
		if (start < end)
		{
			an[i] = ft_strsub(s, start, end - start);
			i++;
		}
	}
	an[i] = NULL;
	return (an);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**an;

	if (s == NULL)
	{
		return (NULL);
	}
	if (!(an = (char **)malloc((ft_word_count(s, c) + 1) * sizeof(char *))))
	{
		return (NULL);
	}
	ft_split(an, s, c);
	return (an);
}
