/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:11:50 by croy              #+#    #+#             */
/*   Updated: 2023/01/10 10:13:11 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

/**
 * @brief creates a copy of the string 's1'
 *
 * @param s1 string to copy
 * @return char* copied string into another string
 * @remark can be used as an arg to the function free
 */
char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	s_len;
	char	*dst;

	i = 0;
	s_len = ft_strlen(s1);
	dst = malloc(sizeof(char) * (s_len + 1));
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
