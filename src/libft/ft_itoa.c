/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:28:48 by croy              #+#    #+#             */
/*   Updated: 2023/01/10 10:13:11 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

/**
 * @brief takes an int and counts its len
 *
 * @param nbr int to check the length of
 * @return int length of 'nbr'
 */
static int	ft_intlen(long int nbr)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
		len++;
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

/**
 * @brief allocates a memory area and convert an int to a string
 *
 * @param n int to convert
 * @return char* converted string
 */
char	*ft_itoa(int n)
{
	unsigned int	nbr;
	size_t			len;
	char			*dst;

	len = ft_intlen(n);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	dst[len--] = '\0';
	if (n == 0)
		dst[len] = '0';
	if (n < 0)
	{
		nbr = n * -1;
		dst[0] = '-';
	}
	else
		nbr = n;
	while (nbr > 0)
	{
		dst[len--] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (dst);
}
