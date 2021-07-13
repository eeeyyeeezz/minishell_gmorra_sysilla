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

int			ft_exit(char **ret)
{
	int	ret_num;

	if (!ret)
		ret_num = 0;
	else if (ret[2])
	{
		printf("minishell: exit: too many arguments\n");
		return (1);
	}
	else
	{
		ret_num = ft_atoi(ret[1]);
		if ((ret_num == 0) && (!(ret[1][0] <= '9' && ret[1][0] >= '0')))
		{
			printf("minishell: exit: %s: numeric argument required\n", ret[1]);
		}
		write(1, "exit\n", 5);
		exit(ret_num);
	}
	exit(ret_num);
}

void			ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(0);
}


int			ft_err(char *str)
{
	ft_putstr_fd(str, 2);
	return (0);
}
