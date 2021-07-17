#include "../../includes/minishell.h"

int	par_process(t_env *env)
{
	signal(SIGINT, SIG_IGN);
	wait(&env->status);
	if (env->status == 256)
		env->status = 1;
	if (WIFSIGNALED(env->status) != 0 && WTERMSIG(env->status) == SIGINT)
		write(1, "\n", 1);
	if (WIFSIGNALED(env->status) != 0 && WTERMSIG(env->status) == SIGQUIT)
		write(1, "^Quit \n", 8);
	if (WEXITSTATUS(env->status) == 12)
		env->cn = 1;
	if (WEXITSTATUS(env->status) == 0 || WEXITSTATUS(env->status) == 1)
	{
		env->cn = -1;
		return (0);
	}
	return (1);
}

int	lnch_pth(char *path_ag, char **args, char **envp, t_env *env)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		chld_sig();
		if (execve(path_ag, args, envp) == -1)
		{
			exit(12);
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
		exit(EXIT_FAILURE);
	}
	else
	{
		return (par_process(env));
	}
	return (0);
}

int	exec_path(char **args, char **envp, t_env *env)
{
	char	**path;
	char	*path_ag;
	int		i;

	path = ft_split(getenv("PATH"), ':');
	i = 0;
	while (path[i])
	{
		if (!(ft_strnstr(args[0], "/bin", 5)))
		{
			path_ag = ft_strjoin_slash(path[i], args[0]);
			lnch_pth(path_ag, args, envp, env);
			free(path_ag);
		}
		else
			lnch_pth(args[0], args, envp, env);
		if (env->cn == -1)
		{
			freemass(path);
			return (0);
		}
		i++;
	}
	freemass(path);
	return (1);
}

int	lsh_execute(char **args, t_struct *global)
{
	if (args[0] == NULL)
	{
		return (2);
	}
	if ((ft_strnstr(args[0], "./", 2)))
		return (lsh_launch(args, global->env.sh_envp, &global->env));
	if (!(ft_strnstr(args[0], "./", 2)) && !(bildin(args, &global->env)))
	{
		exec_path(args, global->env.sh_envp, &global->env);
		if (global->env.cn == 1)
		{
			printf("minishell: %s command not found\n", args[0]);
			global->env.status = 127;
		}
		return (0);
	}
	return (1);
}
