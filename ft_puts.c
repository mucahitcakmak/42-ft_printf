/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucakmak <mucakmak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:40:08 by mucakmak          #+#    #+#             */
/*   Updated: 2023/07/24 14:43:33 by mucakmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_pointer(void *p)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_putbase((unsigned long)p, "0123456789abcdef", 16);
	return (len);
}

int	ft_putnbr(int nbr)
{
	long		number;
	int			len;

	len = 0;
	number = nbr;
	if (number < 0)
	{
		len += ft_putchar('-');
		number = -number;
	}
	if (number > 9)
	{
		len += ft_putnbr(number / 10);
		len += ft_putnbr(number % 10);
	}
	if (number <= 9)
		len += ft_putchar(number + '0');
	return (len);
}

int	ft_putunbr(unsigned int nbr)
{
	int		len;

	len = 0;
	if (nbr < 10)
		len += ft_putchar(nbr + '0');
	else
	{
		len += ft_putunbr(nbr / 10);
		len += ft_putchar(nbr % 10 + '0');
	}
	return (len);
}

int	ft_putbase(unsigned long nbr, char *dict, unsigned int base)
{
	int	len;

	len = 0;
	if (nbr >= base)
		len += ft_putbase(nbr / base, dict, base);
	len += ft_putchar(dict[nbr % base]);
	return (len);
}
