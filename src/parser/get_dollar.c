/*
;;;;;	GET_DOLLAR.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"

static	void	skip_single_quote(char *line, int *i)
{
	*i += 1;
	while (line[*i] != '\'' && line[*i + 1])
		*i += 1;
	if (line[*i + 1])
		*i += 1;
}

char	*connect_dollar_string(char *str,
char *dollar_str, int begin, int get_strlen)
{
	char	*old_str;
	char	*new_str;
	char	*whole_str;
	int		count;
	int		i;

	i = -1;
	count = begin + get_strlen;
	old_str = malloc(sizeof(char) * begin + 1);
	if (!old_str)
		ft_error("Malloc Error!\n");
	while (++i != begin)
		old_str[i] = str[i];
	old_str[i] = '\0';
	if (dollar_str == NULL)
	{
		ft_free((void *)&str);
		return (old_str);
	}
	old_str = ft_strjoin_new(old_str, dollar_str);
	i = 0;
	if (str[count])
	{
		new_str = malloc(sizeof(char)
				* (ft_strlen(str) - (begin + get_strlen)) + 1);
		if (!new_str)
			ft_error("Malloc Error!\n");
		while (str[count])
			new_str[i++] = str[count++];
		new_str[i] = '\0';
		whole_str = ft_strjoin_new(old_str, new_str);
	}
	else
	{
		ft_free((void *)&str);
		return (old_str);
	}
	ft_free((void *)&new_str);
	ft_free((void *)&str);
	return (whole_str);
}

static	char	*double_quotes_dollar(t_struct *gl,
char *line, char *str, int *i)
{
	char	*dollar_str;
	int		end;

	end = itterate_end(gl, line, i, end);
	while (*i < end)
	{
		if (line[*i] == '$')
		{
			gl->flags.begin = *i;
			while (!ft_isspaces(line[*i]) && !(line[*i] == '\"') && line[*i])
				*i += 1;
			gl->flags.str_end = *i;
			dollar_str = ft_strndup((char *)&line[gl->flags.begin],
					gl->flags.str_end - gl->flags.begin);
			gl->flags.get_strlen = ft_strlen(dollar_str);
			str = dollar_error(gl, dollar_str, str);
			if (gl->flags.flag_dollar_error)
				return (str);
			dollar_str = change_dollar_string(gl, dollar_str);
			str = get_str(gl, str, dollar_str, gl->flags.begin);
		}
		*i += 1;
	}
	*i += 1;
	return (str);
}

char	*get_dollar(t_struct *global, char *line, char *str, int end)
{
	int		i;
	int		flag;
	char	*new_str;

	i = 0;
	flag = -1;
	while (line[i + 1] && i < end)
	{
		while (line[i] == '\'')
			skip_single_quote(line, &i);
		while (line[i] == '\"' && line[i + 1])
			str = double_quotes_dollar(global, line, str, &i);
		while (line[i] == '\'')
			skip_single_quote(line, &i);
		if (line[i] == '$')
			str = double_quotes_dollar(global, line, str, &i);
		i++;
	}
	return (str);
}
