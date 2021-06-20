/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:05:03 by ncliff            #+#    #+#             */
/*   Updated: 2021/05/21 15:01:09 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	env_print_exp_dop(t_struct *glb, char *str)
{
	int		i;

	i = 0;
	write(glb->fd, "declare -x ", 11);
	while (str[i] != '=' && str[i] != '\0')
	{
		write(glb->fd, &str[i], 1);
		i++;
	}
	if (ft_memchr(str, '=', ft_strlen(str)) == NULL)
	{
		write(glb->fd, "\n", 1);
		return ;
	}
	write(glb->fd, "=\"", 2);
	i++;
	while (str[i] != '\0')
	{
		write(glb->fd, &str[i], 1);
		i++;
	}
	write(glb->fd, "\"\n", 2);
}

void		env_print_exp(t_struct *glb)
{
	t_list	*first;
	t_list	*cplst;
	t_list	*srch;
	char	*str;

	cplst = ft_lstcpy(glb->env);
	first = cplst;
	env_sort(cplst);
	while (cplst->next)
	{
		str = (char *)cplst->content;
		env_print_exp_dop(glb, str);
		cplst = cplst->next;
	}
	str = (char *)cplst->content;
	env_print_exp_dop(glb, str);
	ft_lstclear(&first, free);
	cplst = NULL;
	first = NULL;
	srch = env_srch(glb, "OLDPWD");
	if (srch == NULL)
		write(glb->fd, "declare -x OLDPWD\n", 18);
}

t_list		*env_cont_join(t_struct *glb, char *str)
{
	t_list	*srch;
	char	*cpstr;
	char	*cpcont;
	int		i;

	i = 0;
	cpstr = ft_strdup(str);
	while (cpstr[i] != '+' && cpstr[i] != '\0')
		i++;
	cpstr[i] = '\0';
	srch = env_srch(glb, cpstr);
	if (srch == NULL)
		srch = env_add_back(glb, str);
	else
	{
		cpcont = ft_strjoin(srch->content, str + (i + 2));
		free(srch->content);
		free(str);
		srch->content = cpcont;
	}
	free(cpstr);
	return (srch);
}