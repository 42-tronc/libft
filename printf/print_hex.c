/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:48:22 by croy              #+#    #+#             */
/*   Updated: 2022/12/05 10:46:51 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_hex(unsigned int nbr, char *base)
{
	size_t	len;

	len = 0;
	if (ft_strlen(base) <= nbr)
	{
		len += print_nbr(nbr / ft_strlen(base), base);
		nbr = nbr % ft_strlen(base);
	}
	print_char(base[nbr]);
	len++;
	return (len);
}
