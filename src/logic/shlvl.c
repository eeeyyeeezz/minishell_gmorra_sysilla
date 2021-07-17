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

void	tr_shlvl(t_env *env, int i, char *shlvl)
{
	int		lvl;
	char	*lvll;

	lvl = ft_atoi(&env->sh_envp[i][6]);
	if (lvl == 999)
	{
		free(env->sh_envp[i]);
		env->sh_envp[i] = ft_strjoin(shlvl, "");
	}
	else
	{
		lvll = ft_itoa(++lvl);
		free(env->sh_envp[i]);
		env->sh_envp[i] = ft_strjoin(shlvl, lvll);
		ft_free((void *)&lvll);
	}
}

void	shlvl(t_env *env)
{
	int		i;
	char	*shlvl;

	shlvl = ft_strdup("SHLVL=");
	i = ft_strmasschr(shlvl, env->sh_envp, 5);
	if (i == -1)
		add_to_env(shlvl, "2", env);
	else
	{
		if (!(env->sh_envp[i][6] == '\"') && !(env->sh_envp[i][7] == '\"'))
			tr_shlvl(env, i, shlvl);
		else
			add_to_env(shlvl, "1", env);
	}
	free(shlvl);
}
