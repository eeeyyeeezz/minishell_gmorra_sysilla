/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:39:31 by gmorra            #+#    #+#             */
/*   Updated: 2021/04/11 12:42:27 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void			ft_exit(char *ret)
{
	int	ret_num;

	ret_num = ft_atoi(ret);
	if ((ret_num == 0) && (!(ret[0] <= '9' && ret[0] >= '0')))
	{
		printf("minishell: exit: %s: numeric argument required\n", ret);
	}
	// tputs(restore_cursor, 1, ft_putchar);
	// tputs(tigetstr("ed"), 1, ft_putchar);
	write(1, "exit\n", 5);
	exit(ret_num);
}

void			ft_err(char *str)
{
	ft_putstr_fd(str, 2);
	exit(0);
}


void			ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(0);
}
