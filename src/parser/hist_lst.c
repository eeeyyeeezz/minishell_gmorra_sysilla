/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:16:58 by gmorra            #+#    #+#             */
/*   Updated: 2021/04/09 17:18:14 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_histclear(t_history **lst, void (*del)(void*))
{
	t_history	*a;

	while ((*lst)->prev != NULL)
		(*lst) = (*lst)->prev;
	while ((*lst))
	{
		a = (*lst)->next;
		if (del != NULL)
			del((*lst)->content);
		(*lst)->content = NULL;
		free(*lst);
		*lst = a;
	}
}

t_history	*ft_histnew(void *content)
{
	t_history	*newlist;

	if (!(newlist = (t_history *)malloc(sizeof(t_history))))
		return (NULL);
	newlist->content = content;
	newlist->next = NULL;
	newlist->prev = NULL;
	return (newlist);
}

void	ft_histadd_back(t_history **lst, t_history *new)
{
	t_history	*current;

	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
	new->prev = current;
	return ;
}
