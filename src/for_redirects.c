#include "../includes/minishell.h"

int	double_right(char *name)
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

int	single_right(char *name)
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

int	single_left(char *name)
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
	tmp = readline("aboba> ");
	while (ft_strncmp(tmp, stop, -1) != 0 && tmp != NULL)
	{
		ret = ft_new_str(ret, tmp);
		free(tmp);
		tmp = readline("aboba> ");
	}
	free(tmp);
	return (ret);
}

void	double_left(char *stop, char **command, t_struct *global)
{
	char	**heredoc;
	int		tmpfd[2];
	int		i;

	heredoc = NULL;
	heredoc = until_stop(stop);
	pipe(tmpfd);
	i = 0;
	while (heredoc[i] && heredoc)
	{
		ft_putendl_fd(heredoc[i], tmpfd[1]);
		i++;
	}
	freemass(heredoc);
	dup2(tmpfd[0], 0);
	close(tmpfd[1]);
	close(tmpfd[0]);
	lsh_execute(&command[0], global);
	dup2(global->env.basefd1, 1);
	dup2(global->env.basefd0, 0);
}
