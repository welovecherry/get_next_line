/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungmiho <jungmiho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:54:39 by jungmiho          #+#    #+#             */
/*   Updated: 2023/04/17 21:22:46 by jungmiho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//char	*test(char *remain_str)
//{
//	char		*temp_str;
	

//	return (joined_str);
//}

//void	test(int read_bytes, int flag, char *remain_str, char *buff)
//{
//	if (read_bytes == 0)
//	{
//		flag = 1;
//		return (remain_str);
//	}
//	if (*remain_str == 0)
//		remain_str = ft_str_n_dup(buff, read_bytes);
//	else
//		remain_str = ft_strjoin(remain_str, buff);
	
//}

char	*get_next_line(int fd)
{
	static char	*remain_str;
	static char	buff[BUFF_SIZE + 1];
	char		*joined_str;
	int			read_bytes;
	int			idx_nl;
	char		*temp_str;
	static int	flag;

	if (fd < 0 || fd == 1 || fd == 2 || flag == 1)
		return (0);
	while (1)
	{
		read_bytes = read(fd, buff, BUFF_SIZE);
		buff[read_bytes] = '\0';
		if (remain_str == 0)
			remain_str = (char *)ft_calloc(read_bytes, sizeof(char));
		idx_nl = ft_strchr_idx(buff, '\n');
		if (idx_nl >= 0) // met newline || met EOF
		{
			temp_str = ft_str_n_dup(buff, idx_nl + 1);
			joined_str = ft_strjoin(remain_str, temp_str);
			//remain_str = ft_str_n_dup(buff + idx_nl + 1, read_bytes - idx_nl);
			if (*remain_str == 0)
				remain_str = ft_str_n_dup(buff, read_bytes);
			else
				remain_str = ft_strjoin(remain_str, buff);
			break ;
		}
		else // didnt find newline
		{
			if (read_bytes == 0)
			{
				flag = 1;
				return (remain_str);
			}
			if (*remain_str == 0)
				remain_str = ft_str_n_dup(buff, read_bytes);
			else
				remain_str = ft_strjoin(remain_str, buff);
			//test(read_bytes, flag, remain_str, buff);
		}
	}
	return (joined_str);
}

int	main(void)
{
	int		fd;
	char	*res;
	int		idx;

	fd = open("example.txt", O_RDONLY);
	idx = 0;
	res = get_next_line(fd);
	idx++;
	while (res != 0)
	{
		//if (idx == 9)
		//	printf("hihi\n");
		res = get_next_line(fd);
		printf("%s", res);
		idx++;
	}
	return (0);
}
