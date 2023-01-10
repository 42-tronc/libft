/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:59:01 by croy              #+#    #+#             */
/*   Updated: 2023/01/10 10:13:11 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

size_t	print_nbr(int nbr, char *base)
{
	unsigned int	u_nbr;
	size_t			len;

	len = 0;
	if (nbr < 0)
	{
		u_nbr = nbr * -1;
		len += print_char('-');
	}
	else
		u_nbr = nbr;
	if (ft_strlen(base) <= u_nbr)
	{
		len += print_nbr(u_nbr / ft_strlen(base), base);
		u_nbr = u_nbr % ft_strlen(base);
	}
	print_char(base[u_nbr]);
	len++;
	return (len);
}
