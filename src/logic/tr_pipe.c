#include "../../includes/minishell.h"

int	builtin_func2(char **args, t_env *env, int i)
{
	if (i == 0)
		return (ft_cd(args, env));
	if (i == 1)
		return (ft_export(args, env));
	if (i == 2)
		return (ft_unset(args, env));
	if (i == 3)
		return (ft_env(args, env));
	return (-1);
}

void	pid_nonzero(t_env *env, int status, int *fd)
{
	signal(SIGINT, SIG_IGN);
	wait(&status);
	close(fd[1]);
	status = env->status;
}
