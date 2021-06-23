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

char	*ft_strjoin_slash(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	char	*jstr;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(jstr = (char*)malloc(sizeof(*jstr) * len + 1)))
		return (NULL);
	while (*s1 != '\0')
		jstr[i++] = *s1++;
	jstr[i++] = '/';
	while (*s2 != '\0')
		jstr[i++] = *s2++;
	jstr[i] = '\0';
	return (jstr);
}