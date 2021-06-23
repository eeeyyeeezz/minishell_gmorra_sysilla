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
	char	*path;

	i = 0;
	while (envp[i])
		i++;
	envp_cpy = (char **)ft_calloc(i + 1, sizeof(char *));
	path = NULL;
	i = -1;
	while (envp[++i])
	{
		envp_cpy[i] = ft_strdup(envp[i]);
		if (!ft_strncmp(envp[i], "PATH=", 5))
			path = &envp_cpy[i][5];
		else if (!ft_strncmp(envp[i], "TERM=", 5))
			buf->sh_term = &envp_cpy[i][5];
		else if (!ft_strncmp(envp[i], "SHLVL=", 6))
			buf->sh_lvl = &envp_cpy[i][6];
	}
	buf->sh_envp = envp_cpy;
	buf->sh_path = path;
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
		ft_err("errrrore");
	j = -1;
	while (++j < i)
		buf[j] = envp[j];
	buf[j] = ft_strdup(add);
	free(envp);
	ft_envp_cpy(buf, env);
	freemass(buf);
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

int	cnt_chr(char **src)
{
	int		i;
	int		j;
	int		max_char;

	max_char = 0;
	i = 0;
	while (src[i])
	{
		j = 0;
		while (src[i][j] != '\0')
		{
			j++;
		}
		if (max_char < j)
		{
			max_char = j;
		}
		i++;
	}
	return (max_char);
}

int	cnt_str(char **src)
{	
	int	i;

	i = 0;
	while (src[i])
	{
		i++;
	}
	return (i);
}