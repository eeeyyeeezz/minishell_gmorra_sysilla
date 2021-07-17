/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 13:01:59 by sysilla           #+#    #+#             */
/*   Updated: 2020/11/07 13:02:02 by sysilla          ###   ########.fr       */
=======
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 11:58:32 by gmorra            #+#    #+#             */
/*   Updated: 2020/10/29 15:21:31 by gmorra           ###   ########.fr       */
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dst;

	dst = (unsigned char *)b;
	while (dst < (unsigned char *)b + len)
		*(dst++) = (unsigned char)c;
=======
void		*ft_memset(void *b, int c, size_t len)
{
	unsigned char *tmp;

	tmp = b;
	while (len--)
		*tmp++ = c;
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
	return (b);
}
