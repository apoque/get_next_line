/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 13:51:55 by apoque            #+#    #+#             */
/*   Updated: 2018/01/12 19:21:17 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_error(const int fd, char **line)
{
	if (fd < 0 || fd > OPEN_MAX || line == NULL || BUFF_SIZE <= 0
			|| (read(fd, NULL, 0) == -1))
		return (-1);
	else
		return (1);
}

char	*ft_join(char *str, const int fd)
{
	int		ret;
	char	*tmp;
	char	buff[BUFF_SIZE + 1];

	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (NULL);
		buff[ret] = '\0';
		tmp = ft_strdup(str);
		if (str)
			free(str);
		str = ft_strjoin(tmp, buff);
		if (tmp)
			free(tmp);
	}
	return (str);
}

char	*ft_move_on_fd(char *str, int i)
{
	char	*tmp;

	tmp = ft_strdup(str);
	free(str);
	str = ft_strdup(tmp + i);
	free(tmp);
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[OPEN_MAX];
	int			i;

	if (ft_error(fd, line) == -1)
		return (-1);
	if ((str[fd] = ft_join(str[fd], fd)) == NULL)
		return (-1);
	i = 0;
	if (str[fd][i])
	{
		while (str[fd][i] != '\n' && str[fd][i] != '\0')
			i++;
		if (i == 0)
			(*line) = ft_strdup("");
		else
		{
			(*line) = ft_strsub(str[fd], 0, i);
			str[fd] = ft_move_on_fd(str[fd], i);
		}
		if (*str[fd] == '\n')
			str[fd] = ft_move_on_fd(str[fd], 1);
		return (1);
	}
	(*line) = ft_strdup("");
	return (0);
}
