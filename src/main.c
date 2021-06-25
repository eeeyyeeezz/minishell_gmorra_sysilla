// #/*
// #;;;;;	MAKEFILE.H
// #;;;;;	gmorra/sysilla's minishell
// #;;;;;	team created ???
// #;;;;;	team locked ???
// #*/

#include "../includes/minishell.h"

// void	signal_2(int sig)
// {
// 	write(1, "\n", 1);
// 	rl_on_new_line();
// 	rl_redisplay();
// }


// char *builtin_str[] = {
// 	"cd",
// 	"export",
// 	"unset",
// 	"env",
// 	"echo",
// 	"exit"
// };

// int (*builtin_func[]) (char **, t_env *env) = {
// 	&ft_cd,
// 	&ft_export,
// 	&ft_unset,
// 	&ft_env
// };

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

// /*
// 	WUNTRACED - означает возврат управления и для остановленных (но не отслеживаемых) дочерних процессов, о статусе которых еще не было сообщено. Статус для отслеживаемых остановленных подпроцессов также обеспечивается без этой опции.
// 	WIFEXITED(status) - не равно нулю, если дочерний процесс успешно завершился.
// 	WIFSIGNALED(status) - возвращает истинное значение, если дочерний процесс завершился из-за необработанного сигнала.
// */

// int lnch_pth(char *path_ag, char **args, char **envp)
// {
// 	pid_t	pid;
// 	pid_t	wpid;
// 	int		status;

// 	pid = fork();
// 	if (pid == 0) {
// 		// Дочерний процесс
// 		// printf("PATH [%s]\n", path_ag);
// 		// for (int i = 0; args[i]; i++)
// 		// 	printf("ARGS [%s]\n", args[i]);
// 		if (execve(path_ag, args, envp) == -1)
// 		{
// 			strerror(1);
// 		}
// 		exit(EXIT_FAILURE);
// 	}
// 	else if (pid < 0) {
// 		// Ошибка при форкинге
// 		printf("%s", strerror(errno));
// 	} else {
// 		// Родительский процесс
// 		do {
// 			wpid = waitpid(pid, &status, WUNTRACED);
// 		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
// 		return (1);
// 	}
// 	return (0);
// }

// int lsh_launch(char **args, char **envp, t_env *env)
// {
// 	pid_t pid;
// 	pid_t wpid;
// 	int status;	
// 	pid = fork();
// 	if (pid == 0) {
// 		// Дочерний процесс
// 		if (execve(args[0], args, envp) == -1)
// 		{
// 			printf("zsh: no such file or directory: %s\n", args[0]);
// 			strerror(1);
// 		}
// 		shlvl(env);
// 		exit(EXIT_FAILURE);
// 	} else if (pid < 0) {
// 		// Ошибка при форкинге
// 		printf("%s", strerror(errno));
// 	} else {
// 		// Родительский процесс
// 		do {
// 		  wpid = waitpid(pid, &status, WUNTRACED);
// 		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
// 	}	
// 	return 3;
// }

char **lsh_split_line(char *line)
{
	int	bufsize = LSH_TOK_BUFSIZE;
	int	position = 0;
	char	**tokens = malloc(bufsize * sizeof(char*));
	char	*token;

	if (!tokens)
	{
		printf("minishell: ошибка выделения памяти\n");
		exit(1);
	}
	token = strtok(line, LSH_TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;	
		if (position >= bufsize)
		{
			bufsize += LSH_TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char*));
			if (!tokens)
			{
				printf("minishell: ошибка выделения памяти\n");
				exit(1);
			}
		}	
		token = strtok(NULL, LSH_TOK_DELIM);
	}
	tokens[position] = NULL;
	return tokens;
}

void	signal_2(int sig)
{
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}

int				main(int argc, char **argv, char **envp)
{
	t_env			env;
	t_struct		global;
	char			*line;
	char 			**args;
	int				status;

	global.fd = 1;
	status = 1;
	rl_catch_signals = 0;
	line = NULL;
	global.pars.arg = NULL;
	global.envp = envp;
	ft_bzero(&env, sizeof(env));
	ft_envp_cpy(envp, &env);
	shlvl(&env);						// тут leak
	init_all(&global);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, signal_2);
	ft_putnbr_fd(getpid(), 1);
	line = readline("minishell: ");
	while (line)
	{
		// signal(SIGQUIT, SIG_IGN);
		// signal(SIGINT, signal_2);
		if (line == NULL)
			break;
		add_history(line);
		// ft_parser(&global, line);
		// for (int i = 0; global.pars.ft_arg[i]; i++)
		// 	printf("I) [%d]\n", i);
		// for (int i = 0; global.pars.ft_arg[i]; i++)
			// status = lsh_execute(global.pars.ft_arg, envp, &env);
			// printf("ARGS [%s]\n", global.pars.ft_arg[i]);
		args = lsh_split_line(line);
		status = lsh_execute(args, envp, &env);
		line = readline("minishell: ");
		if (status == 1)
			printf("minishel: %s: command not found\n", args[0]);
		free(args);
	}
	free(line);
	write(1, "\e[Aminishell: exit\n", 20);
	return (0);
}