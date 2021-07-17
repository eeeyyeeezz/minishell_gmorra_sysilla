#include "../../includes/minishell.h"

int	pwd(t_env *env)
{
	char	*pwd;

	env->isb_in = 0;
	pwd = ft_calloc(255, sizeof(char *));
	if (!pwd)
		ft_error("Malloc error");
	getcwd(pwd, 255);
	ft_putendl_fd(pwd, 1);
	return (0);
}
