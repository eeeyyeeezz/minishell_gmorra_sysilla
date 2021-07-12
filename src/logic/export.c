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
	char	*tmp;
	int		eq;

	eq = str_index(env, '=');
	tmp = ft_strdup(&env[eq + 1]);
	if (value == NULL)
		value = ft_strdup("\"");
	else
		value = ft_strjoin(tmp, "\"");
	free(tmp);
	tmp = ft_strndup(env, eq + 1);
	key = ft_strjoin(tmp, "\"");
	sort_mass = ft_strjoin(key, value);
	free(value);
	free(key);
	free(tmp);
	return (sort_mass);
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
				str = ft_strdup_clean(sort_mass[j]);	
				sort_mass[j] = ft_strdup_clean(sort_mass[j + 1]);
				sort_mass[j + 1] = ft_strdup_clean(str);
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
	freemass(sort_mass);
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

int ft_isnu(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] <= '9' && s[i] >= '0')
			i++;
		else
			return (1);
	}
	return (0);
}

void	export_plus(char *av, t_env *env, int index_eq)
{
	char	*key;
	char	*tmp;

	tmp = ft_strndup(av, index_eq - 1);
	if (!tmp || !(ft_isnu(tmp)))
		printf("minishell: export: `%s': not a valid identifier\n", key);
	key = ft_strjoin(tmp, "=");
	add_to_env_plus(key, &av[index_eq + 1], env);
	free(key);
	free(tmp);
}

int	ft_export(char **av, t_env *env)
{
	int		i;
	int		index_eq;
	char	*key;
	char	*tmp;

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
			if (av[i][index_eq - 1] == '+')
				export_plus(av[i], env, index_eq);
			else
			{
				tmp = ft_strndup(av[i], index_eq);
				if (!tmp || !(ft_isnu(tmp)))
					printf("minishell: export: `%s': not a valid identifier\n", tmp);
				else
				{
					key = ft_strjoin(tmp, "=");
					if (!(ft_strchr(av[i], '=')))
						add_to_env(key, "", env);
					else
						add_to_env(key, &av[i][index_eq + 1], env);
					free(key);
				}
				free(tmp);
			}
			i++;
		}
	}
	return (0);
}
