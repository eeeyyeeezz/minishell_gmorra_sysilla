#/*
#;;;;;	MAKEFILE.H
#;;;;;	gmorra/sysilla's minishell
#;;;;;	team created ???
#;;;;;	team locked ???
#*/

#include "../includes/minishell.h"

int				main(int argc, char **argv, char **envp)
{
	t_sh tsh;
	t_env env;
	t_struct global;

	global.fd = 1;
	global.pars.arg = NULL;
	global.env = envp;
	ft_bzero(&env, sizeof(env));
	ft_envp_cpy(envp, &env);
	shlvl(&env);
	tsh.sh_lvl = ft_atoi(env.sh_lvl);
	tsh.sh_mdepth = tsh.sh_lvl;
	ft_parser(&global, envp, &env);
	return (0);
}
