/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:11:50 by sysilla           #+#    #+#             */
/*   Updated: 2020/11/20 13:32:53 by sysilla          ###   ########.fr       */
=======
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:38:42 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/08 15:45:21 by gmorra           ###   ########.fr       */
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
<<<<<<< HEAD
	char		*sub;
	size_t		i;
	size_t		lens;
=======
	size_t		i;
	size_t		s_start;
	char		*sub;
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c

	lens = ft_strlen(s);
	i = 0;
<<<<<<< HEAD
	if (!s || !(sub = (char*)malloc(sizeof(*sub) * len + 1)))
		return (NULL);
	if (start < lens)
	{
		while (i < len)
		{
			sub[i] = s[i + start];
			i++;
		}
	}
=======
	s_start = start;
	sub = malloc(len + 1);
	if (sub == NULL || s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		sub[i] = '\0';
		return (sub);
	}
	while (len-- && s[start])
		sub[i++] = s[s_start++];
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
	sub[i] = '\0';
	return (sub);
}
