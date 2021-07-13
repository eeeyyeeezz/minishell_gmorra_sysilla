
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

int		double_left(char *name)
{
	/*ЧТОПРОИСХОДИТ?!!!??!*/
}