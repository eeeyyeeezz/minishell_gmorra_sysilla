/*
;;;;;	SKIP_CMD.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"

int				skip_cmd(char *big, char *little)
{
	int	i;
	int	j;
	int	save;

	i = 0;
	j = 0;
	save = 0;
	while (big[i])
	{
		if (big[i] == little[j])
		{
			while (big[save] == little[j])
			{
				save++;
				j++;
			}
			if (little[j] != '\0')
				j = 0;
			else
			{
				while (ft_isspaces(big[save]))
					save++;
				return (save - 1);
			}
		}
		i++;
		save = i;
	}
	return (0);
}
