/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:18:10 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/18 18:39:26 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "get_next_line/get_next_line.h"
# include <stdio.h>

typedef struct s_elem
{
	int	index;
	int	value;
}	t_elem;

typedef struct s_data
{
	t_elem	*stack_a;
	int		length_a;
	t_elem	*stack_b;
	int		length_b;
	int		max_index;
	int		cmds_num;
	char 	**cmds;
}	t_data;

void	error_message(char *msg);
void	parse(int argc, char **argv, t_data *data);
char	**ft_split(char const *str, char c);
int		ft_atoi(const char *nptr);
void	ft_free(char **arr, int n);
void	set_indexes(t_data *data, t_elem *buf);
char	calculate_prise(t_data *data);
void	long_sorts(t_data *data);
void	push_b(t_data *data);
void	push_a(t_data *data);
void	swap_a(t_data *data);
void	swap_b(t_data *data);
void	rotate_a(t_data *data);
void	rotate_b(t_data *data);
void	reverse_rotate_a(t_data *data);
void	reverse_rotate_b(t_data *data);
void	sort_three_a(t_data *data);
void	sort_five(t_data *data);
t_elem	*buf_malloc(t_data *data);
char	calculate_price(t_data *data);
t_elem	*bubble_sort(t_data *data, t_elem *buf);
int		find_max_index(t_data *data);
void	check_value(char *line);
char	*ft_itoa(int n);
int		is_sorted(t_elem *stack, int i);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	get_commands(t_data *data);

#endif