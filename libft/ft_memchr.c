/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 13:00:09 by sysilla           #+#    #+#             */
/*   Updated: 2020/11/07 13:00:11 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cs;
	unsigned char	cc;

	cs = (unsigned char *)s;
	cc = (unsigned char)c;
	while (n--)
		if (*(cs++) == (unsigned char)c)
			return (cs - 1);
	return (NULL);
}
