/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:19:21 by croy              #+#    #+#             */
/*   Updated: 2023/10/30 17:20:28 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

/**
 * @brief Count the number of occurences of a character in a string
 *
 * @param str		string to check
 * @param c			character to count
 * @return size_t	number of occurences of c in str
 */
size_t	ft_countchar(char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}
