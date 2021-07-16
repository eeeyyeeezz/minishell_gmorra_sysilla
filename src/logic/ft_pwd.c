#include "../../includes/minishell.h"

int	pwd(t_env *env)
{
	char	*pwd;

	pwd = ft_calloc(255, sizeof(char *));
	getcwd(pwd, 255);
	ft_putendl_fd(pwd, 1);
	return (0);
}