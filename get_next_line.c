/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungmiho <jungmiho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:54:39 by jungmiho          #+#    #+#             */
/*   Updated: 2023/04/15 22:46:28 by jungmiho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//char	*get_next_line(int fd)
//{
//	ssize_t	nbytes;
//	char	buffer[BUFF_SIZE + 1];
//	char	*temp_str;
//	char	*joined_str;

//	if (fd < 0 || fd == 1 || fd == 2)
//		return (NULL);
//	nbytes = read(fd, buffer, BUFF_SIZE);
//	buffer[nbytes] = '\0';
//	temp_str = ft_strdup(buffer);
//	if (ft_strchr(temp_str, '\n') == NULL) // didnt find \n
//	{
//		nbytes = read(fd, buffer, BUFF_SIZE);
//		joined_str = ft_strjoin(temp_str, buffer);
//		printf("joined:%s\n", joined_str);
//	}
//	else // found \n
//	{
//		//printf("%s\n", ft_strchr(temp_str, '\n'));
//		//joined_str = 
//	}
//	return (joined_str);
//}

char	*get_next_line(int fd)
{
	ssize_t	nbytes;
	char	buffer[BUFF_SIZE + 1];
	char	*temp_str;
	char	*joined_str;
	int		idx_newline;
	static char	*remain_str;

	if (fd < 0 || fd == 1 || fd == 2)
		return (NULL);
	nbytes = read(fd, buffer, BUFF_SIZE);
	buffer[nbytes] = '\0';
	temp_str = ft_strndup(buffer, ft_strlen(buffer)); // 0123456
	idx_newline = ft_strchr_i(temp_str, '\n');
	if (idx_newline == -1) // not found \n in temp_str
	{
		nbytes = read(fd, buffer, BUFF_SIZE);
		//joined_str = ft_strjoin(temp_str, buffer);
		if (BUFF_SIZE == nbytes)
			joined_str = ft_strjoin(temp_str, buffer);
		else
			joined_str = ft_strjoin(remain_str, temp_str);
	}
	else // found \n in temp_str
	{
		joined_str = ft_strndup(temp_str, idx_newline + 1);
		remain_str = ft_strndup(temp_str + ft_strlen(joined_str) , nbytes - ft_strlen(joined_str) );
	}
	return (joined_str);
}

int	main(void)
{
	int		fd;
	char	*res;

	fd = open("example.txt", O_RDONLY);
	res = get_next_line(fd);
	printf("\n\n%s", res);
	res = get_next_line(fd);
	printf("%s", res);
	//res = get_next_line(fd);
	//printf("%s", res);
	//res = get_next_line(fd);
	//printf("%s", res);
	return (0);
}
