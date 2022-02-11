/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:53:49 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/11 11:12:45 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sort_stack_b(t_data *data)
{
	int	count;

	count = 0;
	while (!is_sorted(data->stack_b, data->len_b))
	{
		if (data->stack_b[0] > data->stack_b[1])
			swap_b(data);
		else
			rotate_b(data);
		count++;
		printf("%d \n", count);
	}
}

void	sort_big(t_data *data, int median)
{
	int	i;

	i = data->len_a;
	while (i)
	{
		if (data->stack_a[0] < median)
			push_b(data);
		else
			rotate_a(data);
		i--;
	}
}
