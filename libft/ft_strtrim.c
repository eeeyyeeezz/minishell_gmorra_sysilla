/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:36:01 by sysilla           #+#    #+#             */
/*   Updated: 2020/11/18 16:22:25 by sysilla          ###   ########.fr       */
=======
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:26:41 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/05 16:46:42 by gmorra           ###   ########.fr       */
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!s1 || !set)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[i]) && s1[i] != '\0')
		i++;
	if (s1[i] == '\0')
		return (ft_strdup(""));
	j = ft_strlen(s1);
	while (ft_strchr(set, s1[j - 1]) && i < j)
		j--;
	str = ft_substr(s1, (unsigned int)i, j - i);
	if (str == NULL)
		return (NULL);
	return (str);
=======
int			check_char(char const *str, char const c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char		*ft_strtrim(char const *str, char const *set)
{
	size_t	i;
	size_t	i_end;

	i = 0;
	if (str == NULL)
		return (NULL);
	i_end = ft_strlen(str) - 1;
	while (check_char(set, str[i]))
		i++;
	while (check_char(set, str[i_end]))
		if (i_end > 0)
			i_end--;
		else
			break ;
	if (i == ft_strlen(str))
		return (ft_substr("", 0, 1));
	return (ft_substr(str, i, i_end - i + 1));
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
}
