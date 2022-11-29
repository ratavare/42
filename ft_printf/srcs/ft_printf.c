/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:55:34 by ratavare          #+#    #+#             */
/*   Updated: 2022/11/29 19:12:54 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_print_args(format[i + 1], args);
			i++;
		}
		else
			len += ft_print_char(format[i]);
		i++;
	}
	return (len);
}

int	ft_print_args(const char format, va_list args)
{
	if (format == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (format == 's')
		return (ft_print_string(va_arg(args, char *)));
	//if (format == 'p')
	//	return (ft_print_uhex(va_arg(args, unsigned long)));
	if (format == 'd' || format == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	if (format == 'u')
		return (ft_print_unbr(va_arg(args, unsigned long)));
	if (format == 'x' || format == 'X')
		return (ft_print_hex(va_arg(args, int), format));
	if (format == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_print_char(const char format)
{
	write(1, &format, 1);
	return (1);
}
