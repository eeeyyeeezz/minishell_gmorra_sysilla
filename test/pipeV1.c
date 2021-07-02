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

void	close_pipes(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->cn)
	{
		close(env->fd[i][0]);
		close(env->fd[i][1]);
	}
}

static void	assoc_pipes(int it, t_env *env)
{
	if (it < env->cn - 1)
		dup2(env->fd[it][1], 1);
	if (it > 0)
		dup2(env->fd[it - 1][0], 0);
	else
		dup2(env->basefd1, STDOUT_FILENO);
}

void	init_pipes(t_env *env)
{
	int	i;
	i = 0;
	while (i < env->cn)
	{
		pipe(env->fd[i]);
		i++;
	}
}

void	start_pipe(t_env *env, char **args)
{
	int	i;

	init_pipes(env);
	i = 0;
	while (i < env->cn)
	{
		env->pid[i] = fork();
		if (env->pid == 1)		//child
		{
			chld_sig();
			assoc_pipes(i, env);
			close_pipes(env);
			lsh_execute_pipe(args, env->sh_envp, env);							//тут обработка базовыых фд, наличия команд, и запук execve
		}
		
	}
	
}