/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:51:52 by sisyreet          #+#    #+#             */
/*   Updated: 2021/10/27 16:34:22 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	i;
	char	*dst_1;
	char	*src_1;

	if (dst == 0 && src == 0)
		return (0);
	dst_1 = (char *)dst;
	src_1 = (char *)src;
	i = 0;
	while (i < n)
	{
		dst_1[i] = src_1[i];
		i++;
	}
	return ((void *)dst_1);
}
