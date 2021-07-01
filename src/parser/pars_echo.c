/*
;;;;;	MAKEFILE.H
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"

static	void		single_quote_check_error(char *line)
{
	int i;
	int num;

	i = -1;
	num = 0;
	while (line[++i])
	{
		if (line[i] == '\'')
			num++;
	}
	if (num % 2 != 0)
	{
		ft_error("Syntax error. Quotes not closed\n");
		exit(0);
	}
}

int					pars_single_quotes(char *line, t_struct *global)
{
	int		i;
	int		begin;
	int		end;
	char	*str;

	i = 1;
	end = 0;
	begin = i;
	single_quote_check_error(line);
	while (line[i])
	{
		if (line[i] == '\'')
		{
			end = i;
			break ;
		}
		i++;
	}
	i = 0;
	str = malloc(sizeof(char) * (end - begin) + 1);
	while (begin != end)
		str[i++] = line[begin++];
	str[i] = '\0';
	printf("str lol [%s]\n", str);
	// global->pars.info = ft_strjoin_new(global->pars.info, str);
	ft_free((void *)&str);				// LEAKS??
	return (i + 2);
}

void				pars_info(char *line, t_struct *global, int malloc_count)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\"')
			i += pars_double_quotes((char *)&line[i], global);
		else if (line[i] == '\'')
			i += pars_single_quotes((char *)&line[i], global);
		else if (line[i] != '\'' && line[i] != '\"')
		{
			i += pars_without_quotes((char *)&line[i], global);
			if (i == 0)
				break ;
		}
	}
}

void				find_info_echo(char *line, t_struct *global)
{
	int i;
	int	malloc_count;
	int	double_quote;

	i = -1;
	malloc_count = 0;
	double_quote = 0;
	while (line[++i])
	{
		if (line[i] == 34)			// || line[i] == 39 убрать позже || убрал
			double_quote++;
		malloc_count++;
	}
	malloc_count -= double_quote;
	if (double_quote % 2 != 0)
			ft_error("Syntax error. Quotes not closed\n");
	else
		pars_info(line, global, malloc_count);
}

void				pars_echo(char *line, t_struct *global)
{
	int i;

	i = 0;
	i = skip_cmd(line, "echo");
	while (ft_isspaces(line[i]))
		i++;
	find_info_echo((char *)&line[i], global);
}
