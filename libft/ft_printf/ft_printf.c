/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luce <bde-luce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:37:48 by bde-luce          #+#    #+#             */
/*   Updated: 2024/05/31 17:24:43 by bde-luce         ###   ########.fr       */
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

/*int main(void)
{
	//int a = -1;
	//int b = 43;
	//void *s = &a;
	//void *t = &b;
	//void *r = NULL;
	//void *p = NULL;
	//a = UINT_MAX + (a + 1);
	int i;
	int j;
	
	i = printf("%s\n", "hello");
	j = ft_printf("%s\n", "hello");
	//printf("%i\n%s\n%p\n", printf(NULL), (char*)0, (void*)0);
	//ft_printf("%i\n%s\n%p\n", ft_printf(NULL), (char*)0, (void*)0);
	printf("%i\n%i\n", i, j);
	//printf("%x\n", a);
	//printf("%x\n", UINT_MAX);
	//printf("%zi\n", write(1, NULL, 1));
	//printf("%i\n", ft_putchar(NULL));
}*/