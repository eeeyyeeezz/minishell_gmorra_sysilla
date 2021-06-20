/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:34:02 by ncliff            #+#    #+#             */
/*   Updated: 2021/03/26 18:22:37 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	i = 0;
	if (s1 == NULL)
		return (-1);
	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (ps1[i] == ps2[i] && n-- > 1)
	{
		if (ps1[i] == '\0')
			return (0);
		i++;
	}
	return (ps1[i] - ps2[i]);
}
