/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:32:09 by croy              #+#    #+#             */
/*   Updated: 2023/04/02 20:07:02 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

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
	while (stash && stash[i])
		dst[j++] = stash[i++];
	i = 0;
	while (buffer && buffer[i])
		dst[j++] = buffer[i++];
	dst[j] = '\0';
	return (dst);
}
