/*
;;;;;	FT_PARSER.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"

// printf("cmd [%d]\nchr [%d]\ninfo env [%s]\nfirst line [%s]\nfirst word [%s]\ninfo [%s]\n", 
// 	global->pars.cmd, global->pars.chr, global->pars.info_env, global->pars.first_line, global->pars.first_word,
// 	global->pars.info);

static	void get_two_to_three(t_struct *global)
{
	
}

void	enter_pressed(t_struct *global, char *line)
{
	// printf("LINE [%s]\n", line);
	syntax_error(line, global);
	global->pars.first_line = line;
	find_redirects_pipes(global, line);		// TODO: leaks
	get_two_to_three(global);
	// pars_arguments_line(line, global);
}
 
void			ft_parser(t_struct *global, char *line)
{
	enter_pressed(global, line);
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
