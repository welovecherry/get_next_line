/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungmiho <jungmiho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:54:39 by jungmiho          #+#    #+#             */
/*   Updated: 2023/04/24 23:00:24 by jungmiho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int gnl_strchr_idx(const char *s, int c)
{
	unsigned char *un_s;
	unsigned char un_c;
	size_t idx;

	un_s = (unsigned char *)s;
	un_c = (unsigned char)c;
	idx = 0;
	while (un_s[idx] != '\0')
	{
		if (un_s[idx] == un_c)
			return (idx);
		idx++;
	}
	if (un_s[idx] == un_c)
		return (idx);
	return (-1);
}

char *gnl_strjoin_free(char *s1, char const *s2)
{
	size_t s1_len;
	size_t s2_len;
	char *return_ptr;

	if (s1 == 0)
		s1_len = 0;
	else
		s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	return_ptr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	//int a;
	//a = (int)return_ptr;
	//printf("50, %x\n", a);
	if (!return_ptr)
		return (0);
	if (s1 != 0)
	{
		ft_strlcpy(return_ptr, s1, s1_len + 1);
		free(s1);
	}
	ft_strlcat(return_ptr, s2, s1_len + s2_len + 1);
	return (return_ptr);
}

char *gnl_str_n_dup(const char *s1, int n)
{
	size_t len;
	size_t i;
	char *copy_s1;
	char *dup_ptr;

	copy_s1 = (char *)s1;
	len = ft_strlen(copy_s1);
	// FIXME
	dup_ptr = (char *)malloc(sizeof(char) * (len + 1));
	//int a;
	//a = (int)dup_ptr;
	//printf("64, %x\n", a);
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

char *read_all_concatenate_str(int fd, int *flag_newline)
{
	int read_bytes;
	char	*str_total;
	char buff[BUFFER_SIZE + 1];

	str_total = 0;
	read_bytes = 1;
	while (read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
			return (NULL);
		buff[read_bytes] = '\0';
		str_total = gnl_strjoin_free(str_total, buff);
	}
	*flag_newline = 1;
	return (str_total);
}

char *get_next_line(int fd)
{
	static char *str;
	static int flag[3];
	char *return_line;

	str = 0;
	if (flag[0] == 0)
		str = read_all_concatenate_str(fd, &(flag[0]));
	if (str == NULL || fd < 0 || fd == 1 || fd == 2)
		return (NULL);
	if (*str == '\0')
	{
		//int a;
		//a = (int)str;
		//printf("122, %x\n", a);
		if (str != 0)
			free(str);
		return (NULL);
	}
	flag[1] = gnl_strchr_idx(str, '\n');
	if (flag[1] >= 0)
	{
		return_line = gnl_str_n_dup(str, flag[1] + 1);
		ft_memmove(str, str + flag[1] + 1, ft_strlen(str) - flag[1]);
	}
	else
	{
		if (gnl_strchr_idx(str, '\0') >= 0 && flag[2] == 0)
		{
			flag[2] = 1;
			return (str);
		}
		else
		{
			free(str);
			return (NULL);
		}
	}
	free(str);
	return (return_line);
}

// #include <fcntl.h>
// #include <stdio.h>
// int	main(void)
//{
//	int		fd;
//	char	*res[5];
//	int		idx;

//	fd = open("example.txt", O_RDONLY);
//	idx = 0;
//	while (idx < 3)
//	{
//		res[idx] = get_next_line(fd);
//		printf("%s", res[idx]);
//		idx++;
//	}
//	//while (1);
//	// 터미널 하나 더 켜서 ps -> enter -> leaks a.out
//	return (0);
//}
