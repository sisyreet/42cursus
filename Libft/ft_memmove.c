/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:51:52 by sisyreet          #+#    #+#             */
/*   Updated: 2021/12/01 16:22:54 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ne_vlezlo(char *dst, char *src, int len)
{
	int	i;

	i = 0;
	while (i < (int)len)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*dst_1;
	char	*src_1;

	if (dst == 0 && src == 0)
		return (0);
	dst_1 = (char *)dst;
	src_1 = (char *)src;
	if (src < dst)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			dst_1[i] = src_1[i];
			i--;
		}
	}
	else
		ne_vlezlo(dst_1, src_1, len);
	return ((void *)dst_1);
}
