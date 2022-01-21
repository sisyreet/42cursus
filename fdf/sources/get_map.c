/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:07:26 by sisyreet          #+#    #+#             */
/*   Updated: 2022/01/21 15:14:20 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_map_height_and_width(char *argv, t_data *data)
{
	int		i;
	int		fd;
	char	**line;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		errormsg("File read error!");
	i = 0;
	while (get_next_line(fd))
		i++;
	close(fd);
	data->height = i;
	fd = open(argv, O_RDONLY);
	line = ft_split(get_next_line(fd), ' ');
	if (line == NULL)
		errormsg("Bad map file!");
	i = 0;
	while (line[i])
		i++;
	data->width = i;
	close(fd);
}

int	hex_to_dec(char *hex, long long decimal)
{
	long long	base;
	int			i;

	base = 1;
	i = ft_strlen(hex);
	while (i-- >= 0)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
		{
			decimal += (hex[i] - 48) * base;
			base *= 16;
		}
		else if (hex[i] >= 'A' && hex[i] <= 'F')
		{
			decimal += (hex[i] - 55) * base;
			base *= 16;
		}
		else if (hex[i] >= 'a' && hex[i] <= 'f')
		{
			decimal += (hex[i] - 87) * base;
			base *= 16;
		}
	}
	return (decimal);
}

void	set_alt_and_color(t_dot *zets, char *alt)
{
	zets->alt = ft_atoi(alt);
	if (zets->alt > -20)
		zets->color = 0xa213bf;
	if (zets->alt > -9)
		zets->color = 0xae63ff;
	if (zets->alt > -7)
		zets->color = 0x636bff;
	if (zets->alt > -5)
		zets->color = 0x63aeff;
	if (zets->alt > -3)
		zets->color = 0x63e2ff;
	if (zets->alt > -1)
		zets->color = 0x66fadc;
	if (zets->alt == 0)
		zets->color = 0xa2f2af;
	if (zets->alt > 1)
		zets->color = 0xbdf2a2;
	if (zets->alt > 3)
		zets->color = 0xf9ff8c;
	if (zets->alt > 5)
		zets->color = 0xffdd8c;
	if (zets->alt > 7)
		zets->color = 0xffb88c;
	if (zets->alt > 9)
		zets->color = 0xfa6666;
}

void	fill_points(t_dot *zets, char *line, int y)
{
	char		**temp;
	char		**alt_and_color;
	int			x;
	long long	decimal;

	decimal = 0;
	temp = ft_split(line, ' ');
	x = 0;
	while (temp[x])
	{
		if (5 > ft_strlen(temp[x]))
			set_alt_and_color(&zets[x], temp[x]);
		else
		{
			alt_and_color = ft_split(temp[x], ',');
			zets[x].alt = ft_atoi(alt_and_color[0]);
			zets[x].color = hex_to_dec(alt_and_color[1], decimal);
		}
		zets[x].y = y;
		zets[x].x = x;
		x++;
	}
}

void	get_map(t_data *data, char *argv)
{
	int	i;
	int	fd;
	int	y;

	get_map_height_and_width(argv, data);
	data->points = (t_dot **)malloc(sizeof(t_dot *) * (data->height) + 1);
	i = 0;
	while (i <= data->height)
		data->points[i++] = (t_dot *)malloc(sizeof(t_dot) * (data->width) + 1);
	fd = open(argv, O_RDONLY);
	i = 0;
	y = i;
	while (i < data->height)
		fill_points(data->points[i++], get_next_line(fd), y++);
	close (fd);
	data->points[i] = NULL;
}
