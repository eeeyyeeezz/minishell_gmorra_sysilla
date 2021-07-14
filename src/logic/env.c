#/*
#;;;;;	MAKEFILE.H
#;;;;;	gmorra/sysilla's minishell
#;;;;;	team created ???
#;;;;;	team locked ???
#*/

#include "../../includes/minishell.h"

int	ft_env(char **av, t_env *env)
{
	int	i;

	if (av[1])
	{
		ft_putstr_fd("illegal option -", 1);
		ft_putendl_fd(av[1], 1);
		env->status = 1;
		return(1);
	}	
	i = 0;
	while (env->sh_envp[i])
	{
		ft_putendl_fd(env->sh_envp[i], 1);
		i++;
	}
	return (0);
}
