/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:18:44 by sysilla           #+#    #+#             */
/*   Updated: 2020/11/18 16:26:46 by sysilla          ###   ########.fr       */
=======
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:56:56 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/05 17:52:36 by gmorra           ###   ########.fr       */
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
<<<<<<< HEAD
	char	*smap;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(smap = (char*)malloc(sizeof(*smap) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i])
	{
		smap[i] = f(i, s[i]);
		i++;
	}
	smap[i] = '\0';
	return (smap);
=======
	size_t	i;
	char	*temp;

	i = -1;
	if (s == NULL)
		return (NULL);
	temp = malloc(ft_strlen(s) + 1);
	if (temp == NULL)
		return (NULL);
	while (s[++i])
		temp[i] = f(i, s[i]);
	temp[i] = '\0';
	return (temp);
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
}
