
#include "../includes/minishell.h"

int red(int fd_out, int fd_in, t_env *env)
{
	// >>
	fd_out = open("НАЗВАНИЕ ФАЙЛА", O_WRONLY | O_WRONLY | O_APPEND, 0644);
	// > 
	fd_out = open("НАЗВАНИЕ ФАЙЛА", O_WRONLY | O_WRONLY | O_TRUNC, 0644);
	// <
	fd_in = open("НАЗВАНИЕ ФАЙЛА", O_RDONLY, 0644);
	return (0);
}

int		double_right(char *name)
{
	int	fd;

	if (!name)
		return (0);
	fd = open(name, O_WRONLY | O_CREAT | O_APPEND, 00644);
	if (fd <= 0)
	{
		printf("%s\n", strerror(errno));
		return (-1);
	}
	return (fd);
}

int		single_right(char *name)
{
	int	fd;

	if (!name)
		return (0);
	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (fd <= 0)
	{
		printf("%s\n", strerror(errno));
		return (-1);
	}
	return (fd);
}

int		single_left(char *name)
{
	int	fd;

	if (!name)
		return (0);
	fd = open(name, O_RDONLY, 00644);
	if (fd <= 0)
	{
		printf("%s\n", strerror(errno));
		return (-1);
	}
	return (fd);
}

char	**until_stop(char *stop)
{
	char	**ret;
	char	*tmp;

	ret = NULL;
	tmp = readline("heredoc> ");
	while (ft_strncmp(stop, tmp, ft_strlen(tmp)) && tmp)
	{
		ret = ft_new_str(ret, tmp);
		tmp = readline("heredoc> ");
	}
	free(tmp);
	return (ret);
}

void	double_left(char *stop, char **command, t_struct *global)
{
	/*ЧТОПРОИСХОДИТ?!!!??!*/
	char	**heredoc;
	int		tmpfd[2];
	int		i;

	heredoc = until_stop(stop);
	pipe(tmpfd);
	i = 0;
	while (heredoc[i])
	{
		ft_putendl_fd(heredoc[i], tmpfd[1]);
		i++;
	}
	dup2(tmpfd[0], 0);
	close(tmpfd[1]);
	close(tmpfd[0]);
	/*временная вставка которая не должна работать*/
	if (command[1] == NULL)
		lsh_execute(&command[0], global->env.sh_envp, global);
}

void	redidirecti(t_struct *global)
{
	int		i;
	int		fd;

	i = 0;
	fd = single_right(global->pars.args[1][0]);
	if (fd != -1)
	{
		dup2(fd, 1);
	}
	free(global->pars.args[1]);
	global->pars.args[1] = NULL;
	close(fd);
}