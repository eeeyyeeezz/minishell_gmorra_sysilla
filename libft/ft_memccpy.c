/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:33:28 by sysilla           #+#    #+#             */
/*   Updated: 2020/11/16 13:47:46 by sysilla          ###   ########.fr       */
=======
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:24:11 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/02 14:17:40 by gmorra           ###   ########.fr       */
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
<<<<<<< HEAD
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
=======
	size_t	i;

	i = 0;
	while (n--)
	{
		if (((unsigned char *)src)[i] == (unsigned char)c)
		{
			*((unsigned char *)dst) = ((unsigned char *)src)[i];
			dst++;
			return (dst);
		}
		else
		{
			*((unsigned char *)dst) = ((unsigned char *)src)[i++];
			dst++;
		}
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
	}
	return (0);
}
