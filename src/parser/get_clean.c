/*
;;;;;	GET_CLEAN.C
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

static	int					pars_single_quotes(char *line, t_struct *global)
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
	if (!str)
		ft_error("Malloc Error!\n");
	while (begin != end)
		str[i++] = line[begin++];
	str[i] = '\0';
	global->pars.info = ft_strjoin_new(global->pars.info, str);
	// ft_free((void *)&str);				// LEAKS??
	return (i + 2);
}

static	void				pars_info(char *line, t_struct *global)
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

static	void				find_info(char *line, t_struct *global)
{
	int i;
	int	double_quote;

	i = -1;
	double_quote = 0;
	// printf("line lol [%s]\n", line);
	while (line[++i])
	{
		if (line[i] == 34)			// || line[i] == 39 убрать позже || убрал
			double_quote++;
	}
	if (double_quote % 2 != 0)
			ft_error("Syntax error. Quotes not closed\n");
	else
		pars_info(line, global);
}

void	get_clean(t_struct *global, char **arg)
{
	int j;
	int i;

	i = -1;
	while (arg[++i])
	{
		j = 0;
		global->pars.info = malloc(1);
		global->pars.info[0] = 0;
		while (ft_isspaces(arg[i][j]))
			j++;
		find_info((char *)&arg[i][j], global);
		if (arg[i])
			ft_free((void *)&arg[i]);
		arg[i] = ft_strdup(global->pars.info);
		ft_free((void *)&global->pars.info);
		// printf("STR! [%s]\n", arg[i]);
	}
}

