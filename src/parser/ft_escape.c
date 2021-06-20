/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_escape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:45:02 by gmorra            #+#    #+#             */
/*   Updated: 2021/04/14 16:08:56 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


int			key_escape(char *str)
{
	if (ft_strcmp(str, "\e[A") && ft_strcmp(str, "\e[B") &&
	ft_strcmp(str, "\e[C") && ft_strcmp(str, "\e[D") &&
	ft_strcmp(str, "\177") && str[0] != '\n' && str[0] != '\t')
		return (1);
	else
		return (0);
}

int			chr_to_int(char s, char next)
{
	if (s == ';')
		return (1);
	else if (s == '|')
		return (2);
	else if (s == '<')
		return (3);
	else if (s == '>' && next == '>')
		return (5);
	else if (s == '>' && next != '>')
		return (4);
	return (-1);
}

int			count_arguments(char *line, int begin)
{
	int		count;
	int		end;
	int		i;

	i = 0;
	end = 0;
	count = 0;
	while (!ft_chr(line[end]) && line[end])
		end++;
	while (i < end)
	{
		while (ft_isspaces(line[i]))
			i++;
		while (ft_isalnum_new(line[i]) || line[i] == '\''
		|| line[i] == '\"' || line[i] < 0)
			i++;
		count++;
		i++;
	}
	return (count);
}

int			ft_chr(char s)
{
	if (s == ';' || s == '|' || s == '<' || s == '>')
		return (1);
	else
		return (0);
}

int			ft_escape(char s)
{
	if (s == 34 || s == 39 || s == 92)
		return (1);
	else
		return (0);
}
