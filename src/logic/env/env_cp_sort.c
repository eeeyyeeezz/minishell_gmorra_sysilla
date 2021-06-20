/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cp_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 21:06:25 by ncliff            #+#    #+#             */
/*   Updated: 2021/05/20 17:39:26 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_list		*ft_lstcpy(t_list *lst)
{
	t_list *lst_cp;
	t_list *first;

	first = lst;
	lst_cp = NULL;
	if (lst == NULL)
		return(NULL);
	while (first->next)
	{
		ft_lstadd_back(&lst_cp, ft_lstnew(ft_strdup(first->content)));
		first = first->next;
	}
	ft_lstadd_back(&lst_cp, ft_lstnew(ft_strdup(first->content)));
	return (lst_cp);
}

int         ft_lencmp(char *str1, char *str2)
{
    if (ft_strlen(str1) >= ft_strlen(str2))
        return (ft_strlen(str1));
    else
        return (ft_strlen(str2));
    return (0);
}

char        *ch_rep(char *str, char ch1, char ch2)
{
    int     pnt;
    char    *str_cp;

    pnt = 0;
    str_cp = ft_strdup(str);
    while (str_cp[pnt] != ch1 && str_cp[pnt] != '\0')
		pnt++;
	str_cp[pnt] = ch2;
    return (str_cp);
}

void		env_sort(t_list *env)
{
	int		i;
	t_list	*cp_lst;
	char	*cp_cont;
	char	*cp_str1;
	char	*cp_str2;

	i = ft_lstsize(env);
	while (i != 0)
	{
		cp_lst = env;
		while (cp_lst->next)
		{
			cp_str1 = ch_rep(cp_lst->content, '=', '\0');
			cp_str2 = ch_rep(cp_lst->next->content, '=', '\0');
			if (ft_strncmp(cp_str1, cp_str2, ft_lencmp(cp_str1, cp_str2)) > 0)
			{
				cp_cont = cp_lst->content;
				cp_lst->content = cp_lst->next->content;
				cp_lst->next->content = cp_cont;
			}
			free(cp_str1);
			cp_str1 = NULL;
			free(cp_str2);
			cp_str2 = NULL;
			cp_lst = cp_lst->next;
		}
		i--;
	}
}