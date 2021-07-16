#include "../../includes/minishell.h"

int	ft_isnum(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (!(str[i] <= '9' && str[i] >= '0'))
			j++;
		i++;
	}
	if (j != 0)
		return (1);
	return (0);
}

void	chld_sig(void)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
}

int	par_process(t_env *env)
{
	signal(SIGINT, SIG_IGN);
	wait(&env->status);
	if (WIFSIGNALED(env->status) != 0 && WTERMSIG(env->status) == SIGINT)
		write(1, "\n", 1);
	if (WIFSIGNALED(env->status) != 0 && WTERMSIG(env->status) == SIGQUIT)
		write(1, "^Quit \n", 8);
	if (WEXITSTATUS(env->status) == 0)
		return (0);
	return (1);
}

int	lnch_pth(char *path_ag, char **args, char **envp, t_env *env)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		chld_sig();
		if (execve(path_ag, args, envp) == -1)
		{
			exit(1);
		}
		exit(0);
	}
	else
		return (par_process(env));
	return (0);
}

int	lsh_launch(char **args, char **envp, t_env *env)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		chld_sig();
		if (execve(args[0], args, envp) == -1)
		{
			printf("minishell: no such file or directory: %s\n", args[0]);
			strerror(1);
		}
		shlvl(env);
		printf("a chto zvuchit haypovo12312321 [%s]\n", env->sh_envp[13]);
		exit(EXIT_FAILURE);
	}
	else
	{
		return (par_process(env));
	}
	printf("SMEEEERT'\n");
	return (0);
}

int	exec_path(char **args, char **envp, t_env *env)
{
	char	**path;
	char	*path_ag;
	int		i;
	int		flag;

	path = ft_split(getenv("PATH"), ':');
	i = 0;
	flag = 0;
	while (path[i])
	{	
		path_ag = ft_strjoin_slash(path[i], args[0]);
		flag = lnch_pth(path_ag, args, envp, env);
		free(path_ag);
		if (flag == 0)
		{
			freemass(path);
			return (0);
		}
		i++;
	}
	freemass(path);
	return (1);
}

int	lsh_execute(char **args, char **envp, t_struct *global)
{
	int	i;

	if (args[0] == NULL)
	{
		return (2);
	}
	if ((ft_strnstr(args[0], "./", 2)))
		return (lsh_launch(args, global->env.sh_envp, &global->env));
	if (!(ft_strnstr(args[0], "./", 2)) && !(bildin(args, &global->env)))
	{
		if (exec_path(args, global->env.sh_envp, &global->env))
		{
			printf("minishell: %s command not found\n", args[0]);
			global->env.status = 127;
		}
		return (0);
	}
	return (1);
}
