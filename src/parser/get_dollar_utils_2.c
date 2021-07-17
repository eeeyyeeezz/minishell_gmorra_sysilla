/*
;;;;;	GET_DOLLAR_UTILS.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"

void	skip_single_quote(char *line, int *i)
{
	*i += 1;
	while (line[*i] != '\'' && line[*i + 1])
		*i += 1;
	if (line[*i + 1])
		*i += 1;
}

char	*get_whole_str(char *str,
char *old_str, int begin, int get_strlen)
{
	char	*whole_str;
	char	*new_str;
	int		count;
	int		i;

	i = 0;
	count = begin + get_strlen;
	new_str = malloc(sizeof(char)
			* (ft_strlen(str) - (begin + get_strlen)) + 1);
	if (!new_str)
		ft_error("Malloc Error!\n");
	while (str[count])
		new_str[i++] = str[count++];
	new_str[i] = '\0';
	whole_str = ft_strjoin_new(old_str, new_str);
	ft_free((void *)&new_str);
	return (whole_str);
}

char	*get_old_str(char *str, int begin)
{
	char	*old_str;
	int		i;

	i = -1;
	old_str = malloc(sizeof(char) * begin + 1);
	if (!old_str)
		ft_error("Malloc Error!\n");
	while (++i != begin)
		old_str[i] = str[i];
	old_str[i] = '\0';
	return (old_str);
}
