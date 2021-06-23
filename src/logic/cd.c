#/*
#;;;;;	MAKEFILE.H
#;;;;;	gmorra/sysilla's minishell
#;;;;;	team created ???
#;;;;;	team locked ???
#*/

#include "../../includes/minishell.h"

int	ch_dir(char *av, char **env)
{
	int		res;
	char	*oldpwd;
	char	dir[255];

	oldpwd = getenv("PWD");
	res = chdir(av);
	if (!res)
	{
		getcwd(dir, 255);
		// ft_putstr_fd(dir, 1);
	}
	return (0);
}

int	ft_cd(char **argv, t_env *sh_env)
{
	char	*home;

	home = getenv("HOME");
	if (!argv[1])
	{
		ch_dir(home, sh_env->sh_envp);
		return (1);
	}
	if (argv[2])
	{
		ft_putstr_fd("cd: string not in pwd: ", 1);
		ft_putendl_fd(argv[1], 1);
		return (1);
	}
	ch_dir(argv[1], sh_env->sh_envp);
	return (1);
}