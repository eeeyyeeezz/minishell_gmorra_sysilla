/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:06:54 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/29 17:08:24 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int				skip_cmd(char *big, char *little)
{
	int	i;
	int	j;
	int	save;

	i = 0;
	j = 0;
	save = 0;
	while (big[i])
	{
		if (big[i] == little[j])
		{
			while (big[save] == little[j])
			{
				save++;
				j++;
			}
			if (little[j] != '\0')
				j = 0;
			else
			{
				while (ft_isspaces(big[save]))
					save++;
				return (save - 1);
			}
		}
		i++;
		save = i;
	}
	return (0);
}
