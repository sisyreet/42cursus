/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:05:03 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/21 10:21:09 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	mem_alloc(t_data *data, int len)
{
	data->stack_a = (t_elem *)malloc(sizeof(t_elem) * len + 1);
	if (!data->stack_a)
		error_message("Memory wasn't allocated!\n");
	data->stack_b = (t_elem *)malloc(sizeof(t_elem) * len + 1);
	if (!data->stack_b)
		error_message("Memory wasn't allocated!\n");
}

void	parse_from_string(char **argv, t_data *data)
{
	int		i;
	char	**line;

	line = ft_split(argv[1], ' ');
	i = 0;
	while (line[i])
		i++;
	mem_alloc(data, i);
	data->length_a = i;
	i = 0;
	while (line[i])
	{
		data->stack_a[i].value = ft_atoi(line[i]);
		check_value(line[i]);
		data->stack_b[i].value = 0;
		data->stack_b[i].index = 0;
		i++;
	}
	data->length_b = 0;
	ft_free(line, data->length_a);
}

void	parse_from_argvs(char **argv, t_data *data)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	data->length_a = i - 1;
	mem_alloc(data, i);
	i = 0;
	while (argv[i + 1])
	{
		data->stack_a[i].value = ft_atoi(argv[i + 1]);
		check_value(argv[i + 1]);
		data->stack_b[i].value = 0;
		data->stack_b[i].index = 0;
		i++;
	}
	data->length_b = 0;
}

void	check_duplicates(t_data *data)
{
	int	num;
	int	i;
	int	j;

	i = 0;
	while (i != data->length_a)
	{
		num = data->stack_a[i].value;
		j = 0;
		while (j != data->length_a)
		{
			if (num == data->stack_a[j].value && i != j)
				error_message("Error\n");
			j++;
		}
		i++;
	}
}

void	parse(int argc, char **argv, t_data *data)
{
	if (data->length_a > 2 && is_sorted(data->stack_a, data->length_a))
		return ;
	if (argc == 2)
	{
		check_value(argv[1]);
		parse_from_string(argv, data);
		check_duplicates(data);
		if (is_sorted(data->stack_a, data->length_a))
			return ;
	}
	if (argc > 2)
	{
		parse_from_argvs(argv, data);
		check_duplicates(data);
		if (is_sorted(data->stack_a, data->length_a))
			return ;
	}
}
