/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:51:52 by sisyreet          #+#    #+#             */
/*   Updated: 2021/10/06 18:14:32 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	s;
	size_t	d;
	char *dst_1;
	char *src_1;

	dst_1 = (char *)dst;
	src_1 = (char *)src;
	s = 0;
	d = 0;
	while (s < n)
	{
		dst_1[d] = src_1[s];
		d++;
		s++;
	}
	return ((void *)dst_1);
}
 