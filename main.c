#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int		main(int ac, char **av)
{
	int		fd;
	int		i;
	char	**tab;

	i = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, tab))
	{
		printf("%s\n", tab[i]);
		i++;
	}
	close(fd);
	return (0);
}
