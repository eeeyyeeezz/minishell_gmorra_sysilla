/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:26:43 by sysilla           #+#    #+#             */
/*   Updated: 2021/05/21 16:26:45 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ch_dir(char *av, char **env)
{
	int		res;
	char	*oldpwd;
	char	dir[255];

	oldpwd = getenv("PWD");
	res = chdir(av);
	if (!res)
	{
		getcwd(dir, 255);
		// ft_putstr_fd(dir, 1);
	}
	return (0);
}

int	cd(char **argv, t_env *sh_env)
{
	char	*home;

	home = getenv("HOME");
	if (!argv[1])
	{
		ch_dir(home, sh_env->sh_envp);
		return (1);
	}
	if (argv[2])
	{
		ft_putstr_fd("cd: string not in pwd: ", 1);
		ft_putendl_fd(argv[1], 1);
		return (1);
	}
	ch_dir(argv[1], sh_env->sh_envp);
	return (1);
}
