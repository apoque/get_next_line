/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:28:49 by apoque            #+#    #+#             */
/*   Updated: 2017/12/04 13:41:08 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	const char	*str;
	size_t		i;

	str = (const char *)s;
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	size = (int)ft_strlen(s1) + (int)ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[size] = '\0';
	return (&str[0]);
}

static int	ft_get_len(const	int fd, char **line)
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
	ft_get_len(fd, line);
}
