#include "../../includes/minishell.h"

char	*ft_strjoin_slash(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	char	*jstr;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	jstr = (char *)malloc(sizeof(*jstr) * len + 1);
	if (!(jstr))
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
	jstr = (char *)malloc(sizeof(*jstr) * len + 1);
	if (!(jstr))
		return (NULL);
	while (*s1 != '\0')
		jstr[i++] = *s1++;
	while (*s2 != '\0')
		jstr[i++] = *s2++;
	free(s1);
	jstr[i] = '\0';
	return (jstr);
}

void	tr_new_str(int size, char **new_arr, char *new_str, char **arr)
{
	int	i;

	i = 0;
	new_arr[size + 1] = NULL;
	new_arr[size] = ft_strdup(new_str);
	while (i < size)
	{
		new_arr[i] = ft_strdup(arr[i]);
		i++;
	}
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
		new_arr = ft_calloc(sizeof(char *), size + 2);
		if (!new_arr)
			return (NULL);
		new_arr[size + 1] = NULL;
		new_arr[0] = ft_strdup(new_str);
	}
	else
	{
		while (arr[size])
			size++;
		new_arr = ft_calloc(sizeof(char *), size + 2);
		if (!new_arr)
			return (NULL);
		tr_new_str(size, new_arr, new_str, arr);
		freemass(arr);
	}
	return (new_arr);
}
