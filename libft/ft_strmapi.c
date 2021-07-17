/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:18:44 by sysilla           #+#    #+#             */
/*   Updated: 2020/11/18 16:26:46 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
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
}
