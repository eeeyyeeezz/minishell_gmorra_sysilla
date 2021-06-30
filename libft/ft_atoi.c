/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 09:53:45 by ncliff            #+#    #+#             */
/*   Updated: 2020/11/07 12:40:53 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int	ft_atoi(const char *str)
// {
// 	unsigned long int	num;
// 	int					point;
// 	int					minus;

// 	num = 0;
// 	point = 0;
// 	minus = 1;
// 	while (str[point] == ' ' || str[point] == '\t' || str[point] == '\n' ||
// 		str[point] == '\v' || str[point] == '\f' || str[point] == '\r')
// 		point++;
// 	if (str[point] == '-' || str[point] == '+')
// 	{
// 		if (str[point] == '-')
// 			minus = -1;
// 		point++;
// 	}
// 	while (str[point] >= '0' && str[point] <= '9')
// 	{
// 		num = num * 10 + (str[point] - '0');
// 		point++;
// 	}
// 	(minus == 1 && num > 9223372036854775807 ? num = -1 : 0);
// 	(minus == -1 && num > 9223372036854775807 ? num = 0 : 0);
// 	return (num * minus);
// }

int		ft_atoi(const char *str)
{
	int		i;
	int		res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		sign = -1;
		i++;
	}
	if (str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		i++;
	if (!(str[i] <= '9' && str[i] >= '0'))
		return (0);
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}


int		ft_atoi_plus(const char *str)
{
	int		i;
	int		res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		sign = -1;
		i++;
	}
	if (str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}