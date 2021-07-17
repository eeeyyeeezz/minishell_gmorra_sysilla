/*
;;;;;	FT_ESCAPE.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"

int	chr_to_int(char s, char next)
{
	if (s == '|')
		return (2);
	else if (s == '<' && next == '<')
		return (6);
	else if (s == '<' && next != '<')
		return (3);
	else if (s == '>' && next == '>')
		return (5);
	else if (s == '>' && next != '>')
		return (4);
	return (-1);
}

int	count_arguments(char *line, int begin)
{
	int		count;
	int		end;
	int		i;

	i = 0;
	end = 0;
	count = 0;
	(void)begin;
	while (!ft_chr(line[end]) && line[end])
		end++;
	while (i < end)
	{
		while (ft_isspaces(line[i]))
			i++;
		while (ft_isalnum_new(line[i]) || line[i] == '\''
			|| line[i] == '\"' || line[i] < 0)
			i++;
		count++;
		i++;
	}
	return (count);
}

int	ft_chr(char s)
{
	if (s == '|' || s == '<' || s == '>')
		return (1);
	else
		return (0);
}

int	ft_escape(char s)
{
	if (s == 34 || s == 39 || s == 92)
		return (1);
	else
		return (0);
}
