/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:24:41 by apoque            #+#    #+#             */
/*   Updated: 2017/12/04 13:37:58 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
<<<<<<< HEAD
//# include "libft/libft.a"
#include <unistd.h>
#include <stdlib.h>
=======
# include "libft.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

>>>>>>> abf9730ed7cb38a80016d004768bcb71473aeb3f
int	get_next_line(const int fd, char **line);

#endif
