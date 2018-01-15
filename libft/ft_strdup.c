/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:13:44 by apoque            #+#    #+#             */
/*   Updated: 2018/01/12 16:23:22 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s)
{
	const char	*str;
	char		*dup;
	char		*trace;
	size_t		i;
	size_t		len;

	if (!s)
		return (NULL);
	str = (const char *)s;
	len = ft_strlen(str);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	trace = (char *)dup;
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (trace);
}
