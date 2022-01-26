/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:07:04 by sisyreet          #+#    #+#             */
/*   Updated: 2022/01/19 16:16:41 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int				i;
	long long int	k;
	int				minus;

	i = 0;
	k = 0;
	minus = 1;
	while ((nptr[i] > 8 && nptr[i] < 14) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minus = 1 * (-1);
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		k = k * 10 + (nptr[i++] - '0');
		if (k < 0)
			return (0);
	}
	return (k * minus);
}
