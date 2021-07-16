// #/*
// #;;;;;	MAKEFILE.H
// #;;;;;	gmorra/sysilla's minishell
// #;;;;;	team created ???
// #;;;;;	team locked ???
// #*/

#include "../includes/minishell.h"

void	signal_2(int sig)
{
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}

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

static	void	free_all(t_struct *global, char *line)
{
	// if (line)
	// 	ft_free((void *)&line);
	if (global->pars.ft_pipes)
		ft_free((void *)&global->pars.ft_pipes);
	if (global->pars.ft_cmd)
	{
		for (int i = 0; global->pars.ft_cmd[i]; i++)
			ft_free((void *)&global->pars.ft_cmd[i]);
		ft_free((void *)&global->pars.ft_cmd);
	}
	if (global->pars.pipis)
		ft_free((void *)&global->pars.pipis);
	if (global->pars.chr)
		ft_free((void *)&global->pars.chr);
	if (global->pars.args)
	{
		for (int i = 0; global->pars.args[i]; i++)
		{
			for (int j = 0; global->pars.args[i][j]; j++)
				ft_free((void *)&global->pars.args[i][j]);
			ft_free((void *)&global->pars.args[i]);
		}
		ft_free((void *)&global->pars.args);
	}
}

void			print_double(char **arg, char *str)
{
	int i;
	
	i = -1;
	while (arg[++i])
		printf("%s [%s]\n", str, arg[i]);
}

static	char	*ft_readline(char *line)
{
	if (line)
		ft_free((void *)&line);
	line = readline(YELLOW "$" GREEN "minishell: " RES);
	return (line);
}

static	void	make_pipe_array(t_struct *global)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	global->pars.ft_pipes = malloc(sizeof(char ***) * 30);
	while (global->pars.chr[i])
	{
		if (global->pars.chr[i - 1] != 4 && global->pars.chr[i - 1] != 5 && global->pars.chr[i - 1] != 3
		&& global->pars.chr[i - 1] != 6 && global->pars.chr[i] != 6)
			global->pars.ft_pipes[count++] = global->pars.args[i];
		i++;
	}
	global->pars.ft_pipes[count] = 0;
}

int				main(int argc, char **argv, char **envp)
{
	t_struct		global;
	char			*line;
	char 			**args;
	int				status;
	char 			***megamass;

	global.fd = 1;
	rl_catch_signals = 0;
	line = NULL;
	global.envp = envp;
	ft_bzero(&global.env, sizeof(global.env));
	ft_envp_cpy(envp, &global.env);
	shlvl(&global.env);
	init_all(&global);
	global.env.basefd1 = 4;
	global.env.basefd0 = 3;
	dup2(1, global.env.basefd1);
	dup2(0, global.env.basefd0);
	global.env.status = 0;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, signal_2);
	line = readline(YELLOW "$" GREEN "minishell: " RES);
	while (line)
	{
		if (line == NULL)
			break;
		add_history(line);
		ft_parser(&global, line);
		int i = 0;		
		if (!global.flags.ft_error)
		{
		 	redidirecti(&global);
			make_pipe_array(&global);
			if (!global.pars.args[0])
				free_all(&global, line);
			else
			{
				print_aboba(global.pars.ft_pipes, "JKJ");
				if (global.pars.chr[0] == 4)
					redidirecti(&global);
				if (global.pars.args[1] == NULL)
					lsh_execute(global.pars.ft_pipes[0], envp, &global);
				else
					pipeline(global.pars.ft_pipes, &global.env);
				signal(SIGINT, signal_2);
				free_all(&global, line);
			}
			dup2(global.env.basefd1, 1);
			dup2(global.env.basefd0, 0);
		}
		line = ft_readline(line);
	}
	if (line)
		ft_free((void *)&line);
	write(1, "\033[1;33m$\033[1;32mminishell: \e[0mexit\n", 35);	
	return (0);
}

// echo 12312312 asdasads 'asdasd' -- leak | no
// 	 -- leaks
// echo "$123" | cat -e    - double write
// echo "$uS" '123' lol - empty || no
// echo '$USER'"$USER" - seg || no || prikol

 
// ""ec""ho"" "aboba" 1''2''3""""""'' >> t''1 | c""""at "-e" || good
// 'e''cho'"" a""b""o""ba '$KAVO'"cat -e | cat -e" >> 't1' > t2 << t3 yes | "c""at" '-e' >> " lol mda "
// 'echo'"" 123 << "cat" "-e" - huynya || echo"" "123"'' << lol | fixed
// "ec""ho" 123 -- sega


// echo "$USERasd" 123 'asdsad --  wtf seg

// echo '$ABOBA'"$USER"lol 'cat -e | grep libft' -- leaks || no
// 'echo' 123  >> t1 - tozhe || double free with space


// ABOBA ERROR SEGFAUL!!!
// global->pars.ft_arg = NULL; | double free

// 4) ЗАЩИТИТЬ МАЛЛОКИ !!!!!!!!!!!
