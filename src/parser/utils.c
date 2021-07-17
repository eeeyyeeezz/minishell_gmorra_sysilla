/*
;;;;;	UTILS.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"

void	init_all(t_struct *global)
{
	global->pars.args = NULL;
	global->pars.ft_cmd = NULL;
	global->flags.ft_arg = 0;
	global->flags.ft_error = 0;
}

char	*skip_quote(char *line, char *str, int *i, char quote)
{	
	int		quote_end;

	(*i)++;
	quote_end = *i;
	while (line[quote_end] != quote && line[quote_end])
		quote_end++;
	while (*i != quote_end)
		str = ft_strjoin_char(str, line[(*i)++]);
	(*i)++;
	return (str);
}

int	count_malloc_chr(char *line)
{
	int			malloc_count;
	int			i;

	malloc_count = 0;
	i = -1;
	if (!line[0])
		return (0);
	while (line[++i])
	{
		if (ft_chr(line[i]))
			malloc_count++;
		if (line[i] == '>' && line[i + 1] == '>')
			i++;
		if (line[i] == '<' && line[i + 1] == '<')
			i++;
	}
	malloc_count++;
	return (malloc_count);
}

int	skip_quote_i(char *line, char quote)
{
	int	i;

	i = 1;
	while (line[i] && line[i] != quote)
		i++;
	return (i);
}

int	str_in_str(char *haystack, char *needle)
{
	int	i;
	int	count;

	count = 0;
	i = ft_strlen(needle) - 1;
	while (haystack[count] != '=')
		count++;
	count--;
	while (needle[i] == haystack[count])
	{
		i--;
		count--;
	}
	if (needle[i] == '$')
		return (1);
	else
		return (0);
}
