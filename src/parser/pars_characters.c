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
	return (arg);
}

static	void		array_to_struct(t_struct *global, char **arg)
{
	for (int i = 0; arg[i]; i++)
	{
		global->pars.ft_arg[global->flags.ft_arg] = arg[i];		// leaks ??
		// printf("C4ET4IK [%d] [%s] [%s]\n", global->flags.ft_arg, arg[i], global->pars.ft_arg[global->flags.ft_arg]);
		global->flags.ft_arg++;
	}
}

static	void		get_all_arguments(char *line, t_struct *global)
{
<<<<<<< HEAD
	static	int ft_arg;			// FT_ARG NEPRAVILNO ZANULYYAYU!!!!!
=======
>>>>>>> 479a6df151031226d4228a264d081f1f320b82ed
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
		// for (int i = 0; arg[i]; i++)
		// 	printf("DVUM [%s]\n", arg[i]);
		array_to_struct(global, arg);
		begin = end + 1;
		while (i != end)
			i++;
		end++;
	}
<<<<<<< HEAD
	printf("FT ARG [%d]\n", ft_arg);
	global->pars.ft_arg[ft_arg] = 0;
=======
	// if (arg)			// в случае ничего в строке зайдет?
	// {
	// 	if (arg[1] == NULL)
	// 	{
	// 		free(arg);
	// 	}
	// 	for (int i = 0; arg[i]; i++)
	// 	{
	// 		free(arg[i]);
	// 		arg[i] = NULL;
	// 	}
	// 	free(arg);
	// 	arg = NULL;
	// }
	printf("ZANUL [%d]\n", global->flags.ft_arg);
	global->pars.ft_arg[global->flags.ft_arg] = NULL;
>>>>>>> 479a6df151031226d4228a264d081f1f320b82ed
}

static int		count_twodimarray(t_struct *global)
{
	int i;

	i = 0;
	while (global->pars.ft_cmd[i])
		i++;
	return (i);
}

static	void	free_ft_arg(t_struct *global)
{
	if (global->pars.ft_arg)
	{
		for (int i = 0; global->pars.ft_arg[i] != NULL; i++)
			printf("STROKA [%s]\n", global->pars.ft_arg[i]);
		write(1, "ARG FREE\n", 9);
		for (int i = 0; global->pars.ft_arg[i] != NULL; i++)
		{
			// printf("ARGS [%s]\n", global->pars.ft_arg[i]);
			free(global->pars.ft_arg[i]);
			write(1, "ok\n", 3);
		}
		free(global->pars.ft_arg);
	}
}

static	void	free_ft_cmd(t_struct *global)
{
	if (global->pars.ft_cmd)
	{
		write(1, "CMD FREE\n", 9);
		for (int i = 0; global->pars.ft_cmd[i]; i++)
			ft_free((void *)&global->pars.ft_cmd[i]);
		ft_free((void *)&global->pars.ft_cmd);
	}
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
	// free_ft_arg(global);
	// free_ft_cmd(global);	
	global->pars.ft_cmd = get_all_commands(encode_line, global);	// leaks
	global->pars.ft_arg = malloc(sizeof(char *) * count_twodimarray(global) + 1);
	if (!global->pars.ft_arg)
		ft_error("Malloc Error!\n");	
	printf("twodim [%d]\n", count_twodimarray(global) + 1);
	get_all_arguments(encode_line, global);
	for (int i = 0; global->pars.ft_arg[i]; i++)
		printf("FT_ARGS [%s]\n", global->pars.ft_arg[i]);
	ft_free((void *)&encode_line);
	return (0);
}
