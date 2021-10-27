/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:32:46 by sisyreet          #+#    #+#             */
/*   Updated: 2021/10/27 17:30:42 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			q;
	unsigned char	d;
	unsigned char	*str;

	str = (unsigned char *)s;
	d = (unsigned char)c;
	q = 0;
	while (q < n)
	{
		if (d == str[q])
		{
			return ((void *)&str[q]);
		}
		q++;
	}
	return (NULL);
}
