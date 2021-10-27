/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:36:58 by sisyreet          #+#    #+#             */
/*   Updated: 2021/10/27 16:33:16 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sum;
	int		i;
	int		j;

	if (!s1)
		return (0);
	sum = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!sum)
		return (0);
	i = 0;
	while (s1[i])
	{
		sum[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		sum[i++] = s2[j++];
	sum[i] = 0;
	return (sum);
}
