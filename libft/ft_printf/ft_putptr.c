/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luce <bde-luce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:08:02 by bde-luce          #+#    #+#             */
/*   Updated: 2024/05/31 17:12:40 by bde-luce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptr_exist(unsigned long ptr, int b)
{
	unsigned long	i;

	i = ptr;
	if (b == 0)
		write(1, "0x", 2);
	if (ptr > 15)
	{
		ptr_exist(ptr / 16, 1);
		ptr_exist(ptr % 16, 1);
	}
	else
	{
		if (ptr < 10)
			ptr += 48;
		else
			ptr += 87;
		write(1, &ptr, 1);
	}
	return (2 + ft_num_len_ptr(i));
}

int	ft_putptr(unsigned long ptr)
{
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
		return (ptr_exist(ptr, 0));
}
