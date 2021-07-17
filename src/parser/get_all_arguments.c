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

static	int	plus_end(char *line, int end)
{
	if ((line[end] == '<' && line[end - 1] == '<')
		|| (line[end] == '>' && line[end - 1] == '>'))
		end += 2;
	while (!ft_chr(line[end]) && line[end])
		end++;
	return (end);
}

static	int	plus_begin(char *line, int begin, int end)
{
	if ((line[end] == '<' && line[end + 1] == '<')
		|| (line[end] == '>' && line[end + 1] == '>'))
		begin = end + 2;
	else
		begin = end + 1;
	return (begin);
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

char	**fill_all_arguments(t_struct *global, char *line)
{
	char	*free_str;
	char	**arg;
	int		count;
	int		end;
	int		i;

	i = 0;
	end = 0;
	count = -1;
	arg = malloc(sizeof(char *) * count_arguments(line, 0) + 1);
	if (!arg)
		ft_error("Malloc Error\n");
	while (!ft_chr(line[end]) && line[end])
		end++;
	while (i < end)
	{
		while (ft_isspaces(line[i]) && line[i])
			i++;
		if (line[i] && !ft_chr(line[i]))
		{
			free_str = find_chr_commands(global, (char *)&line[i]);
			if (free_str)
			{
				ft_free((void *)&free_str);
				arg[++count] = find_chr_commands(global, (char *)&line[i]);
			}
		}
		i = itterate_line(line, i);
	}
	arg[++count] = 0;
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
