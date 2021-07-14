#include "../../includes/minishell.h"

int			str_in_str(char *haystack, char *needle)
{
	int	i;
	int	count;

	count = 0;
	i = ft_strlen(needle) - 1;
	while (haystack[count] != '=')
		count++;
	count--;
	while (needle[i] == haystack[count])
	{
		i--;
		count--;
	}
	if (needle[i] == '$')
		return (1);
	else
		return (0);
}