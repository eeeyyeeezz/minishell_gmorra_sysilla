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


static	char		**get_all_commands(char *line, t_struct *global)
{
	int			i;
	int			count;
	int			count_chr;
	int			*characters;
	char		**commands;  
	i = 0;
	count = 0;
	count_chr = 0;
	// COUNT MALLOC CHAR NEPRAVILNO CHTITAET NO POCHEMUTO VSE OK???
	// printf("CMC? [%d]\n", count_malloc_chr(line));
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
	// for (int i = 0; commands[i]; i++)
		// printf("cmd [%s]\n", commands[i]);
	// for (int i = 0; characters[i]; i++)
		// printf("chr [%d]\n", characters[i]);
	// i = -1;
	// while (characters[++i])
	// {
	// 	// pars_add_back(&global->pars.chr, pars_st_new(characters[i]));
	// 	global->pars = *global->pars.next;
	// }
	// for (int i = 0; i <= count_malloc_chr(line); i++)
		// ft_free((void *)&commands[i]);
	// ft_free((void *)&commands);
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
		free(str);
		i++;
	}
	arg[++count] = 0;
		// for (int i = 0; global->pars.ft_arg[i]; i++)
		// printf("FT PARS [%d] [%s]\n", ft_arg, global->pars.ft_arg[i]);

	// for (int i = 0; arg[i]; i++)
		// free(arg[i]);
	// free(arg);			// LEAKS
	// ft_arg++;
	return (arg);
}

static	void		get_all_arguments(char *line, t_struct *global)
{
	static	int ft_arg;			// FT_ARG NEPRAVILNO ZANULYYAYU!!!!!
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
		for (int i = 0; arg[i]; i++)
			global->pars.ft_arg[ft_arg++] = arg[i];
		begin = end + 1;
		while (i != end)
			i++;
		end++;
	}
	printf("FT ARG [%d]\n", ft_arg);
	global->pars.ft_arg[ft_arg] = 0;
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
		return (-1);
	ft_free((void *)&str);
	if (global->pars.ft_cmd)
	{
		write(1, "ABOBAAAAAA", 10);
		for (int i = 0; global->pars.ft_arg[i]; i++)
			ft_free((void *)&global->pars.ft_arg[i]);
		ft_free((void *)&global->pars.ft_arg);
		for (int i = 0; global->pars.ft_cmd[i]; i++)
			ft_free((void *)&global->pars.ft_cmd[i]);
		ft_free((void *)&global->pars.ft_cmd);

	}
	global->pars.ft_cmd = get_all_commands(encode_line, global);	// leaks
	global->pars.ft_arg = malloc(sizeof(char *) * count_twodimarray(global));	
	get_all_arguments(encode_line, global);
	// for (int i = 0; global->pars.ft_arg[i]; i++)
		// printf("FT_ARGS [%s]\n", global->pars.ft_arg[i]);
	ft_free((void *)&encode_line);
	return (0);
}
