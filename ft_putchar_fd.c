/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:53:25 by croy              #+#    #+#             */
/*   Updated: 2022/11/12 09:53:25 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief writes char 'c' to file descriptor 'fd'
 *
 * @param c char to write
 * @param fd file descriptor in which to write
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
