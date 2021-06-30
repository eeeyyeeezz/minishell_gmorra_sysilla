/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeV1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 12:49:06 by sysilla           #+#    #+#             */
/*   Updated: 2021/06/30 12:49:08 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	start_pipe(int *fd, t_env *env)
{
    pipe(fd);
    dup2(STDOUT_FILENO, fd[1]);
    close(STDOUT_FILENO);
    dup2(fd[1], STDIN_FILENO);
}

void    mid_pipe(int *fd, t_env *env)
{

}

void    end_pipe(int *fd, t_env *env)
{
    
}