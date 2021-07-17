/*
;;;;;	PLUS_END_BEGIN.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"

int	plus_end(char *line, int end)
{
	if ((line[end] == '<' && line[end - 1] == '<')
		|| (line[end] == '>' && line[end - 1] == '>'))
		end += 2;
	while (!ft_chr(line[end]) && line[end])
		end++;
	return (end);
}

int	plus_begin(char *line, int begin, int end)
{
	if ((line[end] == '<' && line[end + 1] == '<')
		|| (line[end] == '>' && line[end + 1] == '>'))
		begin = end + 2;
	else
		begin = end + 1;
	return (begin);
}
