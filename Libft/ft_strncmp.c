/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:31:53 by sisyreet          #+#    #+#             */
/*   Updated: 2021/11/08 15:00:14 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	while (n > 0)
	{
		if ((ss2[i] == '\0') && (ss1[i] == '\0'))
			return (0);
		if ((ss2[i] != '\0') && (ss1[i] == '\0'))
			return (ss1[i] - ss2[i]);
		if ((ss2[i] == '\0') && (ss1[i] != '\0'))
			return (ss1[i] + ss2[i]);
		if (ss1[i] > ss2[i])
			return ((ss2[i] - ss1[i]) * (-1));
		if (ss1[i] < ss2[i])
			return (ss1[i] - ss2[i]);
		n--;
		i++;
	}
	return (0);
}
