#include "../../includes/minishell.h"


char		*ft_strmasschr_char(char *what, char **where, int cmplen)
{
	int	i;
	char *ret;

	i = 0;
	if (!what)
		return (NULL);
	while (where[i])
	{
		if (ft_memcmp(what, where[i], cmplen) == 0)
		{
			ret = ft_strdup(where[i]);
			return (ret);
		}
		i++;
	}
	return (NULL);
}

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

char	*ft_strdup_clean(char *s1)
{
	char	*s1dup;
	int		i;

	s1dup = malloc((ft_strlen(s1) + 1) * sizeof(char));
	i = 0;
	if (s1dup == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s1dup[i] = s1[i];
		i++;
	}
	free(s1);
	s1dup[i] = '\0';
	return (s1dup);
}

char	*ft_strjoin_clean(char *s1, char *s2)
{
	size_t	len;
	size_t	i;
	char	*jstr;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(jstr = (char*)malloc(sizeof(*jstr) * len + 1)))
		return (NULL);
	while (*s1 != '\0')
		jstr[i++] = *s1++;
	while (*s2 != '\0')
		jstr[i++] = *s2++;
	free(s1);
	jstr[i] = '\0';
	return (jstr);
}

char	**ft_new_str(char **arr, char *new_str)
{
	char	**new_arr;
	int		size;
	int		i;

	i = 0;
	size = 0;
	if (!arr)
	{
		size = 0;
		new_arr = ft_calloc(sizeof(char *), size + 2);
		if (!new_arr)
			return NULL;
		new_arr[size + 1] = NULL;
		new_arr[0] = ft_strdup(new_str);
	}
	else
	{
		while (arr[size])
			size++;
		new_arr = ft_calloc(sizeof(char *), size + 2);
		if (!new_arr)
			return NULL;
		new_arr[size + 1] = NULL;
		new_arr[size] = ft_strdup(new_str);
		while (i < size)
		{
			new_arr[i] =ft_strdup(arr[i]);
			i++;
		}
		freemass(arr);
	}
	return (new_arr);
}