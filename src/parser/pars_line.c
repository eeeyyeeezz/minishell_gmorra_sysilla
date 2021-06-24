#/*
#;;;;;	MAKEFILE.H
#;;;;;	gmorra/sysilla's minishell
#;;;;;	team created ???
#;;;;;	team locked ???
#*/


#include "../../includes/minishell.h"

static	void		get_command_info(char *line, t_struct *global)
{
	if (global->pars.arg != NULL)
	{
		ft_lstclear(&global->pars.arg, free);
		global->pars.arg = NULL;
	}
	if (!ft_strcmp(line, "echo"))
		pars_echo(global->pars.first_line, global);
	else if (!ft_strcmp(line, "export"))
		pars_export(global->pars.first_line, global);
	else if (!ft_strcmp(line, "unset"))
		pars_unset(global->pars.first_line, global);
	else if (!ft_strcmp(line, "env"))
		pars_env(global->pars.first_line, global);
	else if (!ft_strcmp(line, "pwd"))
		global->pars.cmd = 2;	
	else if (!ft_strcmp(line, "cd"))
		pars_cd(global->pars.first_line, global);
	else if (!ft_strcmp(line, ""))
		;
	else
		;
		// printf("%s: command not found \n" , line);
}

char		*skip_quote(char *line, char *str, int *i, char quote)
{
	int		quote_end;

	(*i)++;
	quote_end = *i;
	while (line[quote_end] != quote)
		quote_end++;
	while (*i != quote_end)
		str = ft_strjoin_char(str, line[(*i)++]);			// boom
	(*i)++;
	return (str);
}


static	void		find_command(char *line, t_struct *global)
{
	char		*str;
	int			quote_end;
	int			end;
	int			i;

	i = 0;
	if (!(str = ft_calloc(1, sizeof(char *))))		// TODO: leaks??	|| tozhe net vrode
		ft_error("Malloc Error\n");
	while (ft_isspaces(line[i]))
		i++;
	end = i;
	while (!ft_isspaces(line[end]) && line[end])
		end++;
	while (i != end)
	{
		if (line[i] == '\"')
			str = skip_quote(line, str, &i, '\"');
		else if (line[i] == '\'')
			str = skip_quote(line, str, &i, '\'');
		else
			str = ft_strjoin_char(str, line[i++]);			// TODO: leaks? || vrode net
	}
	if (global->pars.first_word != NULL)
		free(global->pars.first_word);
	global->pars.first_word = str;
	get_command_info(global->pars.first_word, global);
}

int				pars_arguments_line(char *line, t_struct *global)
{
	find_command(line, global);
	return (0);
}
