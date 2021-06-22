/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_termios.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:06:51 by gmorra            #+#    #+#             */
/*   Updated: 2021/04/09 16:53:47 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void			init_all(t_struct *global)
{
	global->pars.arg = NULL;
	// global->commands = NULL;
	global->history = NULL;
	global->pars.first_line = NULL;
	global->pars.info = NULL;
	global->pars.info_env = NULL;
	global->pars.first_word = NULL;
	global->pars.cmd = -1;
	global->pars.chr = -1;
	global->flags.flag = 0;
	global->term_name = "xterm-256color";
}

void	write_minishell()
{
	write(1, "\033[1;33m$\033[1;32mminishell: \033[0m", 30);
	tputs(save_cursor, 1, ft_putchar);
}


void	init_termios(t_struct *global)
{
	struct termios term;

	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO);
	term.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &term);
	tgetent(0, global->term_name);
	// write_minishell();
}
