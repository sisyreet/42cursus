/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:00:38 by sisyreet          #+#    #+#             */
/*   Updated: 2021/10/07 15:39:28 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	n = 0;
	if (needle == 0)
		return ((char *)haystack);
	while (!haystack)
	{
		if (ft_strncmp(&haystack[h], &needle[n], len) > 1)
			return ((char *) &haystack[h]);
		h++;
	}
	return (NULL);
}
