/*
;;;;;	GET_ARGS.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"

static int			skip_quote_i(char *line, char quote)
{
	int	i;

	i = 1;
	while (line[i] && line[i] != quote)
		i++;
	return (i);
}

char		*skip_quote(char *line, char *str, int *i, char quote)
{
	int		quote_end;

	(*i)++;
	quote_end = *i;
	// printf("LINE [%s] and i [%d]\n", line, *i);
	while (line[quote_end] != quote && line[quote_end])
		quote_end++;
	if (!line[quote_end])
		ft_error("Syntax Error! Quotes not closed\n");
	while (*i != quote_end)
		str = ft_strjoin_char(str, line[(*i)++]);			// boom
	(*i)++;
	return (str);
}



// static	void		array_to_struct(t_struct *global, char **arg)
// {
// 	for (int i = 0; arg[i]; i++)
// 	{
// 		global->pars.ft_arg[global->flags.ft_arg] = arg[i];		// leaks ??
// 		global->flags.ft_arg++;
// 	}
// }

static	void		array_to_three(t_struct *global, char **arg)
{
	if (d_flag < count_twodimarray(global->pars.ft_cmd))
		global->pars.dirty_array[d_flag++] = arg;
	else 
		d_flag = 0;
}

int		count_malloc_chr(char *line)
{
	int			malloc_count;
	int			i;

	malloc_count = 0;
	i = -1;
	if (!line[0])
		return (0);
	while (line[++i])
	{
		if (ft_chr(line[i]))
			malloc_count++;
		if (line[i] == '>' && line[i + 1] == '>')
			i++;
		if (line[i] == '<' && line[i + 1] == '<')
			i++;
	}
	malloc_count++;			// why not???
	return (malloc_count);
}

char	*find_chr_commands(char *line)			// LEAKS
{
	char		*str;
	int			quote_end;
	int			end;
	int			i;

	i = 0;
	str = 0;
	if (!(str = ft_calloc(1, sizeof(char *))))
		return (NULL);
	while (ft_isspaces(line[i]) && line[i])
		i++;
	end = i;
	while (!ft_isspaces(line[end]) && !ft_chr(line[end]) && line[end])
	{
		if (line[end] == '\'' || line[end] == '\"')
			end += skip_quote_i((char *)&line[end], line[end]);
		end++;
	}
	while (i != end)
	{
		if (line[i] == '\"')
			str = skip_quote(line, str, &i, '\"');
		else if (line[i] == '\'')
			str = skip_quote(line, str, &i, '\'');
		else
			str = ft_strjoin_char(str, line[i++]);
	}
	return (str);
}

void		count_pipes(t_struct *global, int *line)
{
	int	count;
	int	pipis;
	int	i;

	i = -1;
	count = 0;
	while (line[++i])
	{
		if (line[i] == 2)
			count++;
	}
	global->pars.pipis = malloc(sizeof(int) * count + 1);
	if (!global->pars.pipis)
		ft_error("Malloc Error!\n");
	global->pars.pipis[0] = count;
	i = -1;
	pipis = 1;
	if (count != 0)
	{
		while (line[++i])
		{
			if (line[i] == 2)
				global->pars.pipis[pipis++] = i + 1;
		}
	}
	if (count == 0)
		pipis = 0;
	global->pars.pipis[pipis] = '\0';
}


char		**get_all_commands(char *line, t_struct *global)
{
	int			i;
	int			count;
	int			count_cmd;
	int			count_chr;
	char		**commands;
	int			*characters;

	i = 0;
	count = 0;
	count_cmd = 0;
	count_chr = 0;
	if (!(commands = malloc(sizeof(char *) * count_malloc_chr(line) + 1)))		// leaks??
 		return (NULL);
	if (!(characters = malloc(sizeof(int) * count_malloc_chr(line) + 1)))
		return (NULL);
	while (count < count_malloc_chr(line))
	{
		if (line[i])
		{
			commands[count] = find_chr_commands((char *)&line[i]);
			count++;
		}
		while (!ft_chr(line[i]) && line[i])
			i++;
		if (line[i])
		{
			characters[count_chr] = chr_to_int(line[i], line[i + 1]);
			if (chr_to_int(line[i], line[i + 1]) == 5)
				i++;
			if (chr_to_int(line[i], line[i + 1]) == 6)
				i++;
			count_chr++;
		}
		i++;
	}
	commands[count] = 0;
	characters[count_chr] = -1;
	characters[count_chr + 1] = '\0';
	// for (int i = 0; characters[i]; i++)
	// 	printf("PIPISI))) [%d]\n", characters[i]);
	// for (int i = 0; commands[i]; i++)
	// 	printf("cmd lol [%s]\n", commands[i]);
	count_pipes(global, characters);
	ft_free((void *)&characters);
	return (commands);
}

static	int		get_true_end(char *line)
{
	int	i;

	i = 1;
	if (line[0] == '\'')
	{
		printf("LINE SUKA [%s]\n", line);
		while (line[i] != '\'' && line[i])
			i++;
		if (!line[i])
			ft_error("Chel)\n");
		else	
			return (i);
	}
	else if (line[0] == '\"')
	{
		while (line[i] != '\"' && line[i])
			i++;
		if (!line[i])
			ft_error("Double Chel)\n");
		else	
			return (i);
	}
	return (0);
}

char		**fill_all_arguments(t_struct *global, char *line)
{
	char	*str;
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
	// for (int i = 0; line[i]; i++)
	// 	printf("LOL END [%d]\n", i);
	while (!ft_chr(line[i]) && line[i])
	{
		while (ft_isspaces(line[i]) && line[i])
			i++;
		if (line[i])
		{
			// printf("po4emu guyzz [%s] [%i]\n", (char *)&line[i], i);
			arg[++count] = find_chr_commands((char *)&line[i]);
			// printf("OBAMA [%s] i [%d]\n", arg[count], i);
		}
		while (line[i + 1] && !ft_isspaces(line[i]))
		{
			if (line[i] == '\'' || line[i] == '\"')
				i += skip_quote_i((char *)&line[i], line[i]);
			// printf("VILET? [%d] [%s]\n", i, (char *)&line[i]);
			i++;
		}
		i++;
	}
	arg[++count] = 0;
	// print_double(arg, "Double");
	return (arg);
}

void		get_all_arguments(char *line, t_struct *global)
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
	d_flag = 0;
	global->pars.dirty_array = malloc(sizeof(char ***) * 30);
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
	global->pars.dirty_array[count_twodimarray(global->pars.ft_cmd)] = 0;
}		

// ""ec""ho"" "aboba" 1''2''3""""""'' >> t''1 | c""""at "-e"

// 'e''cho'"" a""b""o""ba '$KAVO'"cat -e | cat -e" >> 't1' > t2 << t3 yes | "c""at" '-e' >> " lol mda "
// "c""at" '-e' >> " lol mda " | pipeline visnet 
// ЕСЛИ В КАВЫЧКАХ ПРОБЕЛ ВИСНЕТ
// 'echo'"" 123 << "cat" "-e" - huynya || echo"" "123"'' << lol | fixed
// 'echo' 123  >> t1 - tozhe
// "ec""ho" 123 -- sega