/*
;;;;;	GET_DOLLAR_UTILS.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"

char	*change_dollar_string(t_struct *global, char *dollar_string)
{
	int		j;
	int		i;
	char	*dollar;
	char	*env_string;

	j = 0;
	i = 0;
	env_string = 0;
	while (global->env.sh_envp[i])
	{
		if (str_in_str(global->env.sh_envp[i], dollar_string))
		{
			while (global->env.sh_envp[i][j] != '=')
				j++;
			env_string = (char *)&global->env.sh_envp[i][j + 1];
			break ;
		}
		i++;
	}
	ft_free((void *)&dollar_string);
	return (env_string);
}

char	*get_str(t_struct *global, char *str, char *dollar_str, int begin)
{
	if (global->flags.flag_quote)
		str = connect_dollar_string(str, dollar_str,
				begin - 1, global->flags.get_strlen);
	else
	{
		if (dollar_str)
		{
			ft_free((void *)&str);
			str = ft_strdup(dollar_str);
		}
		else
		{
			ft_free((void *)&str);
			str = dollar_str;
		}
	}
	return (str);
}

int	itterate_end(t_struct *global, char *line, int *i, int end)
{
	if (line[*i] == '\"')
	{
		global->flags.flag_quote = 1;
		end = *i + 1;
		while (line[end] != '\"' && line[end])
			end++;
	}
	else
	{
		global->flags.flag_quote = 0;
		end = *i;
		while (line[end] && !ft_isspaces(line[end]))
			end++;
	}
	return (end);
}

char	*dollar_error(t_struct *global, char *dollar_str, char *str)
{
	global->flags.get_strlen = ft_strlen(dollar_str);
	global->flags.flag_dollar_error = 0;
	if (dollar_str[0] == '$' && dollar_str[1] == '?')
	{
		ft_free((void *)&str);
		str = ft_itoa(global->env.status);
		ft_free((void *)&dollar_str);
		global->flags.flag_dollar_error = 1;
		return (str);
	}
	else	
		return (str);
}