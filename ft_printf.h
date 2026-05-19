/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:17:55 by gkim              #+#    #+#             */
/*   Updated: 2026/01/28 20:21:20 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_printc(int c);
int	ft_print_hex(unsigned int nb, char spec);
int	ft_printf(const char *format, ...);
int	ft_formats(va_list	ap, const char format);
int	ft_print_str(char	*str);
int	ft_print_int(int nb);
int	ft_print_unsigned(unsigned int nb);
int	ft_print_ptr(void *ptr);
int	ft_print_hex_ptr(uintptr_t nb);

#endif