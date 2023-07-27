/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucakmak <mucakmak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 08:00:59 by mucakmak          #+#    #+#             */
/*   Updated: 2023/07/19 11:36:37 by mucakmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

// ft_printf.c
int	ft_putchar(char c);
int	arg_check(char c, va_list lst);
int	ft_printf(const char *str, ...);

// puts.c
int	ft_putstr(char *s);
int	ft_pointer(void *p);
int	ft_putnbr(int nbr);
int	ft_putbase(unsigned long nbr, char *dict, unsigned int base);
int	ft_putunbr(unsigned int nbr);

#endif