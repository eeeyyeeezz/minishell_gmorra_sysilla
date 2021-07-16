/*
;;;;;	UTILS.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"

void	init_all(t_struct *global)
{
	global->pars.args = NULL;
	global->pars.ft_cmd = NULL;
	global->pars.pipis = NULL;
	global->flags.ft_arg = 0;
	global->flags.ft_error = 0;
}

int			str_in_str(char *haystack, char *needle)
{
	int	i;
	int	count;

	count = 0;
	i = ft_strlen(needle) - 1;
	while (haystack[count] != '=')
		count++;
	count--;
	while (needle[i] == haystack[count])
	{
		i--;
		count--;
	}
	if (needle[i] == '$')
		return (1);
	else
		return (0);
}