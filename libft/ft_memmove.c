/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 13:01:39 by sysilla           #+#    #+#             */
/*   Updated: 2020/11/07 13:01:41 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*csrc;
	char	*cdst;
	size_t	i;

	if (src == dst)
		return (dst);
	csrc = (char *)src;
	cdst = (char *)dst;
	if (src < dst)
	{
		i = len;
		while (i-- > 0)
			cdst[i] = csrc[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			cdst[i] = csrc[i];
			i++;
		}
	}
	return (dst);
}
