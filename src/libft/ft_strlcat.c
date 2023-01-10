/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:59:46 by croy              #+#    #+#             */
/*   Updated: 2023/01/10 10:13:11 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

/**
 * @brief string concatenation of dst = dst+src.
 * will NULL terminate unless dstsize=0 or dst > dstsize
 *
 * @param dst destination string
 * @param src string to add to dst
 * @param dstsize appends at most dstsize - strlen(dst) - 1
 * @return size_t total length of dst + src
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;

	src_len = 0;
	dst_len = 0;
	if ((!dst || !src) && dstsize == 0)
		return (0);
	while (dst[dst_len] && dst_len < dstsize)
		dst_len++;
	while (src[src_len] && src_len + dst_len + 1 < dstsize)
	{
		dst[dst_len + src_len] = src[src_len];
		src_len++;
	}
	if (dst_len < dstsize)
		dst[dst_len + src_len] = 0;
	return (dst_len + ft_strlen(src));
}
