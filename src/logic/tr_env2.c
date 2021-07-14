/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tr_env2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 17:06:27 by sysilla           #+#    #+#             */
/*   Updated: 2021/07/14 17:06:30 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	cnt_chr(char **src)
{
	int		i;
	int		j;
	int		max_char;

	max_char = 0;
	i = 0;
	while (src[i])
	{
		j = 0;
		while (src[i][j] != '\0')
		{
			j++;
		}
		if (max_char < j)
		{
			max_char = j;
		}
		i++;
	}
	return (max_char);
}

int	cnt_str(char **src)
{	
	int	i;

	i = 0;
	while (src[i])
	{
		i++;
	}
	return (i);
}
