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

void			print_aboba(char ***arg, char *str)
{
	for (int i = 0; arg[i]; i++)
	{
		for (int j = 0; arg[i][j]; j++)
			printf("%s [%s]\n", str, arg[i][j]);
		printf("SPACE \n");
	}
}

int				pars_characters(t_struct *global, char *line)
{
	int		i;
	char	*str;
	char	*encode_line;

	i = -1;
	if (!(str = ft_strdup(line)))
		ft_error("Malloc Error!\n");	
	if (!(encode_line = encode_lines(ft_strdup(str))))
		ft_error("Malloc Error!\n");
	ft_free((void *)&str);
	global->pars.ft_cmd = get_all_commands(encode_line, global);	// leaks
	get_all_arguments(encode_line, global);
	encode_arg(global);
	// print_aboba(global->pars.dirty_array, "ABOBA");
	// for (int i = 0; global->pars.dirty_array[i]; i++)
		// change_dollar_args(global, global->pars.dirty_array[i]);
	ft_free((void *)&encode_line);
	return (0);
}

void			ft_parser(t_struct *global, char *line)
{
	global->flags.ft_cmd = 0;
	global->flags.ft_arg = 0;
	global->flags.ft_error = 0;
	syntax_error(global, line);
	if (!global->flags.ft_error)
		pars_characters(global, line);
}


// echo "Hello cat -e !" | cat -e

// echo ";";";";";"
// 2) $ без кавычек и в кавычках
// 4) ЗАЩИТИТЬ МАЛЛОКИ !!!!!!!!!!!
// 9) После ошибок снова выходить в печать
