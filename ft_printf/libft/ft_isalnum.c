/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:42:13 by ratavare          #+#    #+#             */
/*   Updated: 2022/10/28 13:28:51 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int value)
{
	if ((value >= 48 && value <= 57) || (value >= 65 && value <= 90))
		return (1);
	if (value >= 97 && value <= 122)
		return (1);
	else
		return (0);
}
