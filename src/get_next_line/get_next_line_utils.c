/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:32:09 by croy              #+#    #+#             */
/*   Updated: 2023/01/10 10:13:11 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

char	*gnl_str_join(char *stash, char *buffer)
{
	char	*dst;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	dst = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buffer) + 1));
	if (!dst)
		return (NULL);
	while (stash[i])
		dst[j++] = stash[i++];
	i = 0;
	while (buffer[i])
		dst[j++] = buffer[i++];
	dst[j] = '\0';
	return (dst);
}
