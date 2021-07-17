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
