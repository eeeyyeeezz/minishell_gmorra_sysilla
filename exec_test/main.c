#include "header.h"


/*
  Объявление функций для встроенных команд оболочки:
 */
// int lsh_cd(char **args);
// int lsh_help(char **args);
// int lsh_exit(char **args);

/*
  Список встроенных команд, за которыми следуют соответствующие функции
 */
// char *builtin_str[] = {
//   "cd",
//   "help",
//   "exit"
// };

// int (*builtin_func[]) (char **) = {
//   &lsh_cd,
//   &lsh_help,
//   &lsh_exit
// };

char *builtin_str[] = {
	"cd",
	"export",
	"unset",
	"env",
	"echo"
};

int (*builtin_func[]) (char **, t_env *env) = {
	&cd,
	&export,
	&unset,
	&ft_env
};


int lsh_num_builtins() {
	return sizeof(builtin_str) / sizeof(char *);
}

void	signal_1(int sig)
{
	write(1, " ", 1);
}

void	signal_2(int sig)
{
	write(1, "\n", 1);
}

int lnch_pth(char *path_ag, char **args, char **envp)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	pid = fork();
	if (pid == 0) {
		// Дочерний процесс
		if (execve(path_ag, args, envp) == -1)
		{
			strerror(1);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0) {
		// Ошибка при форкинге
		perror("lsh");
	} else {
		// Родительский процесс
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		return (1);
	}
	return (0);
}

int lsh_launch(char **args, char **envp, t_env *env)
{
	pid_t pid, wpid;
	int status;	
	pid = fork();
	if (pid == 0) {
		// Дочерний процесс
		if (execve(args[0], args, envp) == -1)
		{
			printf("zsh: no such file or directory: %s\n", args[0]);
			strerror(1);
		}
		shlvl(env);
		exit(EXIT_FAILURE);
	} else if (pid < 0) {
		// Ошибка при форкинге
		perror("lsh");
	} else {
		// Родительский процесс
		do {
		  wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}	
	return 1;
}

char **lsh_split_line(char *line)
{
	int bufsize = LSH_TOK_BUFSIZE, position = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "lsh: ошибка выделения памяти\n");
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
				fprintf(stderr, "lsh: ошибка выделения памяти\n");
				exit(1);
			}
		}	
		token = strtok(NULL, LSH_TOK_DELIM);
	}
	tokens[position] = NULL;
	return tokens;
}

char *lsh_read_line(void)
{
	char *line = NULL;
	ssize_t bufsize = 0; // getline сама выделит память
	getline(&line, &bufsize, stdin);
	return line;
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
		path_ag = ft_strjoin_slesh(path[i], args[0]);
		if (lnch_pth(path_ag, args, envp))
			{
				flag++;
			}
		free(path_ag);
		i++;
	}
	return (1);
}

int lsh_execute(char **args, char **envp, t_env *env)
{
 	int i;

 	if (args[0] == NULL) {
 	  return 1;
 	}
	if (!(ft_strnstr(args[0], "./", 2)))
	{
		i = 0;
		
		while (i < lsh_num_builtins())
		{
			if ((strcmp(args[0], builtin_str[i]) == 0) && i != 4)
				return (*builtin_func[i])(args, env);
			if ((strcmp(args[0], builtin_str[i]) == 0) && i == 4)
				return (echo(args));
			i++;
		}
		return (exec_path(args, env->sh_envp));
	}
  	else
		return (lsh_launch(args, env->sh_envp, env));
}

t_sh tsh;

int main(int ac, char **av, char **envp)
{
	t_env env;
	char *line;
  	char **args;
  	int status;

	ft_envp_cpy(envp, &env);
	shlvl(&env);
	tsh.sh_lvl = ft_atoi(env.sh_lvl);
	tsh.sh_mdepth = tsh.sh_lvl;
  	do 
	{
		printf("shell_by_danya> ");
		signal(SIGQUIT, signal_1);
		signal(SIGINT, signal_2);
		line = lsh_read_line();
		args = lsh_split_line(line);
		status = lsh_execute(args, envp, &env);
		free(line);
		free(args);
	} while (status);
}
