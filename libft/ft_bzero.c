/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2020/11/04 15:01:05 by sysilla           #+#    #+#             */
/*   Updated: 2020/11/04 16:32:40 by sysilla          ###   ########.fr       */
=======
/*   Created: 2020/10/29 13:09:30 by gmorra            #+#    #+#             */
/*   Updated: 2020/10/31 13:35:27 by gmorra           ###   ########.fr       */
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *b, size_t len)
{
<<<<<<< HEAD
	size_t			i;
	unsigned char	*d;

	d = s;
	i = 0;
	while (i++ < n)
	{
		*d++ = 0;
	}
=======
	unsigned char	*tmp;

	tmp = b;
	if (len == 0)
		return ;
	while (len--)
		*tmp++ = '\0';
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
}
