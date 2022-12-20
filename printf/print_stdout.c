/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stdout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:55:25 by croy              #+#    #+#             */
/*   Updated: 2022/11/29 13:53:13 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief writes char 'c' to STDOUT
 *
 * @param c char to write
 * @return int len written to STDOUT
 */
int	print_char(int c)
{
	return (write(1, &c, 1));
}

/**
 * @brief writes a string to STDOUT
 *
 * @param s string to write
 * @return int len written to STDOUT
 */
int	print_str(const char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}
