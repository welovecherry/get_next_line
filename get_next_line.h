/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungmiho <jungmiho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:36:35 by jungmiho          #+#    #+#             */
/*   Updated: 2023/04/15 21:57:07 by jungmiho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h> // ssize_t
#include <fcntl.h> // oepn(), close() function // deletetetetetetet
#include <errno.h> // perror
#include <string.h>


// allowed header ??
#include <stdlib.h> // ssize_t, malloc, free
#include <unistd.h> // for read() function
#define BUFF_SIZE 7

//	 ㅇㅏㄴ쓰는 함함수  삭삭제제해해라라
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strndup(const char *s1, int	n);
//char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_strchr_i(const char *s, int c);

#endif