/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:27:33 by croy              #+#    #+#             */
/*   Updated: 2023/01/10 10:13:11 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

static size_t	start_offset(char const *str, char const *trim)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (trim[i] && str[j])
	{
		if (trim[i] == str[j])
		{
			i = 0;
			j++;
		}
		else
			i++;
	}
	return (j);
}

static size_t	end_offset(char const *str, char const *trim)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(str) - 1;
	while (trim[i])
	{
		if (trim[i] == str[j])
		{
			i = 0;
			j--;
		}
		else
			i++;
	}
	return (j + 1);
}

/**
 * @brief allocates a memory area and returns a copy of s1 without
 *  set characters from the start and end of the string
 *
 * @param s1 string to trim
 * @param set characters to trim the s1
 * @return char* the trimmed string or NULL if allocation fails
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	dst_len;
	size_t	start_off;
	size_t	end_off;
	char	*dst;

	i = 0;
	if (!s1)
		return (NULL);
	start_off = start_offset(s1, set);
	if (start_off == ft_strlen(s1))
		return (ft_strdup(""));
	end_off = end_offset(s1, set);
	dst_len = end_off - start_off;
	dst = malloc(sizeof(char) * dst_len + 1);
	if (!dst)
		return (NULL);
	while (i < dst_len && ft_strlen(set) < ft_strlen(s1))
	{
		dst[i] = s1[start_off + i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
