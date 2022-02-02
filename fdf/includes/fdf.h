/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 10:39:25 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/02 10:18:32 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFFER_SIZE 100
# define BG_COLOR	0x000000

# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>

typedef struct s_dot
{
	float	x;
	float	y;
	int		alt;
	int		color;
}	t_dot;

typedef struct s_data
{
	int		height;
	int		width;
	t_dot	**points;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;

	void	*mlx_ptr;
	void	*win_ptr;
	int		scr_x;
	int		scr_y;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

char	**ft_split(char const *str, char c);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nptr);
void	get_map(t_data *data, char *argv);
void	draw(t_data *data, t_dot **points);
void	get_zoom(t_dot *a, t_dot *b, t_data *data);
void	set_alt_and_color(t_dot *zets, char *alt);
void	change_shift(t_dot *a, t_dot *b, t_data *data);
void	isometric(t_dot *start, t_dot *end, int z, int z1);
void	*ft_memset(void *b, int c, size_t len);
void	init_img(t_data *data);
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
int		errormsg(char *msg);
void	ft_free(char **arr, int n);
int		hex_to_dec(char *hex, long long decimal);
void	points_free(t_data *data);

#endif	