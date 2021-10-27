/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:30:58 by sisyreet          #+#    #+#             */
/*   Updated: 2021/10/27 16:33:43 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	int		begin;
	int		end;
	int		i;

	begin = 0;
	i = 0;
	if (!s1)
		return (0);
	while (prefcmp(s1[begin], (char *)set) && s1[begin])
		begin++;
	end = ft_strlen(s1);
	while (end > begin && prefcmp(s1[end - 1], (char *)set))
		end--;
	sum = (char *)malloc(end - begin + 1);
	if (!sum)
		return (0);
	while (begin < end)
		sum[i++] = s1[begin++];
	sum[i] = '\0';
	return (sum);
}
