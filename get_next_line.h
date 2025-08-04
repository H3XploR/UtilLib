/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yantoine <yantoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:34:57 by hexplor           #+#    #+#             */
/*   Updated: 2024/10/25 21:23:32 by yantoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*gnl_ft_getline(char *static_str);
char	*gnl_ft_strjoin(char *s1, char *s2);
char	*gnl_ft_strchr(char *s, int c);
size_t	gnl_ft_strlen(char *s);
char	*gnl_ft_remove_bn(char *static_str);
char	*gnl_read_fd(int fd, char *str);

#endif
