/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:00:38 by sisyreet          #+#    #+#             */
/*   Updated: 2021/10/08 18:39:28 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	compare(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	c = 0;
	while (n > 0)
	{
		if ((s2[c] != '\0') && (s1[c] == '\0'))
			return (-1);
		if ((s2[c] == '\0') && (s1[c] != '\0'))
			return (1);
		if (s1[c] > s2[c])
			return (1);
		if (s1[c] < s2[c])
			return (-1);
		n--;
		c++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	n = 0;
	if (needle == 0)
		return ((char *)haystack);
	while (haystack[h] != '\0')
	{
		if (compare(&haystack[h], &needle[n], len) > 1)
			return ((char *) &haystack[h]);
		h++;
	}
	return (NULL);
}
