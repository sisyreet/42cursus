/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:00:13 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/10 09:52:49 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	mem_alloc(t_data *data, int i)
{
	data->stack_a = (int *)malloc(sizeof(int) * i + 1);
	if (data->stack_a == NULL)
		mem_error_msg();
	data->stack_b = (int *)malloc(sizeof(int) * i + 1);
	if (data->stack_b == NULL)
		mem_error_msg();
	ft_memset(data->stack_b, 0, i);
}

void	fill_stack_from_string(char *argv, t_data *data)
{
	int		i;
	char	**line;

	line = ft_split(argv, ' ');
	i = 0;
	while (line[i])
		i++;
	if (i < 3)
		any_error_msg("Error\n");
	mem_alloc(data, i);
	i = 0;
	while (line[i])
	{
		data->stack_a[i] = ft_atoi(line[i]);
		i++;
	}
		data->len_a = i;
}

void	fill_stack_from_argvs(char **argv, t_data *data)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	mem_alloc(data, i);
	i = 1;
	while (argv[i])
	{
		data->stack_a[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	data->len_a = i - 1;
}

void	check_duplicates(t_data *data)
{
	int	num;
	int	i;
	int	j;

	i = 0;
	while (i != data->len_a)
	{
		num = data->stack_a[i];
		j = 0;
		while (j != data->len_a)
		{
			if (num == data->stack_a[j] && i != j)
				any_error_msg("Error\n");
			j++;
		}
		i++;
	}
}

void	check_args(int argc, char **argv, t_data *data)
{
	if (argc < 2 || argc == 3)
		any_error_msg("Error\n");
	if (argc == 2)
		fill_stack_from_string(argv[1], data);
	if (argc > 3)
		fill_stack_from_argvs(argv, data);
	check_duplicates(data);
}
