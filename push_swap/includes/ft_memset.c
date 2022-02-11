/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:18:45 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/08 13:27:43 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memset(int *arr, int c, size_t len)
{
	size_t	i;
	int		*temp;

	temp = (int *)arr;
	i = 0;
	while (i < len)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	return (temp);
}
