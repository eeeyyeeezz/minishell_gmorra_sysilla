/*
;;;;;	MAIN_UTILS.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../includes/minishell.h"

static	void	free_all_2(t_struct *global)
{
	int	i;
	int	j;

	i = -1;
	if (global->pars.args)
	{
		while (global->pars.args[++i])
		{
			j = -1;
			while (global->pars.args[i][++j])
				ft_free((void *)&global->pars.args[i][j]);
			ft_free((void *)&global->pars.args[i]);
		}
		ft_free((void *)&global->pars.args);
	}
}

void	free_all(t_struct *global)
{
	int	i;

	i = -1;
	if (global->pars.ft_pipes)
		ft_free((void *)&global->pars.ft_pipes);
	if (global->pars.ft_cmd)
	{
		while (global->pars.ft_cmd[++i])
			ft_free((void *)&global->pars.ft_cmd[i]);
		ft_free((void *)&global->pars.ft_cmd);
	}
	if (global->pars.chr)
		ft_free((void *)&global->pars.chr);
	i = -1;
	free_all_2(global);
}

void	make_pipe_array(t_struct *global)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	global->pars.ft_pipes = malloc(sizeof(char ***) * 30);
	while (global->pars.chr[i])
	{
		if (global->pars.chr[i - 1] != 4
			&& global->pars.chr[i - 1] != 5 && global->pars.chr[i - 1]
			!= 3 && global->pars.chr[i - 1] != 6 && global->pars.chr[i] != 6)
			global->pars.ft_pipes[count++] = global->pars.args[i];
		i++;
	}
	global->pars.ft_pipes[count] = 0;
}
