/*
;;;;;	SYNTAX_ERROR.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"

void	ft_free(void **var)
{
	free(*var);
	*var = NULL;
}

static	void	check_error_quotes(t_struct *global,
	char *line, int *i, char quote)
{
	*i += 1;
	while (line[*i] != quote && line[*i])
		*i += 1;
	if (!line[*i])
	{
		global->flags.ft_error = 1;
		write(2, "Aboba Error! Quotes not closed!\n", 32);
	}
}

static	void	check_quotes(t_struct *global, char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '\"' || line[i] == '\'')
			check_error_quotes(global, line, &i, line[i]);
	}
}

static	void	write_syntax_error(t_struct *global, char *str)
{
	global->flags.ft_error = 1;
	ft_putstr_fd(str, 2);
}

void	syntax_error(t_struct *global, char *line)
{
	int	i;

	i = -1;
	if (line[0] == ';' || line[0] == '|'
		|| line[ft_strlen(line) - 1] == '|')
		write_syntax_error(global, "Syntax error\n");
	check_quotes(global, line);
	while (line[++i] && !global->flags.ft_error)
	{
		if (line[i] == '\"')
			while (line[++i] != '\"')
				;
		if (line[i] == '\'')
			while (line[++i] != '\'')
				;
		if (line[i] == ';' && line[i + 1] == ';')
			write_syntax_error(global, "Double semicolon\n");
		if (line[i] == '|' && line[i + 1] == '|')
			write_syntax_error(global, "Double pipe\n");
	}
}
