/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:53:07 by sysilla           #+#    #+#             */
/*   Updated: 2020/11/18 16:21:53 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
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
}
