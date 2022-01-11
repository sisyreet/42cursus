/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:18:34 by sisyreet          #+#    #+#             */
/*   Updated: 2022/01/11 14:50:22 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	*fill_points(char *argv, t_point *coordinates, int x, int y)
{
	int		fd;
	int		i;
	int		j;
	int		c;
	char	**line;

	coordinates = malloc(sizeof(t_point) * (x * y));
	fd = open(argv, O_RDONLY);
	i = 0;
	c = 0;
	while (i < y)
	{
		j = 0;
		line = ft_split(get_next_line(fd), ' ');
		while (line[j])
		{
			coordinates[c].x = j;
			coordinates[c].y = i;
			coordinates[c].z = ft_atoi(line[j]);
			j++;
			c++;
		}
		i++;
	}
	close(fd);
	return (coordinates);
}

t_map	get_map_size(int fd)
{
	char	buffer;
	char	**temp;
	int		count;
	int		i;
	t_map	size;

	temp = ft_split(get_next_line(fd), ' ');
	count = 0;
	i = 0;
	while (temp[i++])
		count++;
	size.x = count;
	count = 0;
	while (get_next_line(fd))
		count++;
	size.y = count + 1;
	return (size);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map_size;
	t_point	*coordinates;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	map_size = get_map_size(fd);
	coordinates = fill_points(argv[1], coordinates, map_size.x, map_size.y);
	draw_something(coordinates, map_size);
	close(fd);
	return (0);
}
