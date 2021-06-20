/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 12:04:54 by gmorra            #+#    #+#             */
/*   Updated: 2021/04/12 19:57:23 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static	int			is_redirect(char c)
{
	if (c == '\\' || c == '\'' || c == '>' ||
	c == '<')
		return (1);
	return (0);
}

void				syntax_error(char *line, t_struct *global)
{
	int i;

	i = -1;
	if (line[0] == ';' || line[0] == '|' ||
	line[ft_strlen(line) - 1] == '|')
		ft_error("Syntax error\n");
	while (line[++i])
	{
		if (line[i] == '\"')
		{
			if (line[i + 1])
				i++;
			while (line[i] != '\"')
				i++;
		}
		if (line[i] == '\'')
		{
			if (line[i + 1])
				i++;
			while (line[i] != '\'')
				i++;
		}
		if (line[i] == ';' && line[i + 1] == ';')
			ft_error("Double semicolon\n");
		if (line[i] == '|' && line[i + 1] == '|')
			ft_error("Double pipe\n");
	}

}
