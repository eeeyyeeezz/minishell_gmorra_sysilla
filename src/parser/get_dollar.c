

#include "../../includes/minishell.h"

static	void	skip_single_quote(char *line, int *i)
{
	*i += 1;

	while (line[*i] != '\'' && line[*i + 1])
		*i += 1;
	if (line[*i + 1])
		*i += 1;
}


static	char	*connect_dollar_string(char *str, char *dollar_str, int begin, int get_strlen)
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
		new_str = malloc(sizeof(char) * (ft_strlen(str) - (begin + get_strlen)) + 1);
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
	// ft_free((void *)&old_str);
	ft_free((void *)&new_str);
	ft_free((void *)&str);
	return (whole_str);
	// str = whole_str;
}

static	char		*change_dollar_string(t_struct *global, char *dollar_string)
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

static	char		*double_quotes_dollar(t_struct *global, char *line, char *str, int *i)
{
	char	*dollar_str;
	int		flag_quote;
	int		get_strlen;
	int		str_end;
	int		begin;
	int		end;

	// printf("LINE [%s]\n", line);
	if (line[*i] == '\"')
	{
		flag_quote = 1;
		end = *i + 1;
		while (line[end] != '\"' && line[end]) 
			end++;
	}
	else 
	{
		flag_quote = 0;
		end = *i;
		while (line[end] && !ft_isspaces(line[end]))
			end++;
	}
	while (*i < end)
	{
		if (line[*i] == '$')
		{
			begin = *i;
			while (!ft_isspaces(line[*i]) && !(line[*i] == '\"') && line[*i])
				*i += 1;
			str_end = *i;
			dollar_str = ft_strndup((char *)&line[begin], str_end - begin);
			get_strlen = ft_strlen(dollar_str);		
			if (dollar_str[0] == '$' && dollar_str[1] == '?')
			{
				ft_free((void *)&str);
				str = ft_itoa(global->env.status);
				ft_free((void *)&dollar_str);
				return (str);
			}
			dollar_str = change_dollar_string(global, dollar_str);
			if (flag_quote)
				str = connect_dollar_string(str, dollar_str, begin - 1, get_strlen);
			else
			{
				if (dollar_str)
				{
					ft_free((void *)&str);
					str = ft_strdup(dollar_str);
					// ft_free((void *)&dollar_str);
				}
				else
				{
					ft_free((void *)&str);
					str = dollar_str;
				}
				// ft_free((void *)&dollar_str);
			}
			// ft_free((void *)&dollar_str);
		}
		*i += 1;
	}
	if (line[*i + 1])
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