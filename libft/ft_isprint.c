/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:59:10 by sysilla           #+#    #+#             */
/*   Updated: 2020/11/07 12:59:12 by sysilla          ###   ########.fr       */
=======
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 19:34:32 by gmorra            #+#    #+#             */
/*   Updated: 2020/10/30 19:38:24 by gmorra           ###   ########.fr       */
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
<<<<<<< HEAD
	return (c >= ' ' && c <= '~');
=======
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
}
