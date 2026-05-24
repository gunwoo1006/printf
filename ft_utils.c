/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:46:00 by gkim              #+#    #+#             */
/*   Updated: 2026/05/24 14:13:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char	*str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_int(int nb)
{
	char	c;
	int		count;

	count = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		count += write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_print_int(nb / 10);
	c = (nb % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}

int	ft_print_unsigned(unsigned int nb)
{
	char	c;
	int		count;

	count = 0;
	if (nb >= 10)
		count += ft_print_unsigned(nb / 10);
	c = (nb % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}

int	ft_print_hex_ptr(uintptr_t nb)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (nb >= 16)
		count += ft_print_hex_ptr(nb / 16);
	count += write(1, &base[nb % 16], 1);
	return (count);
}

int	ft_print_ptr(void *ptr)
{
	uintptr_t	res;

	if (!ptr)
		return (write(1, "(nil)", 5));
	res = (uintptr_t)ptr;
	write(1, "0x", 2);
	return (2 + ft_print_hex_ptr(res));
}

int	ft_print_hex(unsigned int nb, char spec)
{
	char	*base;
	int		count;

	if (spec == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	count = 0;
	if (nb >= 16)
		count += ft_print_hex(nb / 16, spec);
	count += write(1, &base[nb % 16], 1);
	return (count);
}