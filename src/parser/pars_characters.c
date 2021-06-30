/*
;;;;;	MAKEFILE.H
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"

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

static	void	get_clean(t_struct *global)
{
	


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
	get_clean(global);
	ft_free((void *)&encode_line);
	return (0);
}
