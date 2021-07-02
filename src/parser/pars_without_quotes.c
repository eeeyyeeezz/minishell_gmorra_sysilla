/*
;;;;;	MAKEFILE.H
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"

static int				check_count(char *line)
{
	short	int	count;
	short	int	i;

	i = 0;
	count = 0;
	while (line[i] != '\0' && count == 0)
	{
		while (!ft_isalnum(line[i]))
			i++;
		while (ft_isalnum(line[i]))
			i++;
		if (line[i] != '\0')
			count++;
	}
	return (count);
}

int						pars_without_quotes(char *line, t_struct *global)
{
	short	int		i;
	short	int		end;
	short	int		count;
	char			*str;

	i = 0;
	count = 5;
	// count = check_count(global->pars.first_line);
	end = i;
	if (count > 0)
	{
		while (line[end] != '"' && line[end] != '\'' && line[end])
			end++;
		str = malloc(sizeof(char) * (end - i) + 1);
		while (i != end)
		{
			str[i] = line[i];
			i++;
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
	}
	return (end);
}
