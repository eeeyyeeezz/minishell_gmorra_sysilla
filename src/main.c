/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:10:05 by gmorra            #+#    #+#             */
/*   Updated: 2021/04/12 15:51:54 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int				main(int argc, char **argv, char **env)
{
	t_struct global;

	global.fd = 1;

	global.pars.arg = NULL;
	env_add(&global, env);

	ft_parser(&global);
	return (0);
}
