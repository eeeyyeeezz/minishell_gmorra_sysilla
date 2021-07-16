#include "../../includes/minishell.h"

int	ch_dir(char *av, char **env, t_env *envp)
{
	int		res;
	char	*oldpwd;
	char	dir[255];

	oldpwd = ft_strmasschr_char("PWD", envp->sh_envp, 3);
	add_to_env("OLDPWD=", &oldpwd[4], envp);
	res = chdir(av);
	if (res == 0)
	{
		getcwd(dir, 255);
		add_to_env("PWD=", dir, envp);
	}
	else
	{
		envp->status = 1;
		printf("minishell: cd: %s: No such file or directory\n", av);
	}
	free(oldpwd);
	return (0);
}

int	av_2(char *home, char **argv, t_env *sh_env)
{
	ft_putstr_fd("cd: string not in pwd: ", 1);
	ft_putendl_fd(argv[1], 1);
	sh_env->status = 1;
	free(home);
	return (2);
}

int	ft_cd(char **argv, t_env *sh_env)
{
	char	*home;

	home = ft_strmasschr_char("HOME", sh_env->sh_envp, 4);
	if (!home)
	{
		ft_putendl_fd("minishell: cd: HOME not set", 1);
		sh_env->status = 1;
		free(home);
		return (2);
	}
	if (!argv[1])
	{
		ch_dir(&home[5], sh_env->sh_envp, sh_env);
		free(home);
		return (2);
	}
	if (argv[2])
	{
		return (av_2(home, argv, sh_env));
	}
	ch_dir(argv[1], sh_env->sh_envp, sh_env);
	free(home);
	return (1);
}
