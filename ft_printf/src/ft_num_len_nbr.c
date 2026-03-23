/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_len_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luce <bde-luce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:02:04 by bde-luce          #+#    #+#             */
/*   Updated: 2024/05/31 17:09:28 by bde-luce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len_nbr(int i, int base)
{
	int	count;

	count = 0;
	if (i == -2147483648)
		return (11);
	if (i <= 0)
	{
		i *= -1;
		count++;
	}
	while (i > 0)
	{
		i /= base;
		count++;
	}
	return (count);
}
