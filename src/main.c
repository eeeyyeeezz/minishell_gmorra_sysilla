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
	ft_free((void *)&line);

	if (global->pars.ft_cmd)
	{
		for (int i = 0; global->pars.ft_cmd[i]; i++)
			ft_free((void *)&global->pars.ft_cmd[i]);
		ft_free((void *)&global->pars.ft_cmd);
	}
	if (global->pars.ft_arg)
	{
		for (int i = 0; global->pars.ft_arg[i] != NULL; i++)
			ft_free((void *)&global->pars.ft_arg[i]);
		ft_free((void *)&global->pars.ft_arg);
	}
	if (global->pars.pipis)
		ft_free((void *)&global->pars.pipis);
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
	global.envp = envp;
	ft_bzero(&env, sizeof(env));
	ft_envp_cpy(envp, &env);
	// shlvl(&env);						// тут leak
	init_all(&global);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, signal_2);
	ft_putnbr_fd(getpid(), 1);
	line = readline("minishell: ");
	while (line)
	{
		if (line == NULL)
			break;
		add_history(line);
		ft_parser(&global, line);
		// args = lsh_split_line(line);
		status = lsh_execute(global.pars.ft_arg, envp, &env);
		if (status == 1)
			printf("minishel: %s: command not found\n", args[0]);
		free_all(&global, line);
		line = readline("minishell: ");
	}
	if (line)
		ft_free((void *)&line);
	write(1, "\e[Aminishell: exit\n", 20);
	return (0);
}
