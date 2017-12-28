#include "get_next_line.h"

int		ft_error(const int fd, char **line, char **str)
{
	if (fd == -1 || line == NULL)
		return (-1);
	if (!*str)
		if (!(str = (char **)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (-1);
		else
			return (1);
}

char	*ft_join(char *str, const int fd)
{
	int		ret;
	char	*buff;

	if (!(buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (NULL);
	while((ret = read(fd, buff, BUFF_SIZE + 1)) > 0)
	{
		buff[ret] = '\0';
		str = ft_strjoin(str, buff);
	}
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str;
	int			i;

	if(ft_error(fd, line, &str) == -1)
		return (-1);
	if(*str)
		ft_strcpy(*line, str);
	str = ft_join(str, fd);
	i = 0;
	if (str[i])
	{
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (i == 0)
			(*line) = ft_strdup("");
		else
		{
			(*line) = ft_strsub(str, 0, i);
			str = &str[i + 1];
		}
		return (1)
	}
	else
		(*line) = ft_strdup("");
	return (0);
}
