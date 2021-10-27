/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:47:54 by sisyreet          #+#    #+#             */
/*   Updated: 2021/10/27 16:34:16 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				c;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	c = 0;
	while (n > 0)
	{
		if ((ss2[c] != '\0') && (ss1[c] == '\0'))
			return (ss1[c] - ss2[c]);
		if ((ss2[c] == '\0') && (ss1[c] != '\0'))
			return (ss1[c] + ss2[c]);
		if (ss1[c] > ss2[c])
			return ((ss2[c] - ss1[c]) * (-1));
		if (ss1[c] < ss2[c])
			return (ss1[c] - ss2[c]);
		n--;
		c++;
	}
	return (0);
}
