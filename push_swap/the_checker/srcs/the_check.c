/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:54:33 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/21 10:52:23 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	first_part_sort_cmds(t_data *data, char *cmd)
{
	if (!ft_strncmp(cmd, "sa\n", 3))
		swap_a(data);
	if (!ft_strncmp(cmd, "sb\n", 3))
		swap_b(data);
	if (!ft_strncmp(cmd, "ss\n", 3))
	{
		swap_a(data);
		swap_b(data);
	}
	if (!ft_strncmp(cmd, "pa\n", 3))
		push_a(data);
	if (!ft_strncmp(cmd, "pb\n", 3))
		push_b(data);
}

void	second_part_sort_cmds(t_data *data, char *cmd)
{
	if (!ft_strncmp(cmd, "ra\n", 3))
		rotate_a(data);
	if (!ft_strncmp(cmd, "rb\n", 3))
		rotate_b(data);
	if (!ft_strncmp(cmd, "rr\n", 3))
	{
		rotate_a(data);
		rotate_b(data);
	}
	if (!ft_strncmp(cmd, "rra\n", 4))
		reverse_rotate_a(data);
	if (!ft_strncmp(cmd, "rrb\n", 4))
		reverse_rotate_b(data);
	if (!ft_strncmp(cmd, "rrr\n", 4))
	{
		reverse_rotate_a(data);
		reverse_rotate_b(data);
	}
}

void	get_and_execute_commands(t_data *data)
{
	int		i;
	int		fd;
	char	*line;

	line = 0;
	fd = 0;
	i = 0;
	while (!fd)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		first_part_sort_cmds(data, line);
		second_part_sort_cmds(data, line);
		free(line);
		i++;
	}
}

void	get_commands(t_data *data)
{
	t_elem	*buf;

	buf = buf_malloc(data);
	set_indexes(data, buf);
	data->count = 0;
	get_and_execute_commands(data);
	if (is_sorted(data->stack_a, data->length_a) && data->length_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
