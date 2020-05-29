/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbriggs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 15:10:21 by sbriggs           #+#    #+#             */
/*   Updated: 2018/07/11 16:33:08 by sbriggs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		add_line(char **line, char **stat, int fd)
{
	int		i;
	char	*temp;

	i = 0;
	while (stat[fd][i] != '\0')
	{
		if (stat[fd][i] == '\n')
		{
			free(*line);
			*line = ft_strsub(stat[fd], 0, i);
			temp = ft_strdup(&stat[fd][i + 1]);
			if (stat[fd])
				ft_strdel(&stat[fd]);
			stat[fd] = ft_strdup(temp);
			free(temp);
			return (1);
		}
		i++;
	}
	return (0);
}

int		eof(char **stat, int fd, char **line)
{
	free(*line);
	*line = ft_strdup(stat[fd]);
	if (stat[fd])
		ft_strdel(&stat[fd]);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*stat[1];
	int			bytes_read;

	if (fd < 0 || read(fd, buff, 0) < 0 || !line)
		return (-1);
	*line = ft_strnew(0);
	if (stat[fd] == NULL)
		stat[fd] = ft_strnew(0);
	if (add_line(line, stat, fd))
		return (1);
	ft_bzero(buff, BUFF_SIZE + 1);
	while ((bytes_read = read(fd, buff, BUFF_SIZE)) > 0)
	{
		stat[fd] = ft_free_strjoin(stat[fd], buff);
		if (add_line(line, stat, fd))
			return (1);
		ft_bzero(buff, BUFF_SIZE + 1);
	}
	if (ft_strlen(stat[fd]) > 0 && bytes_read == 0)
		return (eof(stat, fd, line));
	return (0);
}
