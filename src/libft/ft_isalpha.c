/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:32:21 by croy              #+#    #+#             */
/*   Updated: 2023/01/10 10:13:11 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

/**
 * @brief check if in alphabet
 *
 * @param c int to test
 * @return int 1 or 0 if in alphabet or not
 */
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z')
		|| ('a' <= c && c <= 'z'))
		return (1);
	return (0);
}
