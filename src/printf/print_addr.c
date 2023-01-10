/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_addr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:58:02 by croy              #+#    #+#             */
/*   Updated: 2023/01/10 10:13:11 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

size_t	print_addr(long unsigned addr, char *base, int start)
{
	int	len;

	if (!addr)
		return (print_str("0x0"));
	len = 0;
	if (start)
		len = print_str("0x");
	if (addr >= 16)
		len += print_addr((addr / 16), base, 0);
	len += print_char(base[addr % 16]);
	return (len);
}
