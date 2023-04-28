/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungmiho <jungmiho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:36:35 by jungmiho          #+#    #+#             */
/*   Updated: 2023/04/28 15:10:51 by jungmiho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// allowed header ?? 123123123123123123123
# include <stdlib.h> // ssize_t, malloc, free
# include <unistd.h> // for read() function
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char	*get_next_line(int fd);
char	*read_all_concatenate_str(int fd, int *flag_newline);
char	*gnl_strjoin_free(char *s1, char const *s2);
char	*gnl_str_n_dup(const char *s1, int n);
int		gnl_strchr_idx(const char *s, int c);
//void	*ft_memcpy(void *dst, const void *src, size_t n); // delete
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

#endif