/*
;;;;;	FT_STRJOIN_NEW.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"

static char	*ft_strjoin_char_leaks(char *s1, char s2)
{
	int		i;
	char	*new_str;

	i = -1;
	new_str = malloc(sizeof(char) * ft_strlen(s1) + 2);
	if (!new_str)
		return (NULL);
	while (s1[++i])
		new_str[i] = s1[i];
	new_str[i] = s2;
	new_str[++i] = '\0';
	return (new_str);
}

char	*ft_strjoin_char(char *s1, char s2)
{
	char	*ptr_free;

	ptr_free = s1;
	s1 = ft_strjoin_char_leaks(s1, s2);
	if (!s1)
		return (NULL);
	free(ptr_free);
	return (s1);
}

char	*ft_strjoin_new(char *s1, char *s2)
{
	char	*ptr_free;

	ptr_free = s1;
	s1 = ft_strjoin(s1, s2);
	if (!s1)
		return (NULL);
	free(ptr_free);
	return (s1);
}
