/*
;;;;;	FT_PARSER.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"

int	count_twodimarray(char **array)
{
	int	i;

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
	while (global->pars.args[++i])
		decode_lines(global->pars.args[i]);
}

void	print_aboba(char ***arg, char *str)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (arg[++i])
	{
		j = -1;
		while (arg[i][++j])
			printf("%s [%s]\n", str, arg[i][j]);
		printf("SPACE\n");
	}
}

int	pars_characters(t_struct *global, char *line)
{
	int		i;
	char	*str;
	char	*encode_line;

	i = -1;
	str = ft_strdup(line);
	if (!str)
		ft_error("Malloc Error!\n");
	encode_line = encode_lines(ft_strdup(str));
	if (!encode_line)
		ft_error("Malloc Error!\n");
	ft_free((void *)&str);
	global->pars.ft_cmd = get_all_commands(global, encode_line);
	get_all_arguments(global, encode_line);
	encode_arg(global);
	ft_free((void *)&encode_line);
	return (0);
}

void	ft_parser(t_struct *global, char *line)
{
	global->flags.ft_cmd = 0;
	global->flags.ft_arg = 0;
	global->flags.ft_error = 0;
	syntax_error(global, line);
	if (!global->flags.ft_error)
		pars_characters(global, line);
}
