/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:30:58 by sisyreet          #+#    #+#             */
/*   Updated: 2021/10/07 19:43:12 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *str);

int	prefcmp(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*sum;
	char	*str;
	char	*pset;
	int		s;
	int		g;

	str = (char *)s1;
	pset = (char *)set;
	s = 0;
	g = 0;
	sum = (char *)malloc(ft_strlen(s1));
	while (prefcmp(str[s], pset) == 1)
		s++;
	while (prefcmp(str[s], pset) == 0)
	{
		sum[g] = str[s];
		s++;
		g++;
	}
	sum[g] = '\0';
	return (sum);
}
