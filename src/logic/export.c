/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 14:01:21 by sysilla           #+#    #+#             */
/*   Updated: 2021/05/26 14:01:22 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*insert_q(char *env)
{
	char	*sort_mass;
	char	*value;
	char	*key;
	int		eq;

	eq = str_index(env, '=');
	value = ft_strdup(&env[eq + 1]);
	if (value == NULL)
		value = ft_strdup("\"");
	else
		value = ft_strjoin(value, "\"");
	key = ft_strndup(env, eq + 1);
	key = ft_strjoin(key, "\"");
	sort_mass = ft_strjoin(key, value);
	free(value);
	free(key);
	return (sort_mass);
}

void	ft_err(char *err)
{
	ft_putendl_fd(err, 1);
	exit(1);
}

void	sort_mass2(char **sort_mass, int count_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (i < count_str - 1)
	{
		j = 0;
		while (j < (count_str - 1) - i)
		{
			if ((unsigned char)(sort_mass[j][0]) - (unsigned char)(sort_mass[j + 1][0]) > 0)
			{
				str = ft_strdup(sort_mass[j]);	
				sort_mass[j] = ft_strdup(sort_mass[j + 1]);
				sort_mass[j + 1] = ft_strdup(str);
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (sort_mass[i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putendl_fd(sort_mass[i], 1);
		i++;
	}
}

void	sort_mass1(t_env *env)
{
	char	**sort_mass;
	char	*value;
	int		i;
	int		eq;

	i = 0;
	env->count_str = cnt_str(env->sh_envp);
	sort_mass = (char **)ft_calloc(env->count_str + 1, sizeof(char *));;
	while (i < env->count_str)
	{
		sort_mass[i] = insert_q(env->sh_envp[i]);
		i++;
	}
	i = 0;
	sort_mass2(sort_mass, env->count_str);
}

void	freemass(char **arr)
{
	int		i;

	i = -1;
	while (arr[++i])
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr);
	arr = NULL;
}

int	ft_export(char **av, t_env *env)
{
	int		i;
	int		index_eq;
	char	*key;

	i = 1;
	if (!av[1])
	{
		sort_mass1(env);
	}
	else
	{
		while (av[i])
		{
			index_eq = str_index(av[i], '=');
			key = ft_strndup(av[i], index_eq + 1);
			if (!key)
				ft_err("ivalid key");
			else
			{
				if (!(ft_strchr(av[i], '=')))
				{
					key = ft_strjoin(key, "=");
					add_to_env(key, "", env);
				}
				add_to_env(key, &av[i][index_eq + 1], env);
			}
			i++;
		}
	}
	return (1);
}