/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:59:20 by gkim              #+#    #+#             */
/*   Updated: 2026/01/28 20:20:43 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printc(int c)
{
	char	ch ;

	ch = (char)c;
	write(1, &ch, 1);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		i;

	va_start(ap, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_formats(ap, format[i + 1]);
			i++;
		}	
		else
			count += ft_printc(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}

int	ft_formats(va_list	ap, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_printc(va_arg(ap, int));
	else if (format == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (format == 'p')
		count += ft_print_ptr(va_arg(ap, void *));
	else if (format == 'd' || format == 'i')
		count += ft_print_int(va_arg(ap, int));
	else if (format == 'u')
		count += ft_print_unsigned(va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		count += ft_print_hex(va_arg(ap, unsigned int), format);
	else if (format == '%')
		count += ft_printc('%');
	else
		count += 0;
	return (count);
}
