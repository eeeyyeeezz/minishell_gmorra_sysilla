#include "../includes/minishell.h"

void	t_redir_fd(int flag, int fd)
{
	if (flag != 1 && flag != 3)
		dup2(fd, 1);
	else if (flag == 1)
		dup2(fd, 0);
}

void	tr_red(t_struct *global, int i, int *flag, int *fd)
{
	if (global->pars.chr[i] == 3)
	{
		*flag = 1;
		*fd = single_left(global->pars.args[i + 1][0]);
	}
	else if (global->pars.chr[i] == 4)
		*fd = single_right(global->pars.args[i + 1][0]);
	else if (global->pars.chr[i] == 5)
		*fd = double_right(global->pars.args[i + 1][0]);
	else if (global->pars.chr[i] == 6)
	{
		*flag = 3;
		double_left(global->pars.args[i + 1][0],
			global->pars.args[i], global);
	}
}

void	redidirecti(t_struct *global)
{
	int		i;
	int		fd;
	int		flag;

	i = -1;
	flag = 0;
	while (global->pars.chr[++i])
	{
		if (global->pars.chr[i] != 2)
		{
			tr_red(global, i, &flag, &fd);
		}
	}
	if (fd != -1)
		t_redir_fd(flag, fd);
	close(fd);
}
