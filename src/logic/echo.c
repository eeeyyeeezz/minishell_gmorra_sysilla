/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:44:28 by sysilla           #+#    #+#             */
/*   Updated: 2021/05/19 13:44:30 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	args_count(char **arg)
{
	int	count;

	count = 0;
	while (arg[count])
	{
		count++;
	}
	return (count);
}

void	ft_putstrecho_fd(const char *str, int fd)
{
	size_t	i;

	i = 0;
	if (fd < 0 || !str)
		return ;
	while (str[i] != 0)
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
	ft_putstr_fd(" ", 1);
}

void	putstr_while(int arg_count, char **arg, int i, int option_n)
{
	if (option_n == 1)
		printf("%s ", arg[i]);
	else
	{
		printf("%s ", arg[i]);
		if (i + 1 == arg_count)
			printf("\n");
	}
}

int	ft_echo(char **arg)
{
	int	i;
	int	option_n;
	int	arg_count;

	i = 1;
	option_n = 0;
	if (!arg[1])
	{
		write(1, "\n", 1);
		return (0);
	}
	if (arg[1][0] == '-' && arg[1][1] == 'n' && arg[1][2] == '\0')
	{
		option_n = 1;
		i++;
	}
	arg_count = args_count(arg);
	while (i < arg_count)
	{
		putstr_while(arg_count, arg, i, option_n);
		i++;
	}
	return (1);
}
