#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*a;

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
