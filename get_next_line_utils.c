/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungmiho <jungmiho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:36:32 by jungmiho          #+#    #+#             */
/*   Updated: 2023/04/15 22:25:11 by jungmiho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}

int	ft_strchr_i(const char *s, int c)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == (unsigned char)c)
			return (i);
		i++;
	}
	if (ptr[i] == (unsigned char)c)
		return (i);
	return (-1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	if (src_len == 0)
	{
		*dst = '\0';
		return (src_len);
	}
	i = 0;
	while (i < dstsize - 1 && src[i]!= '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dst_len > dstsize)
		return (src_len + dstsize);
	else
	{
		i = 0;
		while ((i + 1 < dstsize - dst_len) && (src[i] != '\0'))
		{
			dst[dst_len + i] = src[i];
			i++;
		}
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
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
		return (0);
	strlcpy(return_ptr, s1, s1_len + 1);
	strlcat(return_ptr, s2, s1_len + s2_len + 1);
	return (return_ptr);
}

char	*ft_strndup(const char *s1, int	n)
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
	while (i < len && i < n)
	{
		dup_ptr[i] = copy_s1[i];
		i++;
	}
	dup_ptr[i] = '\0';
	return (dup_ptr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			idx;
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	if (dst == 0 && src == 0)
		return (dst);
	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	idx = 0;
	while (idx < n)
	{
		ptr_dst[idx] = ptr_src[idx];
		idx++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				idx;
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	if (dst == 0 && src == 0)
		return (dst);
	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (dst < src)
		ft_memcpy(ptr_dst, ptr_src, len);
	else
	{
		idx = len - 1;
		while (idx >= 0)
		{
			ptr_dst[idx] = ptr_src[idx];
			idx--;
		}
	}
	return (dst);
}

/*
int main(void) {
	char			dest1[30] = "abcde";
	char			dest2[30] = "abcde";
	char			dest3[30] = "z";
	char			dest4[30] = "z";
	char			src[10] = "abc";


	ft_strlcpy(dest3, src, 2);
	strlcpy(dest4, src, 2);

	printf("myfunc : %s\n", dest3);
	printf("strlcpy: %s\n", dest4);

	return 0;
}
*/