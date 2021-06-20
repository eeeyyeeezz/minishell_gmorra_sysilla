/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:39:21 by gmorra            #+#    #+#             */
/*   Updated: 2021/04/07 15:20:35 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int		ft_ft_strncmp(char *s1, char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i] && s2[i + 1] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int				ft_ft_strnstr(char *big, char *little)
{
	size_t	i;

	i = 0;
	while (big[ft_strlen(little) + i - 1])
	{
		if (ft_ft_strncmp(&big[i], little) == 0)
			return (1);
		i++;
	}
	return (0);
}
