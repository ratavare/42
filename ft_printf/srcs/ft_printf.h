/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:56:11 by ratavare          #+#    #+#             */
/*   Updated: 2022/11/29 19:05:30 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

int	ft_print_string(const char *format);
int	ft_print_nbr(int n);
int	ft_print_unbr(unsigned int n);
int	ft_print_hex(int n, const char format);
int	ft_print_char(const char format);
int	ft_print_args(const char format, va_list args);
int	ft_printf(const char *format, ...);

#endif