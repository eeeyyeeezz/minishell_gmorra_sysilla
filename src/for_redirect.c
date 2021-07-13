
#include "../includes/minishell.h"

int red(int fd_out, int fd_in, t_env *env)
{
	// >>
	fd_out = open("НАЗВАНИЕ ФАЙЛА", O_WRONLY | O_WRONLY | O_APPEND, 0644);
	// > 
	fd_out = open("НАЗВАНИЕ ФАЙЛА", O_WRONLY | O_WRONLY | O_TRUNC, 0644);
	// <
	fd_in = open("НАЗВАНИЕ ФАЙЛА", O_RDONLY, 0644);
}
