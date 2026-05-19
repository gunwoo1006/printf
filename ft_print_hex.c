/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:35:43 by gkim              #+#    #+#             */
/*   Updated: 2026/01/28 19:58:17 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
