/*
;;;;;	FT_PARSER.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"

// printf("cmd [%d]\nchr [%d]\ninfo env [%s]\nfirst line [%s]\nfirst word [%s]\ninfo [%s]\n", 
// 	global->pars.cmd, global->pars.chr, global->pars.info_env, global->pars.first_line, global->pars.first_word,
// 	global->pars.info);

static	char	*enter_pressed(char *line, char *str, t_struct *global)
{
	if (!ft_strncmp(str, "\n", 1))
	{
		// printf("LINE [%s]\n", line);
		syntax_error(line, global);
		global->pars.first_line = line;
		open_file_history(line, global);
		while (global->history->next)
			global->history = global->history->next;
		find_redirects_pipes(line, global);		// TODO: leaks
		pars_arguments_line(line, global);
		// lgc_choise(global);
		write_minishell();
		line[0] = 0;
		return (line);
	}
	return (line);
}

void	signal_2(int sig)
{
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}


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

// int	ft_exit(char **argc)
// {
// 	int	ret;

// 	ret = 0;
// 	ft_putendl_fd("exit", 1);
// 	if (argc[1])
// 	{
// 		if ((ft_isnum(argc[1])))
// 		{
// 			printf("bash: exit: %s: numeric argument required\n", argc[1]);
// 		}
// 		else
// 		{
// 			ret = ft_atoi(argc[1]);
// 		}
// 	}
// 	return (ret);
// }

int lsh_num_builtins() {
	return sizeof(builtin_str) / sizeof(char *);
}

int lnch_pth(char *path_ag, char **args, char **envp)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	pid = fork();
	if (pid == 0) {
		// Дочерний процесс
		// printf("PATH [%s]\n", path_ag);
		// for (int i = 0; args[i]; i++)
		// 	printf("ARGS [%s]\n", args[i]);
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

 	if (args[0] == NULL)
	{
 	  return 1;
 	}
	if (!(ft_strnstr(args[0], "./", 2)))
	{
		i = 0;
		
		while (i < lsh_num_builtins())
		{
			if ((strcmp(args[0], builtin_str[i]) == 0) && i != 4 && i != 5)
				return (*builtin_func[i])(args, env);
			if ((strcmp(args[0], builtin_str[i]) == 0) && i == 4)
				return (ft_echo(args));
			if ((strcmp(args[0], builtin_str[i]) == 0) && i == 5)		// ft_exit изменен
				ft_exit();
			i++;
		}
		return (exec_path(args, env->sh_envp));
	}
  	else
		return (lsh_launch(args, env->sh_envp, env));
}

void			ft_parser(t_struct *global, char **envp, t_env *env)
{
	int				br;
	char			str[200];
	char			*line;
	char 			**args;
	int				status;

	status = 1;
	str[0] = 0;
	line = NULL;
	init_all(global);
	// init_termios(global);
	// gnl_history_to_list(global);
	while (1)
	{
		// while (global->history->next)
			// global->history = global->history->next;
		// line = ft_calloc(1, sizeof(char *));
		while (status)
		{
			// signal(SIGQUIT, SIG_IGN);
			// signal(SIGINT, signal_2);		// CTRL-C
			// br = read(0, str, 100);
			// str[br] = 0;
			// line = key_hook(str, line, global);
			// if (!ft_strncmp(str, "\4", 1) && line[0] == 0)
			// 	ft_exit();
			// if (key_escape(str) && global->flags.flag != 1)
			// 	line = ft_strjoin_new(line, str);
			line = readline("\033[1;33m$\033[1;32mminishell: \033[0m");
			if (line == NULL)
				ft_exit();
			add_history(line);

			// global->flags.flag = 0;
			args = lsh_split_line(line);
			status = lsh_execute(args, envp, env);
			// line = enter_pressed(line, str, global);
		}
	}
}


// ./ ПАРСИНГ
// echo ";";";";";";"
// лики на долларах
// echo $USERasdasdasdasd $"HOME" - sega
// лишняя инфа в долларе сега надо сделоть
// echo "$USER asd " сега с пробелом в конце??? || все гуд
// экранировнаие работает ПО ДРУГОМУ!!!!!!! немного по другому
// echo ""123"" pizda vse zavisaet || vse ok
// !!! OBNULIT FIRST WORD!!! || да обнулен
// экранирование БЕЗ кавычек echo \' = ' мда
// 2) $ без кавычек и в кавычках
// 4) ЗАЩИТИТЬ МАЛЛОКИ !!!!!!!!!!!
// 5) echo ''asd''22 зависает (вай?) || не зависает другие приколы || не зависает
// 6) exit 123 = echo $? = 123
// || exit echo $? = 0
// || exit asdasd echo $? = 255
// || exit 123 456 = не выйдет echo $? = 1
// 7) "command not found" 127
// 9) После ошибок снова выходить в печать
// 10) export пробел s null parametrs
