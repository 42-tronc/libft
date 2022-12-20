/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:12:01 by croy              #+#    #+#             */
/*   Updated: 2022/11/07 15:12:02 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief fill a byte string with a byte value
 *
 * @param b string to fill with 'c'
 * @param c value to fill 'b' with
 * @param len number of bytes to fill of value 'c'
 * @return void* string after being filled
 */
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned int) c;
		i++;
	}
	return (b);
}
