/*
;;;;;	FIND_REDIRECTS_PIPES.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"

void			find_redirects_pipes(t_struct *global, char *line)
{
	global->flags.ft_cmd = 0;
	global->flags.ft_arg = 0;
	pars_characters(global, line);
}
