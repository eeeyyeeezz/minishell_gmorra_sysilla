/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 18:24:17 by sysilla           #+#    #+#             */
/*   Updated: 2021/06/01 18:24:19 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	del_in_env(char *key, t_env *env, int index)
{
	char	**new_env;
	int		i;
	int		j;

	env->count_str = cnt_str(env->sh_envp);
	new_env = (char **)ft_calloc((env->count_str - 1) + 2, sizeof(char *));
	if (!new_env)
		ft_error("malloc error");
	i = 0;
	j = 0;
	while (i < env->count_str)
	{
		if (i == index)
		{
			i++;
		}
		if (env->sh_envp[i])
			new_env[j] = ft_strdup(env->sh_envp[i]);
		i++;
		j++;
	}
	freemass(env->sh_envp);
	env->sh_envp = new_env;
	return (0);
}

int	find_key_in_env(char *key, t_env *env)
{
	int	i;
	int	len_key;

	len_key = ft_strlen(key);
	i = 0;
	while (env->sh_envp[i])
	{
		if (!(ft_strncmp(key, env->sh_envp[i], len_key)))
			return (i);
		i++;
	}
	return (-1);
}

int	ft_unset(char **av, t_env *env)
{
	char	*key;
	int		i;
	int		index;

	i = 1;
	if (!av[1])
		return (ft_err("empty key\n"));
	if (ft_strnstr(av[1], "=", ft_strlen(av[1])))
	{
		printf("minishell: unset: `%s': not a valid identifier\n", av[1]);
		return (2);
	}
	while (av[i])
	{
		index = find_key_in_env(av[i], env);
		if (index >= 0)
		{
			del_in_env(av[i], env, index);
		}
		i++;
	}
	return (1);
}
