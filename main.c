/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 15:27:18 by apoque            #+#    #+#             */
/*   Updated: 2017/12/29 19:12:30 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <string.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	//int		i;
	int		ret;

	//i = 0;
	(void)argc;
	fd = open(argv[1], O_RDONLY);
	line = (char *)malloc(sizeof(*line) * 1);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		//printf("on va rentrer ds gnl\n");
		printf("%s\n", line);
		//i++;
	}
	return (1);
}
