/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 13:10:19 by gmorra            #+#    #+#             */
/*   Updated: 2021/04/12 16:45:54 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static	char				*key_delete(char *line, t_struct *global)
{
	global->flags.flag = 1;
	if (ft_strlen(line) > 0)
	{
		tputs(cursor_left, 1, ft_putchar);
		tputs(tigetstr("ed"), 1, ft_putchar);
		line[ft_strlen(line) - 1] = 0;
	}
	return (line);
}

static	char				*key_up_down(char *str, char *line, t_struct *global)
{
	char		*tmp;

	if (!ft_strcmp(str, "\e[A"))
	{
		tputs(restore_cursor, 1, ft_putchar);
		tputs(tigetstr("ed"), 1, ft_putchar);
		if (global->history)
		{
			if (global->history->prev)
				global->history = global->history->prev;
			ft_putstr_fd(global->history->content, 1);
			tmp = line;
			if (!(tmp = ft_strdup(global->history->content)))
				return (NULL);
			free(line);		// boom
		}
	}
	else if (!ft_strcmp(str, "\e[B"))
	{
		tputs(restore_cursor, 1, ft_putchar);
		tputs(tigetstr("ed"), 1, ft_putchar);
		if (global->history)
		{
			if (global->history->next)
				global->history = global->history->next;
			ft_putstr_fd(global->history->content, 1);
			tmp = line;
			if (!(tmp = ft_strdup(global->history->content)))
				return (NULL);
			free(line);
		}
	}
	return (tmp);
}

char						*key_hook(char *str, char *line, t_struct *global)
{
	if (!ft_strcmp(str, "\e[A"))
		line = key_up_down(str, line, global);
	else if (!ft_strcmp(str, "\e[B"))
		line = key_up_down(str, line, global);
	else if (!ft_strcmp(str, "\e[C") || !ft_strcmp(str, "\e[D"))
		;
	else if (!ft_strcmp(str, "\177"))
	{
		line = key_delete(line, global);
		return (line);
	}
	else
		ft_putstr(str);
	return (line);
}

