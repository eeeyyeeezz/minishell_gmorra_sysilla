/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:43:12 by sysilla           #+#    #+#             */
/*   Updated: 2020/11/18 16:43:36 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_calloc(size_t count, size_t size)
{
	char			*add;
	unsigned int	bytes;
	size_t			i;

	bytes = count * size;
	if (!(add = malloc(bytes)))
		return (NULL);
	i = 0;
	while (bytes--)
	{
		add[i] = 0;
		i++;
	}
	return ((void *)add);
}
