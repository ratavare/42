/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:01:29 by ratavare          #+#    #+#             */
/*   Updated: 2022/11/09 18:34:35 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	i;
	char	*str;

	j = 0;
	i = start;
	if (!s)
		return (NULL);
	if (start < ft_strlen((char *)s))
		str = malloc((len + 1) * sizeof(char));
	else
		str = malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	while (s[i] && j < len && start < ft_strlen((char *)s))
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
