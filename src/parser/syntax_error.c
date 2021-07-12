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
	global->pars.dirty_array = NULL;
	global->pars.ft_cmd = NULL;
	global->pars.pipis = NULL;
	global->history = NULL;
	global->flags.ft_arg = 0;
	global->flags.flag = 0;
	global->term_name = "xterm-256color";
}

static	void		check_error_quotes(char *line, int *i, char quote)
{
	*i += 1;

	while (line[*i] != quote && line[*i])
		*i += 1;
	if (!line[*i])
		ft_error("Aboba Error! Quotes not closed!\n");
}

static	void		check_quotes(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '\"' || line[i] == '\'')
			check_error_quotes(line, &i, line[i]);
	}
}

void				syntax_error(char *line, t_struct *global)
{
	int i;

	i = -1;
	if (line[0] == ';' || line[0] == '|' ||
	line[ft_strlen(line) - 1] == '|')
		ft_error("Syntax error\n");
	check_quotes(line);
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
