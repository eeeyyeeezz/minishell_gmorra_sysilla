/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 13:45:15 by gmorra            #+#    #+#             */
/*   Updated: 2021/05/22 15:31:28 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void			pars_cd(char *line, t_struct *global)
{
	char			*str;
	short	int		begin;
	short	int		end;
	short	int		i;

	i = 2;
	end = 0;
	begin = 0;
	while (ft_isspaces(line[i]) && line[i])
		i++;
	if (line[i])
	{
		begin = i;
		while(ft_isalnum_cd(line[i]))
			i++;
		end = i;
	}
	i = 0;
	str = malloc(sizeof(char) * (end - begin) + 1);
	while (begin != end)
		str[i++] = line[begin++];
	str[i] = '\0';
	printf("ETO STR [%s]\n", str);
	// if (global->pars.info != NULL)
		// free(global->pars.info);
	global->pars.info = str;
	// free(str);			// LEAKS??
	global->pars.cmd = 1;
	// printf("eto na cd [%s]\n", str);
}
