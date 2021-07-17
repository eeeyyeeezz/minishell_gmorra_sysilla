/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 13:00:22 by sysilla           #+#    #+#             */
/*   Updated: 2020/11/07 13:00:24 by sysilla          ###   ########.fr       */
=======
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:17:19 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/02 16:13:56 by gmorra           ###   ########.fr       */
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			i;

	if (s1 == s2 || n == 0)
		return (0);
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	while (i < n && c1[i] == c2[i])
		i++;
	if (i == n)
		return (0);
	return (c1[i] - c2[i]);
=======
int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*temp1;
	unsigned char		*temp2;
	size_t				i;

	i = 0;
	temp1 = (unsigned char *)s1;
	temp2 = (unsigned char *)s2;
	while (n--)
	{
		if (temp1[i] != temp2[i])
			return ((unsigned char)temp1[i] - (unsigned char)temp2[i]);
		i++;
	}
	return (0);
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
}
