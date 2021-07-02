/*
;;;;;	PARS_DOUBLE_QUOTES.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/
#include "../../includes/minishell.h"

static	void			check_escape(char *line)
{
	int i;
	int num;

	i = -1;
	while (line[++i])
	{
		num = 0;
		while (line[i++] == 92)
			num++;
		if (line[i] == '\"')
			break ;
		if (num == 3)
			ft_error("Syntax error. Escape\n");
	}
}

int						pars_double_quotes(char *line, t_struct *global)
{
	char	*str;
	int		begin;
	int		plus_i;
	int		end;
	int		i;

	i = 1;
	plus_i = 0;
	end = 0;
	begin = 1;
	check_escape(line);
	while (line[i])
	{
		if (line[i] == '"')
		{
			end = i;
			break ;
		}
		i++;
	}
	i = 0;
	str = malloc(sizeof(char) * (end - begin) + 1);
	while (begin != end)
	{
		if (line[begin] == 92)
		{
			begin++;
			plus_i++;
		}
		str[i++] = line[begin++];
	}
	str[i] = '\0';
	// i = -1;
	// while (str[++i])
	// {
	// 	if (str[i] == '$' && str[i + 1] != '$')
	// 		str = pars_dollar_sign(str, global);
	// }
	global->pars.info = ft_strjoin_new(global->pars.info, str);
	ft_free((void *)&str);
	return (i + plus_i + 2);
}
