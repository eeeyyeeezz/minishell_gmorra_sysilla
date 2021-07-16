/*
;;;;;	FT_ISALNUM_NEW.C
;;;;;	gmorra/sysilla's minishell
;;;;;	team created ???
;;;;;	team locked ???
*/

#include "../../includes/minishell.h"

int	ft_isspaces(char word)
{
	if (word == ' ' || word == '	')
		return (1);
	return (0);
}

int	ft_issleter(char s)
{
	int	i;

	i = 0;
	while ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z'))
		i++;
	return (i);
}

int	ft_isalnum_new(int c)
{
	if ((c >= 33 && c <= 37) || (c >= 39 && c <= 60))
		return (1);
	else if ((c >= 61 && c <= 123)
		|| c == 125 || c == 126)
		return (1);
	return (0);
}
