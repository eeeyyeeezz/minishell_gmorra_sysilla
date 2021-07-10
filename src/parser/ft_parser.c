/*
;;;;;	FT_PARSER.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"


int		count_twodimarray(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

static	void	encode_arg(t_struct *global)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (global->pars.dirty_array[++i])
		decode_lines(global->pars.dirty_array[i]);
}

int				pars_characters(t_struct *global, char *line)
{
	int		i;
	char	*str;
	char	*encode_line;

	i = -1;
	if (!(str = ft_strdup(line)))				// leaks??
		ft_error("Malloc Error!\n");	
	if (!(encode_line = encode_lines(ft_strdup(str))))
		ft_error("Malloc Error!\n");
	ft_free((void *)&str);
	global->pars.ft_cmd = get_all_commands(encode_line, global);	// leaks
	global->pars.ft_arg = malloc(sizeof(char *) * 100);
	if (!global->pars.ft_arg)
		ft_error("Malloc Error!\n");	
	get_all_arguments(encode_line, global);
	encode_arg(global);
	for (int i = 0; global->pars.dirty_array[i]; i++)
	{
		for (int j = 0; global->pars.dirty_array[i][j]; j++)
			printf("ABOBA [%s]\n", global->pars.dirty_array[i][j]);
		printf("SPACE \n");
	}
	// for (int i = 0; global->pars.dirty_array[i]; i++)
	// 	get_clean(global, global->pars.dirty_array[i]);
	ft_free((void *)&encode_line);
	return (0);
}

void			ft_parser(t_struct *global, char *line)
{
	global->flags.ft_cmd = 0;
	global->flags.ft_arg = 0;
	syntax_error(line, global);
	pars_characters(global, line);
}


// echo "Hello cat -e !" | cat -e

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
