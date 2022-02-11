/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:34:45 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/11 10:49:44 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	*bubble_sort(int *array, int length)
{
	int	temp;
	int	i;
	int	count;

	count = 1;
	while (count)
	{
		i = 0;
		count = 0;
		while (i < length - 1)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				count++;
			}
			i++;
		}
	}
	return (array);
}
