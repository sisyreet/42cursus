/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:31:53 by sisyreet          #+#    #+#             */
/*   Updated: 2021/10/07 12:29:42 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	c = 0;
	while (n > 0)
	{
		if ((s2[c] != '\0') && (s1[c] == '\0'))
			return (s1[c] - s2[c]);
		if ((s2[c] == '\0') && (s1[c] != '\0'))
			return (s1[c] + s2[c]);
		if (s1[c] > s2[c])
			return (1);
		if (s1[c] < s2[c])
			return (-1);
		n--;
		c++;
	}
	return (0);
}
