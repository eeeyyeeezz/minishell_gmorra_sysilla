#include "../../includes/minishell.h"

char *builtin_str2[] = {
	"cd",
	"export",
	"unset",
	"env",
	"echo",
	"exit"
};

int (*builtin_func2[]) (char **, t_env *env) = {
	&ft_cd,
	&ft_export,
	&ft_unset,
	&ft_env
};

// int ft_isnum(char *str)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	while (str[i])
// 	{
// 		if (!(str[i] <= '9' && str[i] >= '0'))
// 			j++;
// 		i++;
// 	}
// 	if (j != 0)
// 		return (1);
// 	return (0);
// }

// int	lsh_num_builtins()
// {
// 	return sizeof(builtin_str) / sizeof(char *);
// }

/*
	WUNTRACED - означает возврат управления и для остановленных (но не отслеживаемых) дочерних процессов, о статусе которых еще не было сообщено. Статус для отслеживаемых остановленных подпроцессов также обеспечивается без этой опции.
	WIFEXITED(status) - не равно нулю, если дочерний процесс успешно завершился.
	WIFSIGNALED(status) - возвращает истинное значение, если дочерний процесс завершился из-за необработанного сигнала.
*/

// void	chld_sig(void)
// {
// 	signal(SIGQUIT, SIG_DFL);
// 	signal(SIGINT, SIG_DFL);
// }

int lnch_pth_pip(char *path_ag, char **args, char **envp)
{
		// Дочерний процесс
		if (execve(path_ag, args, envp) == -1)
		{
			strerror(1);
		}
	return (0);
}

int lsh_launch_pip(char **args, char **envp, t_env *env)
{
		if (execve(args[0], args, envp) == -1)
		{
			printf("zsh: no such file or directory: %s\n", args[0]);
			strerror(1);
		}
		shlvl(env);
		exit(EXIT_FAILURE);
	return 3;
}

// int		exec_path(char **args, char **envp)
// {
// 	char	**path;
// 	char	*path_ag;
// 	int		i;
// 	int		flag;

// 	path = ft_split(getenv("PATH"), ':');
// 	i = 0;
// 	flag = 0;
// 	while (path[i])
// 	{	
// 		path_ag = ft_strjoin_slash(path[i], args[0]);
// 		if (lnch_pth(path_ag, args, envp))
// 			flag++;
// 		free(path_ag);
// 		i++;
// 	}
// 	freemass(path);
// 	if (flag == 0)
// 		printf("minishel: %s: command not found", args[0]);
// 	return (3);
// }

int lsh_execute_pipe(char **args, char **envp, t_env *env)
{
 	int i;

 	if (args[0] == NULL)
	{
 	  return (2);
 	}
	if (!(ft_strnstr(args[0], "./", 2)))
	{
		i = 0;
		while (i < lsh_num_builtins())
		{
			if ((strcmp(args[0], builtin_str2[i]) == 0) && i != 4 && i != 5)
				return (*builtin_func2[i])(args, env);
			if ((strcmp(args[0], builtin_str2[i]) == 0) && i == 4)
				return (ft_echo(args));
			if ((strcmp(args[0], builtin_str2[i]) == 0) && i == 5)		// ft_exit изменен
			{
				if (args[1])
					ft_exit(args[1]);
				ft_exit("0");
			}
			i++;
		}
		return (exec_path(args, env->sh_envp));
	}
  	else if ((ft_strnstr(args[0], "./", 2)))
		return (lsh_launch(args, env->sh_envp, env));
	return (1);
}