/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tr_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:11:25 by sysilla           #+#    #+#             */
/*   Updated: 2021/05/24 14:11:27 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_envp_cpy(char *envp[], t_env *buf)
{
	int		i;
	char	**envp_cpy;

	i = 0;
	while (envp[i])
		i++;
	envp_cpy = (char **)ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (envp[i])
	{
		envp_cpy[i] = strdup(envp[i]);
		i++;
	}
	buf->sh_envp = envp_cpy;
}

void	add_to_env2(char **envp, char *add, t_env *env)
{
	char	**buf;
	int		i;
	int		j;

	i = 0;
	while (envp[i])
		i++;
	buf = (char **)ft_calloc(i + 2, sizeof(char *));
	if (!buf)
		ft_error("errrrore");
	j = -1;
	while (++j < i)
		buf[j] = envp[j];
	buf[j] = ft_strdup(add);
	ft_free((void *)&envp);
	ft_envp_cpy(buf, env);
	freemass(buf);
}

void	add_to_env_plus(char *key, char *add, t_env *env)
{
	int		i;
	int		cmplen;
	char	*newelem;
	char	*tmp;

	cmplen = ft_strlen(key);
	i = ft_strmasschr(key, env->sh_envp, cmplen);
	if (i == -1)
	{
		newelem = ft_strjoin(key, add);
		add_to_env2(env->sh_envp, newelem, env);
		free(newelem);
	}
	else
	{
		tmp = ft_strdup(env->sh_envp[i]);
		free(env->sh_envp[i]);
		env->sh_envp[i] = ft_strjoin(tmp, add);
		free(tmp);
	}
}

void	add_to_env(char *key, char *add, t_env *env)
{
	int		i;
	int		cmplen;
	char	*newelem;

	cmplen = ft_strlen(key);
	i = ft_strmasschr(key, env->sh_envp, cmplen);
	newelem = ft_strjoin(key, add);
	if (i == -1)
	{
		add_to_env2(env->sh_envp, newelem, env);
		free(newelem);
	}
	else
	{
		free(env->sh_envp[i]);
		env->sh_envp[i] = newelem;
	}
}

int	str_index(char *str, char c)
{
	int		index;

	index = -1;
	while (str[++index])
	{
		if (str[index] == c)
			return (index);
	}
	return (index);
}
