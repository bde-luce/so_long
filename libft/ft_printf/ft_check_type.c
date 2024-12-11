/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luce <bde-luce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:03:09 by bde-luce          #+#    #+#             */
/*   Updated: 2024/05/31 17:41:51 by bde-luce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_type(va_list x, char conv, int j)
{
	if (conv == 'c')
		j += ft_putchar(va_arg(x, int));
	else if (conv == 's')
		j += ft_putstr(va_arg(x, char *));
	else if (conv == 'p')
		j += ft_putptr(va_arg(x, unsigned long));
	else if (conv == 'd' || conv == 'i')
		j += ft_putnbr(va_arg(x, int));
	else if (conv == 'u')
		j += ft_putunbr(va_arg(x, unsigned int));
	else if (conv == 'x')
		j += ft_putnbrhex('x', va_arg(x, unsigned int));
	else if (conv == 'X')
		j += ft_putnbrhex('X', va_arg(x, unsigned int));
	else if (conv == '%')
		j += ft_putchar('%');
	return (j);
}
