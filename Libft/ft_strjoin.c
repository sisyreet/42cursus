/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:36:58 by sisyreet          #+#    #+#             */
/*   Updated: 2021/10/07 18:31:58 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(const char *str);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sum;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	sum = (char *)malloc(len);
	if (sum == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		sum[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[i] != '\0')
	{
		sum[i++] = s2[j++];
	}
	sum[i] = 0;
	return (sum);
}
