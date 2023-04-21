/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungmiho <jungmiho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:54:39 by jungmiho          #+#    #+#             */
/*   Updated: 2023/04/21 22:25:31 by jungmiho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_all_concatenate_str(int fd, int *flag_newline)
{
	int		read_bytes;
	char	*str;
	char	buff[BUFF_SIZE + 1];

	read_bytes = read(fd, buff, BUFF_SIZE);
	buff[read_bytes] = '\0';
	str = ft_str_n_dup(buff, read_bytes); //1234\n 
	while (read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFF_SIZE); // abc\nx // yz\n98 // 7 (3 times)
		buff[read_bytes] = '\0';
		str = gnl_strjoin_free(str, buff); //
	}
	*flag_newline = 1;
	return (str);
}

char	*get_next_line(int fd)
{
	// 다시 gnl 함수를 부르기 전에 400이 리턴되어야할것 같다.
	static char	*str;
	static int	flag[3];
	char		*return_str; // return_line으로 바꿔라

	if (fd < 0 || fd == 1 || fd == 2)
		return (0);
	if (flag[0] == 0)
		str = read_all_concatenate_str(fd, &(flag[0]));
	flag[1] = ft_strchr_idx(str, '\n');
	if (flag[1] >= 0) // met nl
	{
		return_str = ft_str_n_dup(str, flag[1] + 1); // 출력을 위한 개행 직전의 문자열 // 500
		ft_memmove(str, str + flag[1] + 1, ft_strlen(str) - flag[1]);
	}
	else // didnt meet nl
	{
		if (ft_strchr_idx(str, '\0') >= 0 && flag[2] == 0)
		{
			flag[2] = 1;
			return (str);
		}
		else
			return (NULL);
	}
	return (return_str);
}

int	main(void)
{
	int		fd;
	char	*res[5];
	int		idx;

	fd = open("example.txt", O_RDONLY);
	idx = 0;
	while (idx < 10)
	{
		res[idx] = get_next_line(fd);
		printf("%s", res[idx]);
		idx++;
	}
	while (1); // 터미널 하나 더 켜서 ps -> enter -> leaks a.out
	return (0);
}
