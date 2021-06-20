/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:23:34 by sysilla           #+#    #+#             */
/*   Updated: 2020/11/18 16:55:06 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
}
