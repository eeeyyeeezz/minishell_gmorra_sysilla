/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:23:34 by gmorra            #+#    #+#             */
/*   Updated: 2021/04/14 13:30:59 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static		char	*allocate_string(char *line, int begin, int end)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = malloc(sizeof(char) * (end - begin) + 1)))
		return (NULL);
	while (begin != end)
		str[i++] = line[begin++];
	str[i] = '\0';
	return (str);
}

static		void	check_content(char *str)
{
	int i;

	i = -1;
	if (!ft_isalpha(str[0]))
	{
		ft_putstr_fd("export: '", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
	}
	while (str[++i])
	{
		if (!ft_isalpha(str[i]) && !ft_isdigit(str[i])
		&& str[i] != '=' && str[i] != '+')
		{
			ft_putstr_fd("export: '", 2);
			ft_putstr_fd(str, 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
		}
	}
}

void				pars_export(char *line, t_struct *global)
{
	char	*str;
	int		begin;
	int		end;
	int		j;
	int		i;

	str = NULL;
	global->pars.arg = NULL;
	i = 6;					// undone
	begin = 0;
	end = 0;
	while (line[i])
	{
		while (ft_isspaces(line[i]))
			i++;
		if (line[i])
			begin = i;
		while (ft_isalnum_new(line[i]))
			i++;
		end = i;
		str = allocate_string(line, begin, end);
		ft_lstadd_back(&global->pars.arg, ft_lstnew(str));
		check_content(str);
		i++;
	}
	global->pars.cmd = 3;
}
