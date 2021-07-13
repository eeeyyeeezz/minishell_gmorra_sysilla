#include "../../includes/minishell.h"

char *builtin_str[] = {
	"cd",
	"export",
	"unset",
	"env",
	"echo",
	"exit"
};

int	lsh_num_builtins()
{
	return sizeof(builtin_str) / sizeof(char *);
}

int	builtin_func2(char **args, t_env *env, int i)
{
	if (i == 0)
		return (ft_cd(args, env));
	if (i == 1)
		return (ft_export(args, env));
	if (i == 2)
		return (ft_unset(args, env));
	if (i == 3)
		return (ft_env(args, env));
}

int	bildin(char **args, t_env *env)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if ((strcmp(args[0], builtin_str[i]) == 0) && i != 4 && i != 5)
			return (builtin_func2(args, env, i));
		if ((strcmp(args[0], builtin_str[i]) == 0) && i == 4)
			return (ft_echo(args));
		if ((strcmp(args[0], builtin_str[i]) == 0) && i == 5)		// ft_exit изменен
		{
			if (args[1])
				return (ft_exit(args));
			else
				return (ft_exit(NULL));
		}
	}
	return (0);
}

int	ex_path(char **args, t_env *env)
{
	char	**path;
	char	*path_ag;
	int		i;
	int		flag;

	path = ft_split(getenv("PATH"), ':');
	i = 0;
	flag = -1;
	while (path[i])
	{	
		path_ag = ft_strjoin_slash(path[i], args[0]);
		flag = execve(path_ag, args, env->sh_envp);
		free(path_ag);
		if (flag != -1)
			return (0);
		i++;
	}
	return (1);
}

void pipeline(char ***cmd, t_env *env)
{
	int fd[2];
	pid_t pid;
	int status;
	int fdd = 0;				/* Backup */

	while (*cmd != NULL)
	{
		pipe(fd);				/* Sharing bidiflow */
		if ((pid = fork()) == -1)
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{
			chld_sig();
			dup2(fdd, 0);
			if (*(cmd + 1) != NULL)
			{
				dup2(fd[1], 1);
			}
			close(fd[0]);
			if (ft_strnstr(&(*cmd)[0][0], "./", 2))
			{
				if (execve((*cmd)[0], &(*cmd)[0], env->sh_envp) == -1)
				{
					printf("minishell: no such file or directory: %s\n", (*cmd)[0]);
					strerror(1);
				}
				shlvl(env);
			}
			else if (!bildin(&(*cmd)[0], env) && !(ft_strnstr(&(*cmd)[0][0], "./", 2)))
			{
				// execvp((*cmd)[0], *cmd);
				// int e = ex_path(&(*cmd)[0], env);
				// printf("                    %d\n", e);
				if (ex_path(&(*cmd)[0], env))
					printf("minishell: %s command not found\n", (*cmd)[0]);
			}
			// else if (ft_strnstr(&(*cmd)[0][0], "./", 2))
			// {
			// 	if (execve((*cmd)[0], &(*cmd)[0], env->sh_envp) == -1)
			// 	{
			// 		printf("minishell: no such file or directory: %s\n", (*cmd)[0]);
			// 		strerror(1);
			// 	}
			// 	shlvl(env);
			// }
			exit(1);
		}
		else
		{
			signal(SIGINT, SIG_IGN);
			wait(NULL); 		/* Collect childs */
			// signal(SIGINT, SIG_IGN);
			// wait(&status);
			// if (WIFSIGNALED(status) != 0 && WTERMSIG(status) == SIGINT)
				// write(1, "\n", 1);
			// if (WIFSIGNALED(status) != 0 && WTERMSIG(status) == SIGQUIT)
				// write(1, "^Quit \n", 8);
			// if (WEXITSTATUS(status) == 0)
			// {
				close(fd[1]);
				fdd = fd[0];
				cmd++;
			// }
		}
	}
}