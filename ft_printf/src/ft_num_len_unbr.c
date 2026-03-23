/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_len_unbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luce <bde-luce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:24:02 by bde-luce          #+#    #+#             */
/*   Updated: 2024/05/31 17:09:54 by bde-luce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len_unbr(unsigned int i, int base)
{
	int	count;

	count = 0;
	if (i == 0)
		return (1);
	while (i > 0)
	{
		i /= base;
		count++;
	}
	return (count);
}
