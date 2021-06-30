/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:05:35 by sysilla           #+#    #+#             */
/*   Updated: 2021/06/28 16:05:38 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	right_red(char **cmd, char *file)
{
	int	fd;
	char	*line;
	// if ">" O_TRUNC, if ">>" O_APPEND
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	if (!fd)
		return (1);
	while (get_next_line(0, &line))
	{
		write(fd, line, sizeof(line));
		write(fd, "/n", 1);
		free(line);
	}
	close(fd);
	free(line);
	return (0);
}

int	left_red(char **cmd, char *file)
{
	//if "<" O_RDONLY
	int fd;

	fd = open(file, O_RDONLY);
	if (fd)
	{
		dup2(fd, 0);
		lsh_execute(cmd, envp, env);
	}
	else
	{
		printf("minishell: no such file or directory: %s", file);
	}
}

void