/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:43:08 by croy              #+#    #+#             */
/*   Updated: 2023/04/24 17:43:09 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

/**
 * @brief creates a copy of the string `str` up to `n`
 *
 * @param str string to copy
 * @param n max len to copy
 * @return char* string copied up to `n`
 */
char	*ft_strndup(const char *str, size_t n)
{
	size_t	i;
	char	*dst;

	i = 0;
	while (str[i] && i < n)
		i++;
	dst = ft_calloc(i + 1, sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (str[i] && i < n)
	{
		dst[i] = str[i];
		i++;
	}
	return (dst);
}
