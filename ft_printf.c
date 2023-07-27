/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucakmak <mucakmak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:33:03 by mucakmak          #+#    #+#             */
/*   Updated: 2023/07/24 13:30:33 by mucakmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	arg_check(char c, va_list lst)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(lst, int));
	else if (c == 's')
		len += ft_putstr(va_arg(lst, char *));
	else if (c == 'd')
		len += ft_putnbr(va_arg(lst, int));
	else if (c == 'p')
		len += ft_pointer(va_arg(lst, void *));
	else if (c == 'i')
		len += ft_putnbr(va_arg(lst, int));
	else if (c == 'u')
		len += ft_putunbr(va_arg(lst, unsigned int));
	else if (c == 'x')
		len += ft_putbase(va_arg(lst, unsigned int), "0123456789abcdef", 16);
	else if (c == 'X')
		len += ft_putbase(va_arg(lst, unsigned int), "0123456789ABCDEF", 16);
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	lst;

	i = 0;
	len = 0;
	va_start(lst, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += arg_check(str[i + 1], lst);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(lst);
	return (len);
}
