/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:58:22 by gmorra            #+#    #+#             */
/*   Updated: 2021/04/08 17:02:40 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

static	int			ft_return_neg(char *buf)
{
	if (buf)
	{
		free(buf);
		buf = NULL;
	}
	return (-1);
}

static char			*check_remainer(char **remainer, char **line)
{
	char *free_ptr;
	char *ptr;

	ptr = NULL;
	if (*remainer)
		if ((ptr = ft_strchr_gnl(*remainer, '\n')))
		{
			*ptr = '\0';
			*line = ft_strdup(*remainer);
			free_ptr = *remainer;
			*remainer = ft_strdup(++ptr);
			free(free_ptr);
		}
		else
		{
			*line = ft_strdup(*remainer);
			free(*remainer);
			*remainer = NULL;
		}
	else
		*line = ft_strdup("");
	return (ptr);
}

int					get_next_line(int fd, char **line)
{
	char			*buf;
	char			*ptr;
	static	char	*remainer;
	int				byte_read;

	buf = NULL;
	if (BUFFER_SIZE <= 0 || !line || !(buf = malloc(BUFFER_SIZE + 1))
		|| (read(fd, buf, 0) == -1))
		return (-1);
	ptr = check_remainer(&remainer, line);
	while (!ptr && (byte_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[byte_read] = '\0';
		if ((ptr = ft_strchr_gnl(buf, '\n')))
		{
			*ptr = '\0';
			if (!(remainer = ft_strdup(++ptr)))
				return (ft_return_neg(buf));
		}
		if (!(*line = ft_strjoin_new(*line, buf)))
			return (ft_return_neg(buf));
	}
	free(buf);
	return (ptr != NULL ? 1 : 0);
}
