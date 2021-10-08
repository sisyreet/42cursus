/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:16:46 by sisyreet          #+#    #+#             */
/*   Updated: 2021/10/08 16:21:55 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *str);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	int				c;

	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	i = 1;
	c = 0;
	while (s[c] != '\0')
	{
		str[c] = (*f)(c, s[c]);
		c++;
	}
	str[c] = 0;
	return (str);
}
