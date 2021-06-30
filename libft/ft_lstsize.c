/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 20:18:10 by ncliff            #+#    #+#             */
/*   Updated: 2021/04/04 18:48:53 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*cp_lst;

	i = 0;
	cp_lst = lst;
	if (!cp_lst)
		return (0);
	while (cp_lst)
	{
		cp_lst = cp_lst->next;
		i += 1;
	}
	return (i);
}
