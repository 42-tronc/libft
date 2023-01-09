/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:02:44 by croy              #+#    #+#             */
/*   Updated: 2022/12/05 10:49:26 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief gets the length of a string 's'
 *
 * @param s string to get the length of
 * @return size_t length of string
 */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	check_type(const char format, va_list arg)
{
	size_t	len;

	len = 0;
	if (format == 'd' || format == 'i')
		return (print_nbr(va_arg(arg, int), "0123456789"));
	if (format == 'u')
		return (print_unsigned(va_arg(arg, unsigned int)));
	if (format == 'c')
		return (print_char(va_arg(arg, int)));
	if (format == 's')
		return (print_str(va_arg(arg, char *)));
	if (format == 'p')
		return (print_addr((va_arg(arg, long unsigned)),
				"0123456789abcdef", 1));
	if (format == 'x')
		return (print_hex(va_arg(arg, unsigned int), "0123456789abcdef"));
	if (format == 'X')
		return (print_hex(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	if (format == '%')
		return (print_char('%'));
	else
		len += print_char(format);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;
	int		len_temp;
	int		i;

	len = 0;
	i = 0;
	if (write(1, 0, 0))
		return (-1);
	va_start (arg, format);
	while (format[i])
	{
		len_temp = len;
		if (format[i] == '%' && format[i + 1])
			len += check_type(format[++i], arg);
		else if (format[i] != '%')
			len += print_char(format[i]);
		if (len_temp > len)
			return (-1);
		i++;
	}
	va_end(arg);
	return (len);
}
