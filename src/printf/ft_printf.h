/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:33:47 by croy              #+#    #+#             */
/*   Updated: 2022/12/05 10:51:30 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		print_char(int c);
int		print_str(const char *s);
size_t	print_addr(long unsigned addr, char *base, int start);
size_t	print_nbr(int nbr, char *base);
size_t	print_hex(unsigned int nbr, char *base);
size_t	print_unsigned(unsigned int nbr);
size_t	ft_strlen(const char *s);

#endif
