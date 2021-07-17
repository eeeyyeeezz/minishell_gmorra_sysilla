/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:23:34 by sysilla           #+#    #+#             */
/*   Updated: 2020/11/18 16:55:06 by sysilla          ###   ########.fr       */
=======
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 21:26:29 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/04 14:46:57 by gmorra           ###   ########.fr       */
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
void	ft_putstr_fd(const char *str, int fd)
{
	size_t i;

	i = 0;
	if (fd < 0 || !str)
		return ;
	while (str[i] != 0)
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
=======
void		ft_putstr_fd(char *s, int fd)
{
	if (fd < 0 || s == NULL)
		return ;
	while (*s)
		write(fd, &*s++, 1);
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
}
