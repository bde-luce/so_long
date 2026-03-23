/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luce <bde-luce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:37:48 by bde-luce          #+#    #+#             */
/*   Updated: 2026/03/23 15:54:11 by bde-luce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		i;
	int		j;
	va_list	x;

	i = 0;
	j = 0;
	va_start(x, s);
	if (!s)
		return (write(1, NULL, 1));
	while (s[i])
	{
		if (s[i] != '%')
			j += ft_putchar(s[i]);
		else
		{
			j = ft_check_type(x, s[i + 1], j);
			i++;
		}
		i++;
	}
	va_end(x);
	return (j);
}
