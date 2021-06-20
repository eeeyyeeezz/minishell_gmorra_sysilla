/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 22:02:15 by ncliff            #+#    #+#             */
/*   Updated: 2021/04/09 17:07:29 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*a;

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
