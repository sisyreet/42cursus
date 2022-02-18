/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:10:54 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/18 13:23:26 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_elem *stack, int length)
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (stack[i].value > stack[i + 1].value)
			return (0);
		i++;
	}
	return (1);
}

void	check_value(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ' && (line[i + 1] < '0' || line[i + 1] > '9'))
			error_message("Error\n");
		if (line[i] < '0' || line[i] > '9')
		{
			if (line[i] != ' ' && line[i] != ','
				&& line[i] != '-' && line[i] != '+')
				error_message("Error\n");
			if ((line[i] == '-' || line[i] == '+')
				&& (line[i + 1] < '0' || line[i + 1] > '9'))
				error_message("Error\n");
			i++;
		}
		else
			i++;
	}
}
