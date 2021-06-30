/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:10:49 by gmorra            #+#    #+#             */
/*   Updated: 2021/04/08 15:07:01 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void		ft_putstr(char *s)
{
	if (s == NULL)
		return ;
	while (*s)
		write(1, &*s++, 1);
}

int			ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (s1[i] || s2[i] != '\0')
		return (1);
	return (0);
}

int			ft_strlen_array(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int			ft_putchar(int word)
{
	write(1, &word, 1);
	return (word);
}
