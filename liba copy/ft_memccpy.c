/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:33:28 by sysilla           #+#    #+#             */
/*   Updated: 2020/11/16 13:47:46 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)src)[i] == (unsigned char)c)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			return (((unsigned char *)dest) + (i + 1));
		}
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		++i;
	}
	return (0);
}
