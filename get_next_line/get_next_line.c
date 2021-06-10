/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkate <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:52:58 by jkate             #+#    #+#             */
/*   Updated: 2020/12/22 19:20:07 by jkate            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "get_next_line.h"

static int	work_with_buff(char **line, char **buf, size_t i, size_t *bytes)
{
	char	*temp_buf;

	temp_buf = NULL;
	if (!(*line = (char *)ft_calloc((i + 1), 1)))
		return (-1);
	ft_memcpy(*line, *buf, i);
	if ((*buf + i + 1))
	{
		*bytes = ft_strlen(*buf + i + 1);
		if (!(temp_buf = (char *)ft_calloc(*bytes + 1, 1)))
			return (-1);
		ft_memcpy(temp_buf, *buf + i + 1, *bytes);
		free(*buf);
		*buf = temp_buf;
	}
	return (1);
}

static int	reading(int fd, char **buf, size_t *bytes)
{
	ssize_t		count;

	if ((ft_realloc(buf, *bytes, BUFFER_SIZE + 1)) < 0)
		return (-1);
	if ((count = read(fd, *buf + *bytes, BUFFER_SIZE)) < 0)
		return (-1);
	*bytes += count;
	(*buf)[*bytes] = '\0';
	return (0);
}

int			work_end_of_file(char **buf, char **line, size_t *bytes, size_t i)
{
	if (!(*line = (char *)ft_calloc(i + 1, 1)))
		return (-1);
	ft_memcpy(*line, *buf, i);
	*bytes = 0;
	free(*buf);
	*buf = NULL;
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char		*buf = NULL;
	static size_t	bytes = 0;
	size_t			i;

	*line = NULL;
	i = 0;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while (1)
	{
		if (!(i % BUFFER_SIZE))
		{
			if ((reading(fd, &buf, &bytes)) < 0)
				return (-1);
		}
		if (buf[i] == '\n')
			return (work_with_buff(line, &buf, i, &bytes));
		else if (buf[i] == '\0')
			return (work_end_of_file(&buf, line, &bytes, i));
		i++;
	}
}
