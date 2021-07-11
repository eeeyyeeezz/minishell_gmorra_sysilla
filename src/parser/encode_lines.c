/*
;;;;;	ENCODE_LINES.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"

char	*quote_encode(char *line, int *i, char quote)
{
	int	save;
	int	end;

	*i += 1;
	save = *i;
	while (line[*i] != quote)
		(*i)++;
	end = *i;
	while (save != end)
	{
		if (line[save] == ';')
			line[save] = -1;
		else if (line[save] == '|')
			line[save] = -2;
		else if (line[save] == '<')
			line[save] = -3;
		else if (line[save] == '>')
			line[save] = -4;
		save++;
	}
	(*i)++;
	return (line);
}

char	*encode_lines(char *line)
{
	int		end;
	int		i;

	i = 0;
	while (line[i])
	{
		while (line[i] == '\'')
			line = quote_encode(line, &i, '\'');	
		while (line[i] == '\"')
			line = quote_encode(line, &i, '\"');
		while (line[i] == '\'')
			line = quote_encode(line, &i, '\'');
		while (line[i] == '\"')
			line = quote_encode(line, &i, '\"');
		i++;
	}
	return (line);
}

char	**decode_lines(char **encode_lines)
{
	int	i;
	int	j;

	i = -1;
	while (encode_lines[++i])
	{
		j = -1;
		while (encode_lines[i][++j])
		{
			if (encode_lines[i][j] == -1)
				encode_lines[i][j] = ';';
			else if (encode_lines[i][j] == -2)
				encode_lines[i][j] = '|';
			else if (encode_lines[i][j] == -3)
				encode_lines[i][j] = '<';
			else if (encode_lines[i][j] == -4)
				encode_lines[i][j] = '>';
		}
	}
	return (encode_lines);
}
