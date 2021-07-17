/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:25:44 by sysilla           #+#    #+#             */
/*   Updated: 2020/11/18 12:42:53 by sysilla          ###   ########.fr       */
=======
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:24:08 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/06 18:34:14 by gmorra           ###   ########.fr       */
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
static size_t	ft_ilen(int n)
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
=======
static int	aabs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_strlen_atoi(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		++len;
	while (n != 0)
	{
		++len;
		n = n / 10;
	}
	return (len);
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
}

char	*ft_itoa(int n)
{
<<<<<<< HEAD
	size_t	len;
	size_t	e;
	char	*r;

	len = ft_ilen(n);
	if (!(r = (char *)malloc(len + 1)))
		return (NULL);
	r[len] = '\0';
=======
	int		len;
	char	*itoa;

	len = ft_strlen_atoi(n);
	itoa = (char *)malloc(sizeof(char) * (len + 1));
	if (itoa == NULL)
		return (NULL);
	itoa[len] = '\0';
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
	if (n < 0)
		itoa[0] = '-';
	if (n == 0)
		itoa[0] = '0';
	while (n != 0)
	{
<<<<<<< HEAD
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
=======
		--len;
		itoa[len] = aabs(n % 10) + 48;
		n = n / 10;
	}
	return (itoa);
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
}
