/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:43:36 by ncliff            #+#    #+#             */
/*   Updated: 2021/05/21 16:33:02 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*env_srch_str(t_struct *glb, char *str)
{
	t_list *srch;

	srch = env_srch(glb, str);
	return (ft_strdup(srch->content + ft_strlen(str)));
}

int		ft_env(t_struct *glb)
{
	t_list	*cplst;
	int		i;

	cplst = glb->env;
	i = 0;
	while (cplst->next)
	{
		if (ft_memchr(cplst->content, '=', ft_strlen(cplst->content)) != NULL)
		{
			write(glb->fd, cplst->content, ft_strlen(cplst->content));
			write(glb->fd, "\n", 1);
		}
		cplst = cplst->next;
	}
	if (ft_memchr(cplst->content, '=', ft_strlen(cplst->content)) != NULL)
	{
		write(glb->fd, cplst->content, ft_strlen(cplst->content));
		write(glb->fd, "\n", 1);
	}
	return (1);
}

int		ft_export(t_struct *glb)
{
	t_list *cplst;
	t_list *first;

	if (glb->pars.arg == NULL)
		env_print_exp(glb);
	else
	{
		cplst = ft_lstcpy(glb->pars.arg);
		first = cplst;
		while (cplst->next)
		{
			// TODO: добавлять строки без знака =
			env_export(glb, cplst->content);
			cplst = cplst->next;
		}
		env_export(glb, cplst->content);
		ft_lstclear(&first, NULL);
	}
	return (1);
}
