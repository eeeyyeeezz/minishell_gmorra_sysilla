/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:22:48 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/13 17:50:42 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

char		*ft_strchr_gnl(const char *s, int c)
{
	char	*temp;

	temp = (char *)s;
	while (*temp != c)
	{
		if (*temp == '\0')
			return (NULL);
		temp++;
	}
	return (temp);
}
