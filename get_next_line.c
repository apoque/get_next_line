/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:28:49 by apoque            #+#    #+#             */
/*   Updated: 2017/11/22 13:46:34 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_get_len(const int fd, char **line)
{
	int		i;
	char	*buf2;

	i = 0;
	buf2 = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	read(fd, buf2, BUFF_SIZE);
	buf2[BUFF_SIZE] = '\0';
	*line = ft_strjoin(*line, buf2);
	while (*line[i] != '\n' && *line[i] != '\0')
		i++;
	if (*line[i] == '\0')
	{
		ft_get_len(fd, line);
	}
	while (*line[i] != '\0')
	{
		*line[i] = '\0';
		i++;
	}
}

int			get_next_line(const int fd, char **line)
{
	*line = "";
	ft_get_len(fd, **line);
}
