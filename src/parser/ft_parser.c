/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:32:21 by gmorra            #+#    #+#             */
/*   Updated: 2021/04/14 14:22:40 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// printf("cmd [%d]\nchr [%d]\ninfo env [%s]\nfirst line [%s]\nfirst word [%s]\ninfo [%s]\n", 
// 	global->pars.cmd, global->pars.chr, global->pars.info_env, global->pars.first_line, global->pars.first_word,
// 	global->pars.info);

static	char	*enter_pressed(char *line, char *str, t_struct *global)
{
	if (!ft_strncmp(str, "\n", 1))
	{
		// printf("LINE [%s]\n", line);
		syntax_error(line, global);
		global->pars.first_line = line;
		open_file_history(line, global);
		while (global->history->next)
			global->history = global->history->next;
		find_redirects_pipes(line, global);		// TODO: leaks
		pars_arguments_line(line, global);
		lgc_choise(global);
		write_minishell();
		line[0] = 0;
		return (line);
	}
	return (line);
}

void			ft_parser(t_struct *global)
{
	int				br;
	char			str[200];
	char			*line;

	str[0] = 0;
	line = NULL;
	init_all(global);
	init_termios(global);
	gnl_history_to_list(global);
	while (1)
	{
		while (global->history->next)
			global->history = global->history->next;
		line = ft_calloc(1, sizeof(char *));
		while (1)
		{
			br = read(0, str, 100);
			str[br] = 0;
			line = key_hook(str, line, global);
			if (!ft_strncmp(str, "\4", 1) && line[0] == 0)
				ft_exit();
			if (key_escape(str) && global->flags.flag != 1)
				line = ft_strjoin_new(line, str);
			global->flags.flag = 0;
			line = enter_pressed(line, str, global);
		}
	}
}


// ./ ПАРСИНГ
// echo ";";";";";";"
// лики на долларах
// echo $USERasdasdasdasd $"HOME" - sega
// лишняя инфа в долларе сега надо сделоть
// echo "$USER asd " сега с пробелом в конце??? || все гуд
// экранировнаие работает ПО ДРУГОМУ!!!!!!! немного по другому
// echo ""123"" pizda vse zavisaet || vse ok
// !!! OBNULIT FIRST WORD!!! || да обнулен
// экранирование БЕЗ кавычек echo \' = ' мда
// 2) $ без кавычек и в кавычках
// 4) ЗАЩИТИТЬ МАЛЛОКИ !!!!!!!!!!!
// 5) echo ''asd''22 зависает (вай?) || не зависает другие приколы || не зависает
// 6) exit 123 = echo $? = 123
// || exit echo $? = 0
// || exit asdasd echo $? = 255
// || exit 123 456 = не выйдет echo $? = 1
// 7) "command not found" 127
// 9) После ошибок снова выходить в печать
// 10) export пробел s null parametrs
