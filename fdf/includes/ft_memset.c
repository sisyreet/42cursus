/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:18:45 by sisyreet          #+#    #+#             */
/*   Updated: 2022/01/27 14:41:38 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*temp;
	size_t	i;

	temp = (char *)b;
	i = 0;
	while (i < len)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	return ((void *)temp);
}
