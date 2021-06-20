/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 15:11:40 by gmorra            #+#    #+#             */
/*   Updated: 2021/04/12 20:00:05 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static	void		single_quote_check_error(char *line)
{
	int i;
	int num;

	i = -1;
	num = 0;
	while (line[++i])
	{
		if (line[i] == '\'')
			num++;
	}
	if (num % 2 != 0)
	{
		ft_error("Syntax error. Quotes not closed\n");
		exit(0);
	}
}

int					pars_single_quotes(char *line, t_struct *global)
{
	int		i;
	int		begin;
	int		end;
	char	*str;

	i = 1;
	end = 0;
	begin = i;
	single_quote_check_error(line);
	while (line[i])
	{
		if (line[i] == '\'')
		{
			end = i;
			break ;
		}
		i++;
	}
	i = 0;
	str = malloc(sizeof(char) * (end - begin) + 1);
	while (begin != end)
		str[i++] = line[begin++];
	str[i] = '\0';
	global->pars.info = ft_strjoin_new(global->pars.info, str);
	free(str);				// LEAKS
	return (i + 2);
}

void				pars_info(char *line, t_struct *global, int malloc_count)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\"')
			i += pars_double_quotes((char *)&line[i], global);
		else if (line[i] == '\'')
			i += pars_single_quotes((char *)&line[i], global);
		else if (line[i] != '\'' && line[i] != '\"')
		{
			i += pars_without_quotes((char *)&line[i], global);
			if (i == 0)
				break ;
		}
	}
	ft_write("eto info [", global->pars.info, "]\n");
	free(global->pars.info);
}

void				find_info_echo(char *line, t_struct *global)
{
	int i;
	int	malloc_count;
	int	double_quote;

	i = -1;
	malloc_count = 0;
	double_quote = 0;
	while (line[++i])
	{
		if (line[i] == 34)			// || line[i] == 39 убрать позже || убрал
			double_quote++;
		malloc_count++;
	}
	malloc_count -= double_quote;
	if (double_quote % 2 != 0)
			ft_error("Syntax error. Quotes not closed\n");
	else
		pars_info(line, global, malloc_count);
}

void				pars_echo(char *line, t_struct *global)
{
	int i;

	global->pars.cmd = 0;
	i = 0;
	i = skip_cmd(line, "echo");
	global->pars.info = malloc(sizeof(char *));
	global->pars.info[0] = 0;
	while (ft_isspaces(line[i]))
		i++;
	find_info_echo((char *)&line[i], global);
}