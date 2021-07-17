/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:24:50 by sysilla           #+#    #+#             */
/*   Updated: 2020/11/18 16:28:34 by sysilla          ###   ########.fr       */
=======
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:32:57 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/04 14:13:21 by gmorra           ###   ########.fr       */
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
char				*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	if (c == 0)
		return ((char *)s + i);
	while (i > 0)
	{
		i--;
		if (s[i] == c)
			return ((char *)s + i);
=======
char	*ft_strrchr(const char *str, int c)
{
	const char	*tmp;
	size_t		i;

	i = 0;
	tmp = NULL;
	while (i < ft_strlen(str) + 1)
	{
		if (str[i] == c)
			tmp = &str[i];
		i++;
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
	}
	return ((char *)tmp);
}
