/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:57:53 by croy              #+#    #+#             */
/*   Updated: 2023/01/10 10:13:11 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

/**
 * @brief tranform uppercase to upper (stays upper if already upper)
 *
 * @param c character to convert to uppercase
 * @return int converted character to uppercase
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return ((unsigned char)(c - 32));
	return (c);
}
