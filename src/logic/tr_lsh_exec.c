#include "../../includes/minishell.h"

int	ft_isnum(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (!(str[i] <= '9' && str[i] >= '0'))
			j++;
		i++;
	}
	if (j != 0)
		return (1);
	return (0);
}

void	chld_sig(void)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
}
