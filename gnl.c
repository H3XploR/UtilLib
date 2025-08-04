/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yantoine <yantoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:35:58 by hexplor           #+#    #+#             */
/*   Updated: 2024/10/25 21:47:48 by yantoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*static_str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	static_str = gnl_read_fd(fd, static_str);
	if (!static_str)
		return (NULL);
	line = gnl_ft_getline(static_str);
	static_str = gnl_ft_remove_bn(static_str);
	return (line);
}

char	*gnl_read_fd(int fd, char *str)
{
	char	*tmp;
	int		bytes;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	bytes = 1;
	while (!gnl_ft_strchr(str, '\n') && (bytes != 0))
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[bytes] = '\0';
		str = gnl_ft_strjoin(str, tmp);
	}
	free(tmp);
	return (str);
}

char	*gnl_ft_getline(char *static_str)
{
	int		i;
	char	*line;

	i = 0;
	if (!static_str[i])
		return (NULL);
	while (static_str[i] && static_str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (static_str[i] && static_str[i] != '\n')
	{
		line[i] = static_str[i];
		i++;
	}
	if (static_str[i] == '\n')
	{
		line[i] = static_str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*gnl_ft_remove_bn(char *static_str)
{
	int		i;
	int		j;
	char	*restof;

	i = 0;
	while (static_str[i] && static_str[i] != '\n')
		i++;
	if (!static_str[i])
	{
		free(static_str);
		return (NULL);
	}
	restof = (char *)malloc(sizeof(char) * (gnl_ft_strlen(static_str) - i + 1));
	if (!restof)
		return (NULL);
	i++;
	j = 0;
	while (static_str[i])
		restof[j++] = static_str[i++];
	restof[j] = '\0';
	free(static_str);
	return (restof);
}
