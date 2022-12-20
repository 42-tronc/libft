/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:59:16 by croy              #+#    #+#             */
/*   Updated: 2022/11/09 15:59:29 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief converts a char to an int
 *
 * @param str string to convert
 * @return int converted
 */
int	ft_atoi(const char *str)
{
	long	result;
	int		sign;
	size_t	i;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (result != ((result * 10 + ((str[i] - 48) * sign)) / 10))
			return ((sign + 1) / 2 / -1);
		result = ((result * 10) + ((str[i] - 48) * sign));
		i++;
	}
	return ((int) result);
}

#include <stdio.h>
int	main(void)
{
	const char str[] = "-000000000000000000000009223372858947475809";

	printf("\nReal:\n\treturn\t= %d\n", atoi(str));
	printf("\nMine:\n\treturn\t= %d", ft_atoi(str));

	return (0);
}
