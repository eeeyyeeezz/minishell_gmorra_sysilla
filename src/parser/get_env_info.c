/*
;;;;;	GET_ENV_INFO.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"

static	char			*check_dollar_info(char *str, t_struct *global)
{
	int		j;
	int		i;
	char	*env_string;

	j = 0;
	i = 0;
	env_string = 0;
	while (global->env.sh_envp[i])
	{
		if (ft_strnstr(global->env.sh_envp[i], str + 1, ft_strlen(str)))
		{
			while (global->env.sh_envp[i][j] != '=')
				j++;
			env_string = (char *)&global->env.sh_envp[i][j + 1];
			break ;
		}
		i++;
	}
	return (env_string);
}

static	char			*change_string_with_env(char *str, char *env_string, int begin, int end)
{
	short	int		i;
	char			*first_string;
	char			*second_string;
	char			*new_string;

	i = 0;
	new_string = 0;
	if (!(first_string = malloc(sizeof(char) * begin + 1)))
		return (NULL);
	if (!(second_string = malloc(sizeof(char) * (ft_strlen(str) - end + 1))))
		return (NULL);
	while (i != begin)
	{
		first_string[i] = str[i];
		i++;
	}
	first_string[i] = '\0';
	i = 0;
	while (str[end] != '\0')
		second_string[i++] = str[end++];
	second_string[i] = '\0';
	new_string = ft_strjoin_new(first_string, env_string);
	new_string = ft_strjoin_new(new_string, second_string);
	return (new_string);
}

char			*pars_dollar_sign(char *str, t_struct *global)
{
	char	*env_string;
	char	*new_string;
	char	*tmp;
	short	int		begin;
	short	int		save_begin;
	short	int		flag;
	short	int		end;
	short	int		j;
	short	int		i;

	flag = 0;
	j = 0;
	i = -1;
	new_string = 0;
	env_string = 0;
	while (str[++i] && !flag)
	{
		if (str[i] == '$' && str[i + 1] != ' ')
		{
			begin = i;
			save_begin = begin;
			while (str[i] != ' ' && str[i])
				i++;
			end = i;
			if (!(env_string = malloc(sizeof(char) * (end - begin) + 1)))
				return (NULL);
			while (save_begin != end)
				env_string[j++] = str[save_begin++];
			env_string[j] = '\0';
			flag = 1;
		}
	}
	tmp = env_string;
	env_string = check_dollar_info(env_string, global);
	new_string = change_string_with_env(str, env_string, begin, end);
	ft_free((void *)&tmp);
	return (new_string);
}
