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
			if ((U_CHR)(sort_mass[j][0]) - (U_CHR)(sort_mass[j + 1][0]) > 0)
			{
				str = ft_strdup_clean(sort_mass[j]);
				sort_mass[j] = ft_strdup_clean(sort_mass[j + 1]);
				sort_mass[j + 1] = ft_strdup_clean(str);
			}
			j++;
		}
		i++;
	}
	print_sortmass(sort_mass);
	freemass(sort_mass);
}

void	sort_mass1(t_env *env)
{
	char	**sort_mass;
	int		i;

	i = 0;
	env->count_str = cnt_str(env->sh_envp);
	sort_mass = (char **)ft_calloc(env->count_str + 1, sizeof(char *));
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
			in_export_while(av, env, index_eq, i);
			i++;
		}
	}
	return (1);
}
