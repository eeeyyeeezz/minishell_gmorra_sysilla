/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:03:35 by sysilla           #+#    #+#             */
/*   Updated: 2021/06/11 13:03:37 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	shlvl(t_env *env)
{
	int		i;
	int		lvl;
	char	*shlvl;

	shlvl = (char *)ft_calloc(ft_strlen("SHLVL="), sizeof(char *));
	if (!shlvl)
		ft_error("malloc error!");
	shlvl = "SHLVL=";
	i = ft_strmasschr(shlvl, env->sh_envp, 5);
	if (i == -1)
		add_to_env(shlvl, "2", env);
	else
	{
		lvl = ft_atoi(&env->sh_envp[i][6]);
		free(env->sh_envp[i]);
		env->sh_envp[i] = ft_strjoin(shlvl, ft_itoa(++lvl));
	}
}
