/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_choice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncliff <ncliff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:04:28 by ncliff            #+#    #+#             */
/*   Updated: 2021/05/22 15:12:47 by ncliff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int lgc_choise(t_struct *glb)
{
	printf("\n%d\n", glb->pars.cmd);
	if (glb->pars.cmd == 1) // cd
		ft_cd(glb);
    else if (glb->pars.cmd == 2) // pwd
        ft_pwd(glb);
    else if (glb->pars.cmd == 3) // export
        ft_export(glb);
	else if (glb->pars.cmd == 4) // unset
      ft_unset(glb);
	else if (glb->pars.cmd == 5) // env
        ft_env(glb);
    glb->pars.cmd = -1;
	return (0);
}