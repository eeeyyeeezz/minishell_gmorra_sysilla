/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pocket_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:52:59 by gmorra            #+#    #+#             */
/*   Updated: 2021/04/07 16:07:53 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void			ft_write(char *line, char *str, char *close)
{
	ft_putstr_fd(line, 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd(close, 1);
}

void			ft_free(void **var)
{
	free(*var);
	*var = NULL;
}
