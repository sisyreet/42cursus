/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:09:47 by sisyreet          #+#    #+#             */
/*   Updated: 2021/10/06 19:21:40 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	d;
	size_t	s;
	size_t	counter;

	s = 0;
	counter = 0;
	while (src[s] != '\0')
	{
		s++;
		counter++;
	}
	if (dstsize < counter)
		return (0);
	s = 0;
	d = 0;
	while (src[s] != '\0')
	{
		dst[d] = src[s];
		d++;
		s++;
	}
	dst[d] = '\0';
	return (counter);
}
