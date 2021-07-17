/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:59:14 by sysilla           #+#    #+#             */
/*   Updated: 2020/11/18 16:14:33 by sysilla          ###   ########.fr       */
=======
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:28:33 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/02 16:50:43 by gmorra           ###   ########.fr       */
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
<<<<<<< HEAD
	char *r;

	r = (char *)s;
	while (*r != c)
	{
		if (*r == '\0')
			return (NULL);
		r++;
	}
	return (r);
=======
	char	*temp;

	temp = (char *)s;
	while (*temp != c)
	{
		if (*temp == '\0')
			return (NULL);
		temp++;
	}
	return (temp);
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
}
