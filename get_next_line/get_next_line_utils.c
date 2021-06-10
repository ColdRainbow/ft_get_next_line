/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkate <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 04:32:40 by jkate             #+#    #+#             */
/*   Updated: 2020/12/22 19:22:34 by jkate            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_realloc(char **line, long int current_size, long int needed_size)
{
	char		*temp;
	long int	i;

	i = 0;
	if (!(temp = (char *)ft_calloc((current_size + needed_size), 1)))
		return (-1);
	while (i < current_size)
	{
		temp[i] = (*line)[i];
		i++;
	}
	temp[i] = '\0';
	free(*line);
	*line = temp;
	return (1);
}

size_t		ft_strlen(const char *str)
{
	size_t a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

void		*ft_memcpy(void *dest, const void *source, size_t count)
{
	size_t a;

	a = 0;
	if (count == 0 || dest == source)
		return (dest);
	while (a < count)
	{
		((char *)dest)[a] = ((unsigned char *)source)[a];
		a++;
	}
	return (dest);
}

void		*ft_calloc(size_t num, size_t size)
{
	size_t	a;
	char	*res;

	res = (char *)malloc(num * size);
	a = 0;
	if (res == NULL)
		return (NULL);
	while (a < num * size)
	{
		res[a] = 0;
		a++;
	}
	return ((void *)res);
}
