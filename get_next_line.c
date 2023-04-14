/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungmiho <jungmiho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:54:39 by jungmiho          #+#    #+#             */
/*   Updated: 2023/04/14 23:00:16 by jungmiho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//int	get_line_len(int fd)
//{
//	int		total_len;
//	int		read_len;
//	char	buffer[BUFF_SIZE + 1];

//	total_len = 0;
//	while (1)
//	{
//		read_len = read(fd, buffer, BUFF_SIZE);
//		if (*buffer == '\n' ||read_len == 0)
//			break ;
//		else
//			total_len++;
//	}
//	return (total_len);
//}

char	*get_next_line(int fd)
{
	ssize_t	nbytes;
	char	buffer[BUFF_SIZE + 1];
	char	*temp_str;
	char	*new_str;

	if (fd < 0 || fd == 1 || fd == 2)
		return (NULL);
	temp_str = (char *)malloc(sizeof(char) * 1000);
	nbytes = read(fd, buffer, BUFF_SIZE);
	if (nbytes <= 0)
		return (NULL); // TODO
	ft_strlcpy(temp_str, buffer, 2);
	while (1)
	{
		nbytes = read(fd, buffer, BUFF_SIZE);
		if (nbytes == 0)
			break ;
		else
		{
			ft_strlcat(temp_str, buffer, ft_strlen(temp_str) + ft_strlen(buffer) + 1);
			if (*buffer == '\n')
				break ;
		}
	}
	new_str = ft_strdup(temp_str);
	return (new_str);
}

int	main(void)
{
	int		fd;
	char	*res;

	fd = open("example.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("error opening");
		return (1);
	}
	//res = get_next_line(fd);
	//printf("%s", res);
	//res = get_next_line(fd);
	//printf("%s", res);
	//res = get_next_line(fd);
	//printf("%s", res);
	//res = get_next_line(fd);
	//printf("%s", res);
	while (res != 0)
	{
		res = get_next_line(fd);
		printf("%s", res);
	}	
	return (0);
}