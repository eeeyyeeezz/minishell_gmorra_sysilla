/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:43:13 by ncliff            #+#    #+#             */
/*   Updated: 2021/05/21 16:32:40 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int		env_add(t_struct *glb, char **env)
{
	int		i;
	t_list	*new;

	i = 0;
	while (env[i] != NULL)
	{
		new = ft_lstnew(ft_strdup(env[i]));
		if (new == NULL)
			return (-1);
		ft_lstadd_back(&glb->env, new);
		i++;
	}
	return (1);
}

t_list	*env_add_back(t_struct *glb, char *str)
{
	t_list *new;

	new = ft_lstnew(str);
	if (new == NULL)
		return (NULL);
	ft_lstadd_back(&glb->env, new);
	return (new);
}

t_list	*env_srch(t_struct *glb, char *str)
{
	t_list *env_cp;

	env_cp = glb->env;
	while (env_cp->next != NULL)
	{
		if (ft_strncmp(env_cp->content, str, ft_strlen(str)) == 0)
		{
			return (env_cp);
		}
		env_cp = env_cp->next;
	}
	if (ft_strncmp(env_cp->content, str, ft_strlen(str)) == 0)
	{
		return (env_cp);
	}
	return (NULL);
}

t_list	*env_export(t_struct *glb, char *str)
{
	t_list	*srch;
	char	*cpstr;
	int		i;

	i = 0;
	cpstr = ft_strdup(str);
	while (cpstr[i] != '=' && cpstr[i] != '\0')
		i++;
	if (cpstr[i - 1] == '+' && cpstr[i] == '=')
	{
		free(cpstr);
		return (env_cont_join(glb, str));
	}
	cpstr[i] = '\0';
	srch = env_srch(glb, cpstr);
	if (srch == NULL)
		srch = env_add_back(glb, str);
	else
	{
		if (ft_memchr(str, '=', ft_strlen(str)) == NULL)
		{
			free(str);
			free(cpstr);
			return (srch);
		}
		free(srch->content);
		srch->content = str;
	}
	free(cpstr);
	return (srch);
}

char	**env_to_array(t_struct *glb)
{
	t_list	*cplst;
	char	**map;
	int		i;

	i = 0;
	cplst = glb->env;
	map = (char **)malloc(sizeof(char *) * ft_lstsize(glb->env));
	if (map == NULL)
		return (NULL);
	while (cplst->next)
	{
		map[i] = ft_strdup(cplst->content);
		cplst = cplst->next;
		i++;
	}
	map[i] = ft_strdup(cplst->content);
	return (map);
}
