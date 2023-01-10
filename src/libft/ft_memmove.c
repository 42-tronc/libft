/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:45:27 by croy              #+#    #+#             */
/*   Updated: 2023/01/10 10:13:11 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

/**
 * @brief copy a string in a non destructive manner
 *
 * @param dst destination string
 * @param src source string
 * @param len bytes to copy from 'src' to 'dst'
 * @return void* value of 'dst'
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (!dst && !src)
		return (dst);
	if (src < dst)
	{
		while (++i < len)
			((char *)dst)[len - i - 1] = ((char *)src)[len - i - 1];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
