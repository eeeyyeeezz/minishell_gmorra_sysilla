/*
;;;;;	MAIN.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../includes/minishell.h"

void	signal_2(int sig)
{
	if (sig)
	{
	}
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}

static	char	*ft_readline(char *line)
{
	if (line)
		ft_free((void *)&line);
	line = readline(YELLOW "$" GREEN "minishell: " RES);
	return (line);
}

void	pre_read(t_struct *global)
{
	global->fd = 1;
	shlvl(&global->env);
	global->env.cn = 0;
	global->env.basefd1 = 4;
	global->env.basefd0 = 3;
	dup2(1, global->env.basefd1);
	dup2(0, global->env.basefd0);
	global->env.status = 0;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, signal_2);
}

void	readlin(char *line, t_struct *global)
{
	add_history(line);
	ft_parser(global, line);
	if (!global->flags.ft_error)
	{
		redidirecti(global);
		make_pipe_array(global);
		if (!global->pars.args[0])
			free_all(global);
		else
		{
			if (global->pars.chr[0] == 4)
				redidirecti(global);
			if (global->pars.args[1] == NULL)
				lsh_execute(global->pars.ft_pipes[0], global);
			else
				pipeline(global->pars.ft_pipes, &global->env);
			signal(SIGINT, signal_2);
			free_all(global);
		}
		dup2(global->env.basefd1, 1);
		dup2(global->env.basefd0, 0);
		global->env.cn = 0;
	}	
}

int	main(int argc, char **argv, char **envp)
{
	t_struct	global;
	char		*line;

	if (argc > 2 && argv[3])
		return (0);
	rl_catch_signals = 0;
	line = NULL;
	global.envp = envp;
	ft_bzero(&global.env, sizeof(global.env));
	ft_envp_cpy(envp, &global.env);
	init_all(&global);
	pre_read(&global);
	line = readline(YELLOW "$" GREEN "minishell: " RES);
	while (line)
	{
		if (line == NULL)
			break ;
		readlin(line, &global);
		line = ft_readline(line);
	}
	if (line)
		ft_free((void *)&line);
	write(1, "\e[A\033[1;33m$\033[1;32mminishell: \e[0mexit\n", 38);
	return (0);
}

// 4) ЗАЩИТИТЬ МАЛЛОКИ !!!!!!!!!!!
