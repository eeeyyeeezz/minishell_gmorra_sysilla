/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:25:44 by sysilla           #+#    #+#             */
/*   Updated: 2020/11/18 12:42:53 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_ilen(int n)
{
	size_t	l;

	if (n == 0)
		return (1);
	l = 0;
	if (n < 0)
		l++;
	while (n)
	{
		n /= 10;
		l++;
	}
	return (l);
}

char				*ft_itoa(int n)
{
	size_t	len;
	size_t	e;
	char	*r;

	len = ft_ilen(n);
	if (!(r = (char *)malloc(len + 1)))
		return (NULL);
	r[len] = '\0';
	if (n < 0)
	{
		r[0] = '-';
		e = 1;
	}
	else
		e = 0;
	while (len-- > e)
	{
		r[len] = '0' + n % 10 * (n < 0 ? -1 : 1);
		n /= 10;
	}
	return (r);
}
