/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2020/11/13 14:24:35 by sysilla           #+#    #+#             */
/*   Updated: 2020/11/16 17:18:00 by sysilla          ###   ########.fr       */
=======
/*   Created: 2020/10/30 16:39:21 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/03 19:39:13 by gmorra           ###   ########.fr       */
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;
=======
static int		ft_ft_strncmp(const char *s1, const char *s2)
{
	unsigned int i;
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c

	if (find[0] == '\0')
		return ((char *)str);
	i = 0;
<<<<<<< HEAD
	while (i < len && str[i] != '\0')
	{
		j = 0;
		while (find[j] != '\0')
		{
			if (i + j >= len || str[i + j] != find[j])
				break ;
			j++;
		}
		if (find[j] == '\0')
			return ((char *)(str + i));
		i++;
	}
	return (0);
=======
	while (s1[i] && s2[i + 1] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char			*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[ft_strlen(little) + i - 1] && i + ft_strlen(little) <= len)
	{
		if (ft_ft_strncmp(&big[i], little) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
}
