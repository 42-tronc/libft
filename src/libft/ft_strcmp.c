/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:23:04 by croy              #+#    #+#             */
/*   Updated: 2023/04/03 23:24:10 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

/**
 * @brief compare two strings up to '\0'.
 *
 * @param s1 first string to compare.
 * @param s2 second string to compare.
 *
 * @return An integer greater than, equal to, or less than 0, according to
 * whether the string s1 is greater than, equal to, or less than the string s2.
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	while (str1[i] == str2[i] && str1[i] != '\0')
	{
		i++;
	}
	return (str1[i] - str2[i]);
}
