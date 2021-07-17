/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2020/11/16 14:53:07 by sysilla           #+#    #+#             */
/*   Updated: 2020/11/18 16:21:53 by sysilla          ###   ########.fr       */
=======
/*   Created: 2020/10/31 17:48:20 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/04 14:43:05 by gmorra           ###   ########.fr       */
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
<<<<<<< HEAD
	size_t	len;
	size_t	i;
	char	*jstr;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(jstr = (char*)malloc(sizeof(*jstr) * len + 1)))
		return (NULL);
	while (*s1 != '\0')
		jstr[i++] = *s1++;
	while (*s2 != '\0')
		jstr[i++] = *s2++;
	jstr[i] = '\0';
	return (jstr);
=======
	int		i;
	int		a;
	char	*new_string;

	a = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	new_string = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new_string == NULL)
		return (NULL);
	while (s1[a])
		new_string[i++] = s1[a++];
	a = 0;
	while (s2[a])
		new_string[i++] = s2[a++];
	new_string[i] = '\0';
	return (new_string);
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
}
