/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:23:09 by sysilla           #+#    #+#             */
/*   Updated: 2020/11/18 16:27:53 by sysilla          ###   ########.fr       */
=======
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 21:34:12 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/04 13:19:38 by gmorra           ###   ########.fr       */
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *str, int fd)
{
<<<<<<< HEAD
	if (fd < 0)
		return ;
	ft_putstr_fd(str, fd);
=======
	ft_putstr_fd(s, fd);
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
	ft_putchar_fd('\n', fd);
}
