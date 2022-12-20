/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:58:24 by croy              #+#    #+#             */
/*   Updated: 2022/11/09 15:58:24 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief locates a character in string s
 *
 * @param s string to look into
 * @param c character to find (starting for the end)
 * @return char* pointer of string s starting from c (regular order)
 */
char	*ft_strrchr(const char *s, int c)
{
	int	str_len;

	str_len = ft_strlen(s);
	while (str_len >= 0)
	{
		if (s[str_len] == (char)c)
			return (&((char *)s)[str_len]);
		str_len--;
	}
	if (!(char)c)
		return (&((char *)s)[str_len]);
	return (NULL);
}
