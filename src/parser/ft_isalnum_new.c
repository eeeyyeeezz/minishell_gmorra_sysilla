/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/29 17:46:52 by gmorra            #+#    #+#             */
/*   Updated: 2021/04/07 15:19:17 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		ft_isspaces(char word)
{
	if (word == ' ' || word == '	')
		return (1);
	return (0);
}

int				ft_issleter(char s)
{
	int i;

	i = 0;
	while ((s >= 'A' && s <= 'Z') ||
	(s >= 'a' && s <= 'z'))
		i++;
	return (i);
}

int	ft_isalnum_new(int c)
{
	if ((c >= 33 && c <= 37) || (c >= 39 && c <= 58)
	|| c == 60)
		return (1);
	else if ((c >= 61 && c <= 123)
	 || c == 125 || c == 126)
		return (1);
	return (0);
}
