/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:59:20 by croy              #+#    #+#             */
/*   Updated: 2022/11/29 13:53:11 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_unsigned(unsigned int nbr)
{
	unsigned int	u_nbr;
	size_t			len;

	len = 0;
	if (nbr < 0)
		u_nbr = 4294967296 + nbr;
	else
		u_nbr = nbr;
	if (u_nbr >= 10)
	{
		len += print_unsigned(u_nbr / 10);
		u_nbr = u_nbr % 10;
	}
	print_char(u_nbr + 48);
	len++;
	return (len);
}
