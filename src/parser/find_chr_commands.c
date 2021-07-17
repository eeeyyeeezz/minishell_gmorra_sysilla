/*
;;;;;	FIND_CHR_COMMANDS.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"

static	char	*while_str(char *str, char *line, int i, int end)
{
	while (i != end)
	{
		if (line[i] == '\"')
			str = skip_quote(line, str, &i, '\"');
		else if (line[i] == '\'')
			str = skip_quote(line, str, &i, '\'');
		else
			str = ft_strjoin_char(str, line[i++]);
	}
	return (str);
}

char	*find_chr_commands(t_struct *global, char *line)
{
	char		*str;
	int			end;
	int			i;

	i = 0;
	str = ft_calloc(1, sizeof(char *));
	if (!str)
		return (NULL);
	while (ft_isspaces(line[i]) && line[i])
		i++;
	end = i;
	while (!ft_isspaces(line[end]) && !ft_chr(line[end]) && line[end])
	{
		if (line[end] == '\'' || line[end] == '\"')
			end += skip_quote_i((char *)&line[end], line[end]);
		end++;
	}
	str = while_str(str, line, i, end);
	str = get_dollar(global, line, str, end);
	return (str);
}
