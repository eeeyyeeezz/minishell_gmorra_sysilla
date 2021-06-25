/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_characters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:24:56 by gmorra            #+#    #+#             */
/*   Updated: 2021/04/19 15:04:20 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static	int		count_malloc_chr(char *line)
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
	}
	malloc_count++;			// why not???
	return (malloc_count);
}

static	char	*find_chr_commands(char *line)			// LEAKS
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
		end++;
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

static	void		count_pipes(t_struct *global, int *line)
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
	printf("lolcount [%d] pipis [%d]\n", count, pipis);
	for (int i = 0; global->pars.pipis[i]; i++)
		printf("PIPIS)) [%d]\n", global->pars.pipis[i]);
}

static	char		**get_all_commands(char *line, t_struct *global)
{
	int			i;
	int			count;
	int			count_chr;
	char		**commands;
	int			*characters;

	i = 0;
	count = 0;
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
			count_chr++;
		}
		i++;
	}
	commands[count] = 0;
	characters[count_chr] = -1;
	characters[count_chr + 1] = '\0';
	count_pipes(global, characters);
	ft_free((void *)&characters);
	return (commands);
}

static	char		**fill_all_arguments(t_struct *global, char *line)
{
	// static	int ft_arg;
	char	*str;
	char	**arg;
	int		end_fill;
	int		count;
	int		begin;
	int		end;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = 0;
	count = -1;
	end_fill = 0;
	while (!ft_chr(line[end_fill]) && line[end_fill])
		end_fill++;
	if (!(arg = malloc(sizeof(char *) * count_arguments(line, 0) + 1)))
		ft_error("Malloc Error\n");
	while (i < end_fill)
	{
		while (ft_isspaces(line[i]) && line[i])
			i++;
		begin = i;
		while (ft_isalnum_new(line[i]) || line[i] == '\''
		|| line[i] == '\"' || line[i] < 0)
			i++;
		end = i;
		if (!(str = malloc(sizeof(char) * (end - begin) + 1)))
			return (NULL);
		j = 0;
		// printf("BEGIN [%d] end [%d]\n", begin, end);
		while (begin != end)
			str[j++] = line[begin++];
		str[j] = '\0';
		if (str[0])
			arg[++count] = ft_strdup(str);			// leaks
		ft_free((void *)&str);
		i++;
	}
	arg[++count] = 0;
	return (arg);
}

static	void		array_to_struct(t_struct *global, char **arg)
{
	for (int i = 0; arg[i]; i++)
	{
		global->pars.ft_arg[global->flags.ft_arg] = arg[i];		// leaks ??
		global->flags.ft_arg++;
	}
}

static	void		get_all_arguments(char *line, t_struct *global)
{
	char		**arg;
	int			begin;
	int			count;
	int			end;
	int			i;

	i = 0;
	end = 0;
	count = 0;
	begin = 0;
	while (line[i])
	{
		while (!ft_chr(line[end]) && line[end])
			end++;
		arg = fill_all_arguments(global, (char *)&line[begin]);
		array_to_struct(global, arg);
		ft_free((void *)&arg);			// boom?
		begin = end + 1;
		while (i != end)
			i++;
		end++;
	}
	global->pars.ft_arg[global->flags.ft_arg] = 0;
}

static int		count_twodimarray(t_struct *global)
{
	int i;

	i = 0;
	while (global->pars.ft_cmd[i])
		i++;
	return (i);
}

int				pars_characters(t_struct *global, char *line)
{
	int		i;
	char	*str;
	char	*encode_line;

	i = -1;
	if (!(str = ft_strdup(line)))				// leaks??
		return (-1);
	if (!(encode_line = encode_lines(ft_strdup(str))))
		ft_error("Malloc Error!\n");
	ft_free((void *)&str);
	global->pars.ft_cmd = get_all_commands(encode_line, global);	// leaks
	global->pars.ft_arg = malloc(sizeof(char *) * 100);
	if (!global->pars.ft_arg)
		ft_error("Malloc Error!\n");	
	get_all_arguments(encode_line, global);
	ft_free((void *)&encode_line);
	return (0);
}
