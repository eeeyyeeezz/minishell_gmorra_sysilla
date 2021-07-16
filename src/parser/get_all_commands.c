/*
;;;;;	GET_ARGS.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"

char		**get_all_commands(t_struct *global, char *line)
{
	int			i;
	int			count;
	int			count_cmd;
	int			count_chr;
	char		**commands;
	char		*free_str;
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
			if ((free_str = find_chr_commands(global, (char *)&line[i])))
			{
				ft_free((void *)&free_str);
				commands[count++] = find_chr_commands(global, (char *)&line[i]);
			}
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
	global->pars.chr = characters;
	return (commands);
}
