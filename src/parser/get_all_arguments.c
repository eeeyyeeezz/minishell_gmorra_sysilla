/*
;;;;;	GET_ALL_ARGUMENTS.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"

static	void		array_to_three(t_struct *global, char **arg)
{
	if (global->flags.d_flag < count_twodimarray(global->pars.ft_cmd))
		global->pars.args[global->flags.d_flag++] = arg;
	else 
		global->flags.d_flag = 0;
}

char		**fill_all_arguments(t_struct *global, char *line)
{
	char	*str;
	char	*free_str;
	char	**arg;
	int		count;
	int		begin;
	int		end;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = 0;
	count = -1;
	if (!(arg = malloc(sizeof(char *) * count_arguments(line, 0) + 1)))
		ft_error("Malloc Error\n");
	end = 0;
	while (!ft_chr(line[end]) && line[end])
		end++;
	while (i < end)
	{
		while (ft_isspaces(line[i]) && line[i])
			i++;
		if (line[i] && !ft_chr(line[i]))
		{
			if ((free_str = find_chr_commands(global, (char *)&line[i])) != NULL)
			{
				ft_free((void *)&free_str);
				arg[++count] = find_chr_commands(global, (char *)&line[i]);
			}
		}
		while (line[i + 1] && !ft_isspaces(line[i]))
		{
			if (line[i] == '\'' || line[i] == '\"')
				i += skip_quote_i((char *)&line[i], line[i]);
			i++;
		}
		i++;
	}
	arg[++count] = 0;
	return (arg);
}

void		get_all_arguments(t_struct *global, char *line)
{
	char			**arg;
	int				begin;
	int				count;
	int				end;
	int				i;

	i = 0;
	end = 0;
	count = 0;
	begin = 0;
	global->flags.d_flag = 0;
	global->pars.args = malloc(sizeof(char ***) * 30);
	while (line[i])
	{
		if ((line[end] == '<' && line[end - 1] == '<') || 
		(line[end] == '>' && line[end - 1] == '>'))
			end+= 2;
		while (!ft_chr(line[end]) && line[end])
			end++;
		arg = fill_all_arguments(global, (char *)&line[begin]);
		array_to_three(global, arg);
		if ((line[end] == '<' && line[end + 1] == '<') || 
		(line[end] == '>' && line[end + 1] == '>'))
			begin = end + 2;
		else
			begin = end + 1;
		while (i != end)
			i++;
		end++;
	}
	global->pars.args[count_twodimarray(global->pars.ft_cmd)] = 0;
}		