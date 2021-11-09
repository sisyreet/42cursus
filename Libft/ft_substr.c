/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:37:16 by sisyreet          #+#    #+#             */
/*   Updated: 2021/11/08 15:02:32 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char));
		str[0] = 0;
		return (str);
	}
	if ((unsigned int)ft_strlen(s) - start < len)
		len = (unsigned int)ft_strlen(s) - start;
	while (i < start)
		i++;
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	while (len > j)
		str[j++] = s[i++];
	str[j] = 0;
	return (str);
}
