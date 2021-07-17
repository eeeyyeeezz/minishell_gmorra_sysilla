/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2020/11/08 14:13:28 by sysilla           #+#    #+#             */
/*   Updated: 2020/11/18 16:30:11 by sysilla          ###   ########.fr       */
=======
/*   Created: 2020/10/28 16:12:21 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/09 16:27:15 by gmorra           ###   ########.fr       */
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

<<<<<<< HEAD
size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	if (size)
	{
		if (!src)
			return (0);
		size--;
		while (src[i] != '\0' && size)
		{
			dst[i] = src[i];
			i++;
			size--;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
=======
static size_t		min(size_t a, size_t size)
{
	return ((a < size) ? a : size);
}

size_t				ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (dst == NULL || src == NULL)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	len = min(ft_strlen(src), size - 1);
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	if (size <= ft_strlen(src) || size == 0)
		return (ft_strlen(src));
	return (len);
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
}
