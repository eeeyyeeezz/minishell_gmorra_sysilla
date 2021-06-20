/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:11:50 by sysilla           #+#    #+#             */
/*   Updated: 2020/11/20 13:32:53 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		i;
	size_t		lens;

	lens = ft_strlen(s);
	i = 0;
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
	sub[i] = '\0';
	return (sub);
}
