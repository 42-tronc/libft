/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:58:14 by croy              #+#    #+#             */
/*   Updated: 2022/11/09 15:58:14 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief tranform uppercase to lower (stays lower if already lower)
 *
 * @param c character to convert to lowercase
 * @return int converted character to lowercase
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return ((unsigned char)(c + 32));
	return (c);
}
