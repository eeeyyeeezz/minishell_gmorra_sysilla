/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:29:35 by ncliff            #+#    #+#             */
/*   Updated: 2021/05/22 15:30:08 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_cd(t_struct *glb)
{
	char	dir[1000];
	char	*helper;

	if (glb->pars.info == NULL)
	{
		env_export(glb, ft_strjoin("OLDPWD=", getcwd(dir, 1000)));
		helper = env_srch_str(glb, "HOME=");
		printf("\nINFO CD [%s]\n", glb->pars.info);
		chdir(helper);
		free(helper);
	}
	else
	{
		env_export(glb, ft_strjoin("OLDPWD=", getcwd(dir, 1000)));
		helper = ft_strjoin(dir, glb->pars.info);
		printf("\nINFO CD [%s]\n", glb->pars.info);
		chdir(helper);
		free(helper);
		env_export(glb, ft_strjoin("PWD=", getcwd(dir, 1000)));
	}
	return (1);
}

int ft_pwd(t_struct *glb)
{
	char my_pwd[1000];

	getcwd(my_pwd, 1000);
	ft_putstr_fd(my_pwd, glb->fd);
	write(glb->fd, "\n", 1);
	return (0);
}