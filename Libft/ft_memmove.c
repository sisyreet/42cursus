/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:51:52 by sisyreet          #+#    #+#             */
/*   Updated: 2021/10/06 18:01:18 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	s;
	size_t	d;
	char *dst_1;
	char *src_1;

	dst_1 = (char *)dst;
	src_1 = (char *)src;
	s = 0;
	d = 0;
	while (s < len)
	{
		dst_1[d] = src_1[s];
		d++;
		s++;
	}
	return ((void *)dst_1);
}
 