/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:02:54 by croy              #+#    #+#             */
/*   Updated: 2022/11/19 12:12:41 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief allocates memory area and zeroes it
 *
 * @param count number of objects of byte 'size'
 * @param size byte size of each object
 * @return void* pointer to the allocated memory
 */
void	*ft_calloc(size_t count, size_t size)
{
	char	*dst;

	if (size > 0 && count > SIZE_MAX / size)
		return (NULL);
	dst = malloc(count * size);
	if (!dst)
		return (NULL);
	ft_bzero(dst, count * size);
	return (dst);
}
