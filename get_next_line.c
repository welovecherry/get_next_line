/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungmiho <jungmiho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:54:39 by jungmiho          #+#    #+#             */
/*   Updated: 2023/04/15 20:40:20 by jungmiho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t	nbytes;
	char	buffer[BUFF_SIZE + 1];
	char	*temp_str;

	if (fd < 0 || fd == 1 || fd == 2)
		return (NULL);
	nbytes = read(fd, buffer, BUFF_SIZE);
	buffer[nbytes] = '\0';
	temp_str = ft_strdup(buffer); // hellowo
	printf("%s\n", temp_str); 

	if (ft_strchr(temp_str, '\n') != NULL)
	{
		printf("")
		nbytes = read(fd, buffer, BUFF_SIZE);
		ft_strjoin(temp_str, buffer);
	}
	printf("%s\n", temp_str); 
	return (temp_str);
}

int	main(void)
{
	int		fd;
	char	*res;

	fd = open("example.txt", O_RDONLY);
	res = get_next_line(fd);
	printf("main res:%s", res);
	//res = get_next_line(fd);
	//printf("%s", res);
	//res = get_next_line(fd);
	//printf("%s", res);
	//res = get_next_line(fd);
	//printf("%s", res);
	return (0);
}
