/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:56:56 by ccarnot           #+#    #+#             */
/*   Updated: 2023/05/25 15:21:19 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h> 
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *buffer);
char	*ft_bufupdate(char *buffer, char *new_buf);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_strchr(char *str, char c);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

#endif
