/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:58:19 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/01 16:41:08 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

<<<<<<< HEAD
	bytes = count * size;
	add = malloc(bytes);
	if (!(add))
		return (NULL);
	i = 0;
	while (bytes--)
	{
		add[i] = 0;
		i++;
	}
	return ((void *)add);
=======
	tmp = (void *)malloc(count * size);
	if (tmp == NULL)
		return (NULL);
	ft_bzero(tmp, count * size);
	return (tmp);
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
}
