/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:01:24 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/11 11:14:47 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	print_stacks(t_data *data)
{
	int	len;
	int	i;

	len = 0;
	if (data->len_a > data->len_b)
		len = data->len_a;
	else
		len = data->len_b;
	i = 0;
	while (i < len)
	{
		printf("%d	-	%d\n", data->stack_a[i], data->stack_b[i]);
		i++;
	}
	printf("\n================\n");
}

int	define_median(int *arr, int len)
{
	int	*temp;
	int	i;
	int	median;

	temp = (int *)malloc(sizeof(int) * len + 1);
	if (!temp)
		mem_error_msg();
	i = 0;
	while (i < len)
	{
		temp[i] = arr[i];
		i++;
	}
	temp = bubble_sort(temp, len);
	median = temp[len / 2];
	free(temp);
	return (median);
}

void	sorting(t_data *data)
{
	int	median;

	median = define_median(data->stack_a, data->len_a);
	printf("mediana - %d\n", median);
	if (is_sorted(data->stack_a, data->len_a) == 1)
		any_error_msg("Error\n");
	if (data->len_a == 3)
		sort_three_a(data);
	if (data->len_a > 3 && data->len_a < 6)
		sort_five(data, median);
	if (data->len_a > 5)
		sort_big(data, median);
}
