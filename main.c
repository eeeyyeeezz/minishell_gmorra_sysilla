/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:44:58 by sysilla           #+#    #+#             */
/*   Updated: 2021/05/24 14:45:00 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bildin/header.h"

int main(int ac, char **av, char **envp)
{
	t_env env;
	ft_envp_cpy(envp, &env);
	shlvl(&env);
	export(av, &env);
	// unset(av, &env);
	// ft_env(&env);
	return(0);
}