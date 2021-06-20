/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorra <gmorra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 13:35:05 by gmorra            #+#    #+#             */
/*   Updated: 2021/03/13 17:42:54 by gmorra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int			get_next_line(int fd, char **line);
char		*ft_strjoin_new(char *s1, char *s2);
char		*ft_strdup(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoin_new(char *s1, char *s2);
char		*ft_strchr_gnl(const char *s, int c);

#endif
