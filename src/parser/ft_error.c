/*
;;;;;	FT_ERROR.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"

int	ft_exit(char **ret, t_env *env)
{
	int	ret_num;

	if (!ret)
		ret_num = 0;
	else if (ret[2])
	{
		env->status = 1;
		printf("minishell: exit: too many arguments\n");
		return (1);
	}
	else
	{
		ret_num = ft_atoi(ret[1]);
		if ((ret_num == 0) && (!(ret[1][0] <= '9' && ret[1][0] >= '0')))
		{
			env->status = 1;
			printf("minishell: exit: %s: numeric argument required\n", ret[1]);
		}
		write(1, "exit\n", 5);
		exit(ret_num);
	}
	exit(ret_num);
}

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(0);
}

int	ft_err(char *str)
{
	ft_putstr_fd(str, 2);
	return (0);
}
