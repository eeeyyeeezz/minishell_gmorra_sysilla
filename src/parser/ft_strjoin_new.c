/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:36:16 by gmorra            #+#    #+#             */
/*   Updated: 2021/04/11 14:18:24 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char		*ft_strjoin_char_leaks(char *s1, char s2)
{
	int		i;
	char	*new_str;

	i = -1;
	if (!(new_str = malloc(sizeof(char) * ft_strlen(s1) + 2)))
		return (NULL);
	while (s1[++i])
		new_str[i] = s1[i];
	new_str[i] = s2;
	new_str[++i] = '\0';
	return (new_str);
}

char		*ft_strjoin_char(char *s1, char s2)
{
	char	*ptr_free;

	ptr_free = s1;
	if (!(s1 = ft_strjoin_char_leaks(s1, s2)))
		return (NULL);
	free(ptr_free);
	return (s1);
}

char		*ft_strjoin_new(char *s1, char *s2)
{
	char	*ptr_free;

	ptr_free = s1;
	if (!(s1 = ft_strjoin(s1, s2)))
		return (NULL);
	free(ptr_free);
	return (s1);
}
