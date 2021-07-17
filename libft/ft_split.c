/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:27:44 by sysilla           #+#    #+#             */
/*   Updated: 2020/11/20 13:24:36 by sysilla          ###   ########.fr       */
=======
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:56:32 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/09 18:41:26 by gmorra           ###   ########.fr       */
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
static void		ft_cpy(char *dest, char *src, size_t n)
{
	size_t		i;
=======
static int		memory_len(char const *s, char c)
{
	int j;
	int n;
	int i;
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c

	j = 0;
	i = 0;
<<<<<<< HEAD
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static size_t	ft_count_words(const char *str, char c)
{
	size_t		i;
	size_t		words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (!str[i])
			break ;
		words++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (words);
}

static size_t	ft_cut_words(const char *str, size_t words, char **r, char c)
{
	size_t		w;
	size_t		start;
	size_t		end;

	w = 0;
	start = 0;
	while (w < words && str[start])
	{
		while (str[start] == c)
			start++;
		end = start;
		while (str[end] && str[end] != c)
			end++;
		if (!(r[w] = malloc(end - start + 1)))
			return (0);
		ft_cpy(r[w], (char *)str + start, end - start);
		start = end + 1;
		w++;
	}
	return (1);
}

char			**ft_split(char const *str, char c)
{
	size_t		words;
	char		**r;

	if (!str)
		return (NULL);
	words = ft_count_words(str, c);
	if (!words)
	{
		if (!(r = malloc(sizeof(*r))))
			return (NULL);
		r[0] = NULL;
		return (r);
	}
	if (!(r = malloc((words + 1) * sizeof(*r))))
		return (NULL);
	if (!ft_cut_words(str, words, r, c))
		return (NULL);
	r[words] = 0;
	return (r);
=======
	n = 0;
	while (s[i])
	{
		if (j == 1 && s[i] == c)
			j = 0;
		if (j == 0 && s[i] != c)
		{
			j = 1;
			n++;
		}
		i++;
	}
	return (n);
}

char			**ft_split(char const *s, char c)
{
	int		arr[3];
	char	**temp;

	arr[0] = 0;
	arr[2] = -1;
	if (!s)
		return (NULL);
	if (!(temp = malloc(sizeof(char *) * (memory_len(s, c) + 1))))
		return (NULL);
	while (++arr[2] < memory_len(s, c))
	{
		while (s[arr[0]] == c && s[arr[0]])
			arr[0]++;
		arr[1] = arr[0];
		while (s[arr[0]] != c && s[arr[0]])
			arr[0]++;
		temp[arr[2]] = ft_substr(s, arr[1], arr[0] - arr[1]);
		arr[0]++;
	}
	temp[arr[2]] = NULL;
	return (temp);
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
}
