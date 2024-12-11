/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luce <bde-luce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:49:41 by bde-luce          #+#    #+#             */
/*   Updated: 2024/05/31 17:12:20 by bde-luce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrhex(char c, unsigned int n)
{
	unsigned int	i;

	if (n < 0)
		ft_putnbrhex(c, UINT_MAX + (n + 1));
	i = n;
	if (n > 15)
	{
		ft_putnbrhex(c, n / 16);
		ft_putnbrhex(c, n % 16);
	}
	else
	{
		if (n < 10)
			n += 48;
		else if (c == 'x')
			n += 87;
		else if (c == 'X')
			n += 55;
		write(1, &n, 1);
	}
	return (ft_num_len_unbr(i, 16));
}
