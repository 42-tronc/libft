/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:58:35 by croy              #+#    #+#             */
/*   Updated: 2023/01/10 10:13:11 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

/**
 * @brief locates a substring needle in a string haystack
 *
 * @param haystack complete string to look into
 * @param needle string to look for in haystack
 * @param len max len to look for in haystack
 * @return char* pointer of haysize starting from the needle (included)
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((!haystack || !needle) && len == 0)
		return (NULL);
	if (!needle[i])
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && needle[j] == haystack[i] && i < len)
		{
			if (!needle[j + 1])
				return (&((char *)haystack)[i - j]);
			i++;
			j++;
		}
		i = i - j + 1;
	}
	return (NULL);
}
