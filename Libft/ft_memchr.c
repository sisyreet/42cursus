/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:32:46 by sisyreet          #+#    #+#             */
/*   Updated: 2021/10/07 12:44:44 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		q;
	char	*str;

	str = (char *)s;
	q = 0;
	if (str[q] == 0)
		return ((char *) &str[q]);
	while (n > 0)
	{
		if (c == str[q])
		{
			return ((char *) &str[q]);
		}
		q++;
		n--;
	}
	return ((void *) NULL);
}
