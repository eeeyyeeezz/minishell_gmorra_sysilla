/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:17:50 by sysilla           #+#    #+#             */
/*   Updated: 2020/11/18 16:17:34 by sysilla          ###   ########.fr       */
=======
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 15:01:21 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/07 20:55:26 by gmorra           ###   ########.fr       */
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t d;
	size_t s;
	size_t i;

	i = 0;
	d = 0;
	s = 0;
	while (src[s])
		s++;
	if (size == 0)
		return (s);
	while (d < size && dst[d])
		d++;
	if (size <= d)
		return (size + s);
	while (size && (--size - d) && src[i])
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = '\0';
	return (s + d);
=======
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	origa_origa_dstlen;
	size_t	origa_dstlen;
	size_t	origa_srclen;
	char	*d_dst;

	d_dst = dst;
	origa_dstlen = ft_strlen(dst);
	origa_srclen = ft_strlen(src);
	origa_origa_dstlen = ft_strlen(dst);
	i = ft_strlen(dst);
	if (dst == NULL && src == NULL)
		return (0);
	if (ft_strlen(dst) > dstsize || dstsize == 0)
		return (ft_strlen(src) + dstsize);
	while (*src && (dstsize - 1) > origa_dstlen++)
		d_dst[i++] = *src++;
	d_dst[i] = '\0';
	return (origa_srclen + origa_origa_dstlen);
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
}
