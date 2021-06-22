#/*
#;;;;;	MAKEFILE.H
#;;;;;	gmorra/sysilla's minishell
#;;;;;	team created ???
#;;;;;	team locked ???
#*/
#include "../includes/minishell.h"

int				main(int argc, char **argv, char **env)
{
	t_struct global;

	global.fd = 1;
	global.pars.arg = NULL;
	ft_parser(&global);
	return (0);
}
