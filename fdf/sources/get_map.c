/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:07:26 by sisyreet          #+#    #+#             */
/*   Updated: 2022/01/26 12:28:47 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_map_height(char *argv, t_data *data)
{
	int		i;
	int		j;
	int		fd;
	char	*temp;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		errormsg("File read error!");
	i = 0;
	j = 0;
	while (fd)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		free(temp);
		i++;
	}
	if (i < 2)
		errormsg("Incorrect data!");
	close(fd);
	data->height = i;
}

void	get_map_width(char *argv, t_data *data)
{
	int		i;
	int		fd;
	int		sum;
	char	**line;
	char	*temp;

	fd = open(argv, O_RDONLY);
	sum = 0;
	while (fd)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		line = ft_split(temp, ' ');
		i = 0;
		while (line[i])
			i++;
		sum += i;
		free(temp);
		ft_free(line, i);
	}
	if (sum / data->height != i)
		errormsg("Incorrect data!");
	data->width = i;
	close(fd);
}

int	hex_to_dec(char *hex, long long decimal)
{
	long long	base;
	int			i;

	base = 1;
	i = ft_strlen(hex);
	while (i >= 0)
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
		i--;
	}
	return (decimal);
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
			ft_free(alt_and_color, 2);
		}
		zets[x].y = y;
		zets[x].x = x;
		x++;
	}
	ft_free(temp, x);
}

void	get_map(t_data *data, char *argv)
{
	int		i;
	int		fd;
	int		y;
	char	*line;

	get_map_height(argv, data);
	get_map_width(argv, data);
	data->points = (t_dot **)malloc(sizeof(t_dot *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
	{
		data->points[i] = (t_dot *)malloc(sizeof(t_dot) * (data->width + 1));
		i++;
	}
	fd = open(argv, O_RDONLY);
	i = 0;
	y = i;
	while (i < data->height)
	{
		line = get_next_line(fd);
		fill_points(data->points[i++], line, y++);
		free(line);
	}
	close (fd);
}
