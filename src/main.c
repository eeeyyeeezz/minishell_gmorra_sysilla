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
	if (line)
		ft_free((void *)&line);
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
	if (global->pars.dirty_array)
	{
		for (int i = 0; global->pars.dirty_array[i]; i++)
		{
			for (int j = 0; global->pars.dirty_array[i][j]; j++)
				ft_free((void *)&global->pars.dirty_array[i][j]);
			ft_free((void *)&global->pars.dirty_array[i]);
		}
		ft_free((void *)&global->pars.dirty_array);
	}
}

void			print_double(char **arg, char *str)
{
	int i;
	
	i = -1;
	while (arg[++i])
		printf("%s [%s]\n", str, arg[i]);
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
	line = readline("minishell: ");
	while (line)
	{
		if (line == NULL)
			break;
		add_history(line);
		ft_parser(&global, line);
		int i = 0;
		if (!global.pars.dirty_array[0])
			free_all(&global, line);
		else
		{
			if (global.pars.chr[0] == 4)
				redidirecti(&global);
			if (global.pars.dirty_array[1] == NULL)
				lsh_execute(global.pars.dirty_array[0], envp, &global);
			else
				pipeline(global.pars.dirty_array, &global.env);
			signal(SIGINT, signal_2);
			free_all(&global, line);
		}
		dup2(global.env.basefd1, 1);
		dup2(global.env.basefd0, 0);
		line = readline("minishell: ");
	}
	if (line)
		ft_free((void *)&line);
	write(1, "\e[Aminishell: exit\n", 20);	
	return (0);
}

// global->pars.ft_arg = NULL; | double free
// """"""ls""'' -la | cat "-e"
// "\\\" - segfault
// echo "asdasd""" - segfault	| no
// echo "asdasd1223""asdsd" - double free | no