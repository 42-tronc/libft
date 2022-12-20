/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:47:25 by croy              #+#    #+#             */
/*   Updated: 2022/11/07 14:47:27 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief check if alphanumberic
 *
 * @param c int to test
 * @return int 1 or 0 if alphanum or not
 */
int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z')
		|| ('a' <= c && c <= 'z')
		|| ('0' <= c && c <= '9'))
		return (1);
	return (0);
}
