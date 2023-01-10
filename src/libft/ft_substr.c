/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:29:17 by croy              #+#    #+#             */
/*   Updated: 2023/01/10 10:13:11 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

/**
 * @brief allocates a memory area and
 * returns a string starting form index 'start' with a max length 'len'
 *
 * @param s string to copy from
 * @param start index (starting with 0) to copy from
 * @param len character to copy into dst
 * @return char* dst where len character starting from start is copied from src
 */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	int		dst_len;

	dst_len = 0;
	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
		s += start;
	else
		s += ft_strlen(s);
	while (*s++ && len--)
		dst_len++;
	s = s - dst_len - 1;
	dst = ft_calloc(dst_len + 1, sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s, dst_len + 1);
	return (dst);
}
