/*
;;;;;	GET_ALL_ARGUMENTS.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"

static	void	array_to_three(t_struct *global, char **arg)
{
	if (global->flags.d_flag < count_twodimarray(global->pars.ft_cmd))
		global->pars.args[global->flags.d_flag++] = arg;
	else
		global->flags.d_flag = 0;
}

static	int	itterate_line(char *line, int i)
{
	while (line[i + 1] && !ft_isspaces(line[i]))
	{	
		if (line[i] == '\'' || line[i] == '\"')
			i += skip_quote_i((char *)&line[i], line[i]);
		i++;
	}
	i++;
	return (i);
}

static	char	**get_two_array(t_struct *global, char **arg, char *line, int i)
{
	char	*free_str;

	if (line[i] && !ft_chr(line[i]))
	{
		free_str = find_chr_commands(global, (char *)&line[i]);
		if (free_str)
		{
			ft_free((void *)&free_str);
			arg[++global->flags.count]
				= find_chr_commands(global, (char *)&line[i]);
		}
	}
	return (arg);
}

char	**fill_all_arguments(t_struct *global, char *line)
{
	char	**arg;
	int		end;
	int		i;

	i = 0;
	end = 0;
	global->flags.count = -1;
	arg = malloc(sizeof(char *) * count_arguments(line, 0) + 1);
	if (!arg)
		ft_error("Malloc Error\n");
	while (!ft_chr(line[end]) && line[end])
		end++;
	while (i < end)
	{
		while (ft_isspaces(line[i]) && line[i])
			i++;
		arg = get_two_array(global, arg, line, i);
		i = itterate_line(line, i);
	}
	arg[++global->flags.count] = 0;
	return (arg);
}

void	get_all_arguments(t_struct *global, char *line)
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
		end = plus_end(line, end);
		arg = fill_all_arguments(global, (char *)&line[begin]);
		array_to_three(global, arg);
		begin = plus_begin(line, begin, end);
		while (i != end)
			i++;
		end++;
	}
	global->pars.args[count_twodimarray(global->pars.ft_cmd)] = 0;
}
