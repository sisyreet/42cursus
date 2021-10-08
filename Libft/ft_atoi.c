/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:07:04 by sisyreet          #+#    #+#             */
/*   Updated: 2021/10/08 18:29:49 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *nptr)
{
	int	i;
	int	k;
	int	minus;

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
	if (!(nptr[i] > 47 && nptr[i] < 58))
		return (0);
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		k = k + (nptr[i] - '0');
		k = k * 10;
		i++;
	}
	k = k / 10;
	return (k * minus);
}
