/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_without_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:01:48 by gmorra            #+#    #+#             */
/*   Updated: 2021/04/03 15:16:10 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int				check_count(char *line)
{
	short	int	count;
	short	int	i;

	i = 0;
	count = 0;
	while (line[i] != '\0' && count == 0)
	{
		while (!ft_isalnum(line[i]))
			i++;
		while (ft_isalnum(line[i]))
			i++;
		if (line[i] != '\0')
			count++;
	}
	return (count);
}

int						pars_without_quotes(char *line, t_struct *global)
{
	short	int		i;
	short	int		end;
	short	int		count;
	char			*str;

	i = 0;
	count = check_count(global->pars.first_line);
	end = i;
	if (count > 0)
	{
		while (line[end] != '"' && line[end] != '\'' && line[end])
			end++;
		str = malloc(sizeof(char) * (end - i) + 1);
		while (i != end)
		{
			str[i] = line[i];
			i++;
		}
		str[i] = '\0';
		i = -1;
		while (str[++i])
		{
			if (str[i] == '$' && str[i + 1] != '$')
				str = pars_dollar_sign(str, global);
		}
		global->pars.info = ft_strjoin_new(global->pars.info, str);
		free(str);
	}
	// printf("eto end [%d]\n", end);
	return (end);
}
