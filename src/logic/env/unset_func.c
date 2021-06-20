/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:28:55 by ncliff            #+#    #+#             */
/*   Updated: 2021/05/21 18:39:24 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"


// Переделать
int	ft_unset(t_struct *glb)
{
	t_list *tmp;
	t_list *first;
	t_list *cparg;

	write(1, "\n111\n", 5);
	cparg = glb->pars.arg;
	write(1, glb->pars.arg->content, ft_strlen(glb->pars.arg->content));
	write(1, "\n", 1);
	while (glb->pars.arg->next != NULL)
	{
		first = glb->env;
		tmp = env_srch(glb ,glb->pars.arg->content);
		write(1, glb->pars.arg->content, ft_strlen(glb->pars.arg->content));
		write(1, "\n", 1);
		if (tmp != NULL)
		{
			write(1, "\n222\n", 5);
			while (first->next != tmp)
			{
				first = first->next;
			}
			first->next = tmp->next;
			ft_lstdelone(tmp, free);
		}
		glb->pars.arg = glb->pars.arg->next;
	}
	return (1);
}