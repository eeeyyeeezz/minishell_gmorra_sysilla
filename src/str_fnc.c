/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_fnc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:35:54 by ncliff            #+#    #+#             */
/*   Updated: 2021/04/15 13:48:59 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_pars		*pars_st_new()
{
	t_pars	*new;

	new = (t_pars *)malloc(sizeof(t_pars));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->arg = NULL;
	new->cmd = 0;
	new->chr = 0;
	new->info_env = NULL;
	new->first_line = NULL;
	new->first_word = NULL;
	new->info = NULL;
	return (new);
}

void		pars_add_back(t_pars **lst, t_pars *new)
{
	t_pars	*a;

	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	a = *lst;
	while (a->next)
		a = a->next;
	a->next = new;
	return ;
}
