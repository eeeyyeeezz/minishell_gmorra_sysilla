/*
;;;;;	GET_ARGS.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"

static	char	**get_two_array_commands(t_struct *global,
char **commands, char *line, int i)
{
	char	*free_str;

	if (line[i])
	{
		free_str = find_chr_commands(global, (char *)&line[i]);
		if (free_str)
		{
			ft_free((void *)&free_str);
			commands[global->flags.cmd_count++]
				= find_chr_commands(global, (char *)&line[i]);
		}
	}
	return (commands);
}

static	int	*get_characters(t_struct *global,
int *characters, char *line, int *i)
{
	if (line[*i])
	{
		characters[global->flags.chr_count]
			= chr_to_int(line[*i], line[*i + 1]);
		if (chr_to_int(line[*i], line[*i + 1]) == 5)
			*i += 1;
		if (chr_to_int(line[*i], line[*i + 1]) == 6)
			*i += 1;
		global->flags.chr_count++;
	}
	return (characters);
}

char	**get_all_commands(t_struct *global, char *line)
{
	int			i;
	char		**commands;
	int			*characters;

	i = 0;
	global->flags.chr_count = 0;
	global->flags.cmd_count = 0;
	commands = malloc(sizeof(char *) * count_malloc_chr(line) + 1);
	characters = malloc(sizeof(int) * count_malloc_chr(line) + 1);
	if (!commands || !characters)
		return (NULL);
	while (global->flags.cmd_count < count_malloc_chr(line))
	{
		commands = get_two_array_commands(global, commands, line, i);
		while (!ft_chr(line[i]) && line[i])
			i++;
		characters = get_characters(global, characters, line, &i);
		i++;
	}
	commands[global->flags.cmd_count] = 0;
	characters[global->flags.chr_count] = -1;
	characters[global->flags.chr_count + 1] = '\0';
	global->pars.chr = characters;
	return (commands);
}
