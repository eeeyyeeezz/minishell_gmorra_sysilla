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
	char	*lvll;
	char	*shlvl;

	shlvl = ft_strdup("SHLVL=");
	i = ft_strmasschr(shlvl, env->sh_envp, 5);
	if (i == -1)
		add_to_env(shlvl, "2", env);
	else
	{
		lvl = ft_atoi(&env->sh_envp[i][6]);
		lvll = ft_itoa(++lvl);
		free(env->sh_envp[i]);
		env->sh_envp[i] = ft_strjoin(shlvl, lvll);
		ft_free((void *)&lvll);
	}
	free(shlvl);
}