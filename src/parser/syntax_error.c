/*
;;;;;	SYNTAX_ERROR.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"

static	int			is_redirect(char c)
{
	if (c == '\\' || c == '\'' || c == '>' ||
	c == '<')
		return (1);
	return (0);
}

void			ft_free(void **var)
{
	free(*var);
	*var = NULL;
}

void			init_all(t_struct *global)
{
	global->pars.args = NULL;
	global->pars.ft_cmd = NULL;
	global->pars.pipis = NULL;
	global->history = NULL;
	global->flags.ft_arg = 0;
	global->flags.ft_error = 0;
}

static	void		check_error_quotes(t_struct *global, char *line, int *i, char quote)
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

static	void		check_quotes(t_struct *global, char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '\"' || line[i] == '\'')
			check_error_quotes(global, line, &i, line[i]);
	}
}

void				syntax_error(t_struct *global, char *line)
{
	int i;

	i = -1;
	if (line[0] == ';' || line[0] == '|' ||
	line[ft_strlen(line) - 1] == '|')
	{
		global->flags.ft_error = 1;
		write(1, "Syntax error\n", 13);
		return ;
	}
	check_quotes(global, line);
	while (line[++i] && !global->flags.ft_error)
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
		{
			global->flags.ft_error = 1;
			write(1, "Double semicolon\n", 17);
		}
		if (line[i] == '|' && line[i + 1] == '|')
		{
			global->flags.ft_error = 1;
			write(1, "Double pipe\n", 13);
		}
	}
}
