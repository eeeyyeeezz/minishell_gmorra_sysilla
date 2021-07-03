#include "../../includes/minishell.h"

char *builtin_str[] = {
	"cd",
	"export",
	"unset",
	"env",
	"echo",
	"exit"
};

int (*builtin_func[]) (char **, t_env *env) = {
	&ft_cd,
	&ft_export,
	&ft_unset,
	&ft_env
};

int	lsh_num_builtins()
{
	return sizeof(builtin_str) / sizeof(char *);
}

int	bildin(char **args, t_env *env)
{
	int	i;
	// int	j;

	i = 0;
	while (i < 6)
	{
		if ((strcmp(args[0], builtin_str[i]) == 0) && i != 4 && i != 5)
		{
			(*builtin_func[i])(args, env);
			return (1);
		}
		if ((strcmp(args[0], builtin_str[i]) == 0) && i == 4)
		{
			ft_echo(args);
			return (1);
		}
		if ((strcmp(args[0], builtin_str[i]) == 0) && i == 5)		// ft_exit изменен
		{
			if (args[1])
				ft_exit(args[1]);
			ft_exit("0");
		}
		i++;
	}
	return (0);
}

int	ex_path(char **args, t_env *env)
{
	char	**path;
	char	*path_ag;
	int		i;

	path = ft_split(getenv("PATH"), ':');
	i = 0;
	while (path[i])
	{	
		path_ag = ft_strjoin_slash(path[i], args[0]);
		execve(path_ag, args, env->sh_envp);
		free(path_ag);
		i++;
	}
	return(0);
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
			if (!bildin(&(*cmd)[0], env) && !(ft_strnstr(&(*cmd)[0][0], "./", 2)))
			{
				// execvp((*cmd)[0], *cmd);
				ex_path(&(*cmd)[0], env);
			}
			else
			{
				if (execve((*cmd)[0], &(*cmd)[0], env->sh_envp) == -1)
				{
					printf("zsh: no such file or directory: %s\n", (*cmd)[0]);
					strerror(1);
				}
				shlvl(env);
			}				
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