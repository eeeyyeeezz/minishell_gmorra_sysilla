<<<<<<< HEAD
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:50:54 by gmorra            #+#    #+#             */
/*   Updated: 2020/11/06 20:57:30 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> 4128ad9df73a2acc5758061d18c5b2b37cb2486c
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	if (!f)
		return ;
	while (lst)
	{
		f(lst->content);
		tmp = lst->next;
		lst = tmp;
	}
	lst = NULL;
}
