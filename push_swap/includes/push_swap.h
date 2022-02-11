/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:38:35 by sisyreet          #+#    #+#             */
/*   Updated: 2022/02/11 11:12:05 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>		/* del */
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int	*stack_a;
	int	len_a;
	int	*stack_b;
	int	len_b;
}	t_data;

char	**ft_split(char const *str, char c);
int		*bubble_sort(int *array, int length);
char	*ft_itoa(long long n);
void	*ft_memset(int *arr, int c, size_t len);
void	any_error_msg(char *msg);
void	check_args(int argc, char **argv, t_data *data);
int		ft_atoi(const char *nptr);
void	ft_free(char **arr, int n);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	mem_error_msg(void);
void	sorting(t_data *data);
void	swap_a(t_data *data);
void	swap_b(t_data *data);
void	swap_ss(t_data *data);
void	rotate_a(t_data *data);
void	rotate_b(t_data *data);
void	rotate_rotate(t_data *data);
void	push_a(t_data *data);
void	push_b(t_data *data);
void	print_stacks(t_data *data);
void	sort_three_a(t_data *data);
void	sort_three_b(t_data *data);
void	sort_five(t_data *data, int median);
void	sort_big(t_data *data, int median);
int		is_sorted(int *array, int length);
void	reverse_rotate_a(t_data *data);
void	reverse_rotate_b(t_data *data);

#endif

/* рр печатает ра рб */
