/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:57:45 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/21 13:01:02 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	print_stacks(t_data *data)
{
	int	len;
	int	i;

	i = 0;
	if (data->length_a >= data->length_b)
		len = data->length_a;
	else
		len = data->length_b;
	while (i < len)
	{
		printf("%d	%d	|	%d	%d\n", data->stack_a[i].value, data->stack_a[i].index, data->stack_b[i].value, data->stack_b[i].index);
		i++;
	}	
}
