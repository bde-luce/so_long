/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luce <bde-luce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:22:58 by bde-luce          #+#    #+#             */
/*   Updated: 2024/05/31 17:12:48 by bde-luce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	unsigned int	i;

	if (n < 0)
		ft_putunbr(UINT_MAX + (n + 1));
	i = n;
	if (n > 9)
	{
		ft_putunbr(n / 10);
		ft_putunbr(n % 10);
	}
	else
	{
		n += 48;
		write(1, &n, 1);
	}
	return (ft_num_len_unbr(i, 10));
}
