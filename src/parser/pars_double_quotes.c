/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_double_quotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:33:08 by gmorra            #+#    #+#             */
/*   Updated: 2021/04/05 19:25:03 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static	void			check_escape(char *line)
{
	int i;
	int num;

	i = -1;
	while (line[++i])
	{
		num = 0;
		while (line[i] == 92)
		{
			num++;
			i++;
		}
		if (line[i] == '\"')
			break ;
		if (num == 3)
			ft_error("Syntax error. Escape\n");
	}
}

int						pars_double_quotes(char *line, t_struct *global)
{
	char	*str;
	int		begin;
	int		plus_i;
	int		end;
	int		i;

	i = 1;
	plus_i = 0;
	end = 0;
	begin = 1;
	check_escape(line);
	while (line[i])
	{
		if (line[i] == '"')
		{
			end = i;
			break ;
		}
		i++;
	}
	i = 0;
	str = malloc(sizeof(char) * (end - begin) + 1);
	while (begin != end)
	{
		if (line[begin] == 92)
		{
			begin++;
			plus_i++;
		}
		str[i++] = line[begin++];
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
	return (i + plus_i + 2);
}
