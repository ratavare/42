/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:38:41 by ratavare          #+#    #+#             */
/*   Updated: 2022/11/01 16:48:49 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	char			*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		if (str[i] == c)
			return ((unsigned char *)s + i);
		i++;
	}
	return (NULL);
}
