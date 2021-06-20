/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file_history.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:05:25 by gmorra            #+#    #+#             */
/*   Updated: 2021/04/12 17:38:31 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void					gnl_history_to_list(t_struct *global)
{
	int				new_fd;
	char			*str;

	str = NULL;
	new_fd = open("minishell_history", O_RDONLY, 0777);
	while (get_next_line(new_fd, &str))
	{
		ft_histadd_back(&global->history, ft_histnew(ft_strdup(str)));
		free(str);
		str = NULL;
	}
	ft_histadd_back(&global->history, ft_histnew(ft_strdup(str)));
	free(str);
	str = NULL;
	close(new_fd);
}



static	void			make_file_history(char *line, int fd, t_struct *global)
{
	int			num;
	int			fake_fd;

	write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
	ft_histclear(&global->history, free);
	gnl_history_to_list(global);
}

void					open_file_history(char *line, t_struct *global)
{
	int		fd;
	char	buf;
	char	*str;

	str = NULL;
	fd = open("minishell_history", O_CREAT | O_RDWR | O_APPEND, 0777);
	if (line[0])
		make_file_history(line, fd, global);
	close(fd);
}
