/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:14:29 by apoque            #+#    #+#             */
/*   Updated: 2018/01/12 18:02:49 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	int		i;
	int		j;
	char	*str;

	if (!s1 && s2)
		return (ft_strdup((char *)s2));
	if (!s1 && !s2)
		return (NULL);
	i = -1;
	j = 0;
	size = (int)ft_strlen(s1) + (int)ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[size] = '\0';
	return (&str[0]);
}
