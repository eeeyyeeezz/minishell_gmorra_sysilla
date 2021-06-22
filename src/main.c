#/*
#;;;;;	MAKEFILE.H
#;;;;;	gmorra/sysilla's minishell
#;;;;;	team created ???
#;;;;;	team locked ???
#*/

#include "../includes/minishell.h"

int				main(int argc, char **argv, char **envp)
{
	t_env env;
	t_struct global;

	global.fd = 1;
	global.pars.arg = NULL;
	global.env = envp;
	ft_bzero(&env, sizeof(env));
	ft_envp_cpy(envp, &env);
	ft_parser(&global);
	return (0);
}
