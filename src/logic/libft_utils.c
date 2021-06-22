#include "../../includes/minishell.h"


int		ft_strmasschr(char *what, char **where, int cmplen)
{
	int	i;

	i = 0;
	if (!what)
		return (0);
	while (where[i])
	{
		if (ft_memcmp(what, where[i], cmplen) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strndup(const char *s, size_t n)
{
	char			*res;
	unsigned int	i;

	i = 0;
	res = (char*)malloc(sizeof(char) * n + 1);
	if (res == NULL)
		return (NULL);
	while (i < n)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}