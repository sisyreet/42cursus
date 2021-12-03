/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:26:01 by sisyreet          #+#    #+#             */
/*   Updated: 2021/12/02 15:26:32 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*dst_1;
	char	*src_1;

	if (!dst && !src)
		return (0);
	dst_1 = (char *)dst;
	src_1 = (char *)src;
	if (src < dst)
	{
		i = (int)len;
		while (i--)
			*(dst_1 + i) = *(src_1 + i);
	}
	else
	{	
		i = 0;
		while (i < (int)len)
		{
			dst_1[i] = src_1[i];
			i++;
		}
	}
	return ((void *)dst_1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*sum;

	if (!s1 && !s2)
		return (0);
	sum = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!sum)
		return (0);
	ft_memmove(sum, s1, ft_strlen(s1));
	ft_memmove(sum + ft_strlen(s1), s2, ft_strlen(s2));
	sum[ft_strlen(s1) + ft_strlen(s2)] = 0;
	free(s1);
	return (sum);
}
