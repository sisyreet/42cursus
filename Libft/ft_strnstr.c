/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 13:00:38 by sisyreet          #+#    #+#             */
/*   Updated: 2021/11/08 16:27:46 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	if (needle[0] == 0 || haystack == needle)
		return ((char *) haystack);
	if (!len)
		return (0);
	h = 0;
	while (haystack[h] != '\0' && h < len)
	{
		n = 0;
		while (haystack[h + n] && needle[n]
			&& (h + n) < len && haystack[h + n] == needle[n])
			n++;
		if (!needle[n])
			return ((char *)(haystack + h));
		h++;
	}
	return (NULL);
}
