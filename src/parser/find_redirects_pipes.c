/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_redirects_pipes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:19:11 by gmorra            #+#    #+#             */
/*   Updated: 2021/04/12 17:39:13 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void			find_redirects_pipes(t_struct *global, char *line)
{
	global->flags.ft_arg = 0;
	pars_characters(global, line);
}
