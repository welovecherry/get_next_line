/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungmiho <jungmiho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:54:39 by jungmiho          #+#    #+#             */
/*   Updated: 2023/05/06 18:06:38 by jungmiho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin_free(char *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*return_ptr;

	if (s1 == 0)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	return_ptr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!return_ptr)
	{
		free(s1);
		return (0);
	}
	ft_strlcpy(return_ptr, s1, s1_len + 1);
	ft_strlcat(return_ptr, s2, s1_len + s2_len + 1);
	free(s1);
	return (return_ptr);
}

char	*gnl_str_n_dup(const char *s1, int n)
{
	size_t	len;
	size_t	i;
	char	*copy_s1;
	char	*dup_ptr;

	copy_s1 = (char *)s1;
	len = ft_strlen(copy_s1);
	dup_ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup_ptr)
		return (0);
	i = 0;
	while (i < len && i < (size_t)n)
	{
		dup_ptr[i] = copy_s1[i];
		i++;
	}
	dup_ptr[i] = '\0';
	return (dup_ptr);
}

char	*read_all_concatenate_str(int fd, int *flag)
{
	int		read_bytes;
	char	*str;
	char	buff[BUFFER_SIZE + 1];

	read_bytes = read(fd, buff, BUFFER_SIZE);
	if (read_bytes == -1 || read_bytes == 0)
		return (0);
	buff[read_bytes] = '\0';
	str = gnl_str_n_dup(buff, read_bytes);
	while (read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
			return (NULL);
		if (read_bytes == 0)
			break ;
		buff[read_bytes] = '\0';
		str = gnl_strjoin_free(str, buff);
	}
	*flag = 1;
	return (str);
}

int	is_null(char *str, int *flag)
{
	*flag = 1;
	if (gnl_strchr_idx(str, '\0') == 0)
	{
		free(str);
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*new_str;
	static int	flag[3];
	char		*return_str;

	if (flag[0] == 0)
		str = read_all_concatenate_str(fd, &flag[0]);
	if (fd < 0 || str == 0 || flag[2] == 1)
		return (0);
	flag[1] = gnl_strchr_idx(str, '\n');
	if (flag[1] >= 0)
	{
		return_str = gnl_str_n_dup(str, flag[1] + 1);
		new_str = gnl_str_n_dup(str + flag[1] + 1, ft_strlen(str) - flag[1]);
		free(str);
		str = new_str;
	}
	else if (is_null(str, &flag[2]) == 1)
		return (0);
	else
		return (str);
	return (return_str);
}

//#include <fcntl.h> 
//#include <stdio.h>
//int	main(void)
//{
//	int		fd;
//	char	*res[55];
//	int		idx;

//	fd = open("example.txt", O_RDONLY);
//	idx = 0;
//	res[idx] = get_next_line(fd);
//	printf("%s", res[idx]);
//	while (idx < 16)
//	{
//		res[idx] = get_next_line(fd);
//		printf("%s", res[idx]);
//		idx++;
//	}
//	//while (1); // 터미널 하나 더 켜서 ps -> enter -> leaks a.out
//	return (0);
//}
