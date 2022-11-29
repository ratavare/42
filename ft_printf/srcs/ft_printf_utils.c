/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:47:03 by ratavare          #+#    #+#             */
/*   Updated: 2022/11/29 19:14:02 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(const char *format)
{
	int	i;

	i = 0;
	while (format[i])
		ft_print_char(format[i++]);
	return (i);
}

int	ft_print_nbr(int n)
{
	static int	ret;

	ret = 0;
	if (n == -2147483648)
	{
		ft_print_char('-');
		write(1, "2147483648", 10);
		return (11);
	}
	if (n < 0)
	{
		ret += ft_print_char('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_print_nbr(n / 10);
		n %= 10;
	}
	if (n < 10)
		ret += ft_print_char(n + 48);
	return (ret);
}

int	ft_print_unbr(unsigned int n)
{
	static int	ret;

	ret = 0;
	if (n >= 10)
	{
		ft_print_unbr(n / 10);
		n %= 10;
	}
	if (n < 10)
		ret += ft_print_char(n + 48);
	return (ret);
}

int	ft_print_hex(int n, const char format)
{
	int		ret;
	char	*str;

	str = ft_itoa(n);
	ret = ft_strlen(str);
	if (n > 15)
	{
		ft_print_hex(n / 16, format);
		ft_print_hex(n % 16, format);
	}
	if (n < 15 && n > 9)
	{
		if (format == 'x')
			ft_print_char(n + 87);
		if (format == 'X')
			ft_print_char(n + 55);
	}
	if (n < 9)
		ft_print_nbr(n);
	return (ret);
}
