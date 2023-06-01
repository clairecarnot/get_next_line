/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:56:32 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/30 14:33:36 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

char	*ft_bufupdate(char *buffer, char *new_buf)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, new_buf);
	free(buffer);
	return (tmp);
}

char	*ft_read(int fd, char *buffer)
{
	int		ret;
	char	*new_buf;

	if (!buffer)
	{
		buffer = ft_calloc(1, 1);
		if (!buffer)
			return (NULL);
	}
	new_buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!new_buf)
		return (NULL);
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, new_buf, BUFFER_SIZE);
		if (ret == -1)
			return (free(new_buf), NULL);
		new_buf[ret] = '\0';
		buffer = ft_bufupdate(buffer, new_buf);
		if (ft_strchr(buffer, '\n') != -1)
			break ;
	}
	free(new_buf);
	return (buffer);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(sizeof(char), (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_bufremain(char *buffer)
{
	int		i;
	int		j;
	char	*remain;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	remain = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!remain)
		return (free(buffer), NULL);
	i++;
	j = 0;
	while (buffer[i])
		remain[j++] = buffer[i++];
	free(buffer);
	return (remain);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd == -1 || fd > 1024)
		return (0x0);
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (!buffer[fd])
		return (0x0);
	line = ft_line(buffer[fd]);
	buffer[fd] = ft_bufremain(buffer[fd]);
	return (line);
}

/*
int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*dst;

	fd1 = open("test.txt", O_RDONLY, S_IRUSR);
	if (fd1 == -1)
	{
		write(1, "(open1 failed)", 13);
		return (1);
	}
	fd2 = open("test2.txt", O_RDONLY, S_IRUSR);
	if (fd2 == -1)
	{
		write(1, "(open2 failed)", 13);
		return (1);
	}
	fd3 = open("test3.txt", O_RDONLY, S_IRUSR);
	if (fd3 == -1)
	{
		write(1, "(open3 failed)", 13);
		return (1);
	}
	dst = get_next_line(fd1);
	printf("%s", dst);
	dst = get_next_line(fd2);
	printf("%s", dst);
	dst = get_next_line(fd3);
	printf("%s", dst);
	while (1)
	{
		dst = get_next_line(fd2);
		printf("%s", dst);
		if (dst == 0x0)
			break;
		free(dst);
	}
	dst = get_next_line(fd1);
	printf("%s", dst);
	if (close(fd1) == -1)
	{
		write(1, "(close failed)", 14);
		return (1);
	}
	if (close(fd2) == -1)
	{
		write(1, "(close failed)", 14);
		return (1);
	}
	if (close(fd3) == -1)
	{
		write(1, "(close failed)", 14);
		return (1);
	}
	return (0);
}*/
