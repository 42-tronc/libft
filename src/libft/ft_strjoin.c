/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:33:11 by croy              #+#    #+#             */
/*   Updated: 2023/01/10 10:13:11 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

/**
 * @brief copies a string into another starting from index
 *
 * @param dst destination string
 * @param src source string to copy
 * @param index index of dst to start the copy from
 * @return int index after the copy (effectively the size of dst)
 */
static int	str_cpy(char *dst, char *src, int index)
{
	size_t	i;

	i = 0;
	while (src && src[i])
	{
		dst[index] = ((char *)src)[i];
		i++;
		index++;
	}
	return (index);
}

/**
 * @brief allocates and return a new string being s1 + s2
 *
 * @param s1 first string
 * @param s2 second string to add to s1
 * @return char* concatenated string of s1+s2 NULL if allocation fails
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	index;
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	dst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	index = str_cpy(dst, (char *)s1, 0);
	index = str_cpy(dst, (char *)s2, index);
	dst[index] = '\0';
	return (dst);
}
