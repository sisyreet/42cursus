/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:09:47 by sisyreet          #+#    #+#             */
/*   Updated: 2021/11/08 14:52:48 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s;
	size_t	d;
	size_t	d_size;
	size_t	s_size;

	s = 0;
	d_size = ft_strlen(dst);
	s_size = ft_strlen(src);
	d = d_size;
	if (d_size < size - 1 && size > 0)
	{
		while (src[s] && d_size + s < size - 1)
			dst[d++] = src[s++];
		dst[d] = 0;
	}
	if (d_size >= size)
		d_size = size;
	return (d_size + s_size);
}
