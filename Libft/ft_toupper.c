/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:08:04 by sisyreet          #+#    #+#             */
/*   Updated: 2021/10/27 16:33:49 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c > 64 && c < 91)
		return (c);
	if (c > 96 && c < 123)
		return (c - 32);
	return (c);
}
