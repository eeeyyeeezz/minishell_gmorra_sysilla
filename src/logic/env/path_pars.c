/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 20:50:17 by ncliff            #+#    #+#             */
/*   Updated: 2021/03/29 18:36:00 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	**path_pars(t_struct *glb)
{
	char	**path_spl;
	char	*dupstr;
	t_list	*pathlst;

	pathlst = env_srch(glb, "PATH=");
	if (pathlst == NULL)
		return (NULL);
	dupstr = ft_substr(pathlst->content, 5, ft_strlen(pathlst->content) - 5);
	path_spl = ft_split(dupstr, ':');
	return (path_spl);
}

void	path_pars_to_lst(t_struct *glb)
{
	t_list	*new;
	char	**path_spl;
	int		i;

	i = 0;
	path_spl = path_pars(glb);
	while (path_spl[i])
	{
		new = ft_lstnew(path_spl[i]);
		ft_lstadd_back(&glb->path, new);
		i++;
	}
}
