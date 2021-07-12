#include "../../includes/minishell.h"

// char *builtin_str[] = {
	// "cd",
	// "export",
	// "unset",
	// "env",
	// "echo",
	// "exit"
// };
// 
// int (*builtin_func[]) (char **, t_env *env) = {
	// &ft_cd,
	// &ft_export,
	// &ft_unset,
	// &ft_env
// };

int ft_isnum(char *str)
{
	int i;
	int j;

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

// int	lsh_num_builtins()
// {
	// return sizeof(builtin_str) / sizeof(char *);
// }

/*
	WUNTRACED - означает возврат управления и для остановленных (но не отслеживаемых) дочерних процессов, о статусе которых еще не было сообщено. Статус для отслеживаемых остановленных подпроцессов также обеспечивается без этой опции.
	WIFEXITED(status) - не равно нулю, если дочерний процесс успешно завершился.
	WIFSIGNALED(status) - возвращает истинное значение, если дочерний процесс завершился из-за необработанного сигнала.
*/

void	chld_sig(void)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
}

int lnch_pth(char *path_ag, char **args, char **envp)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		// Дочерний процесс
		chld_sig();
		if (execve(path_ag, args, envp) == -1)
		{
			exit(1);
		}
		exit(0);
	}
	// else if (pid < 0) {
		// Ошибка при форкинге
		// printf("%s", strerror(errno));
	// }
	else
	{
		// Родительский процесс
		signal(SIGINT, SIG_IGN);
		wait(&status);
		if (WIFSIGNALED(status) != 0 && WTERMSIG(status) == SIGINT)
			write(1, "\n", 1);
		if (WIFSIGNALED(status) != 0 && WTERMSIG(status) == SIGQUIT)
			write(1, "^Quit \n", 8);
		if (WEXITSTATUS(status) == 0)
			return (0);
		return (1);
	}
	// return (0);
}

int lsh_launch(char **args, char **envp, t_env *env)
{
	pid_t pid;
	int status;	
	pid = fork();
	if (pid == 0) {
		// Дочерний процесс
		chld_sig();
		if (execve(args[0], args, envp) == -1)
		{
			printf("minishell: no such file or directory: %s\n", args[0]);
			strerror(1);
		}
		shlvl(env);
		exit(EXIT_FAILURE);
	}
	// else if (pid < 0)
	// {
		// Ошибка при форкинге
		// printf("%s", strerror(errno));
	// }
	else
	{
		// Родительский процесс
		signal(SIGINT, SIG_IGN);
		wait(&status);
		if (WIFSIGNALED(status) != 0 && WTERMSIG(status) == SIGINT)
			write(1, "\n", 1);
		if (WIFSIGNALED(status) != 0 && WTERMSIG(status) == SIGQUIT)
			write(1, "^Quit \n", 8);
		if (WEXITSTATUS(status) == 0)
			return (0);
	}
	return (0);
}

int		exec_path(char **args, char **envp)
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
		flag = lnch_pth(path_ag, args, envp);
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

int lsh_execute(char **args, char **envp, t_env *env)
{
 	int i;

 	if (args[0] == NULL)
	{
 	  return (2);
 	}
	if ((ft_strnstr(args[0], "./", 2)))
		return (lsh_launch(args, env->sh_envp, env));
	if (!(ft_strnstr(args[0], "./", 2)) && !(bildin(args, env)))
	{
		if (exec_path(args, env->sh_envp))
			printf("minishell: %s command not found\n", args[0]);
		return (0);
	}
	return (1);
}
