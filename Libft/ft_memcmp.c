/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:47:54 by sisyreet          #+#    #+#             */
/*   Updated: 2021/10/07 12:55:10 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	c;
	char	*ss1;
	char	*ss2;

	ss1 = (char *)s1;
	ss2 = (char *)s2;
	c = 0;
	while (n > 0)
	{
		if ((ss2[c] != '\0') && (ss1[c] == '\0'))
			return (ss1[c] - ss2[c]);
		if ((ss2[c] == '\0') && (ss1[c] != '\0'))
			return (ss1[c] + ss2[c]);
		if (ss1[c] > ss2[c])
			return (1);
		if (ss1[c] < ss2[c])
			return (-1);
		n--;
		c++;
	}
	return (0);
}
