/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:32:00 by ratavare          #+#    #+#             */
/*   Updated: 2023/01/05 16:02:01 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *line, char *buffer)
{
	char	*newln;
	int		i;
	int		y;
	int		llen;
	int		blen;

	if (!buffer)
		return (NULL);
	llen = ft_strlen(line);
	blen = ft_strlen(buffer);
	newln = malloc(sizeof newln * (llen + blen) + 1);
	if (!newln)
		return (NULL);
	i = -1;
	y = -1;
	while (++i < llen)
		newln[i] = line[i];
	while (++y < blen)
		newln[i + y] = buffer[y];
	newln[i + y] = '\0';
	free (line);
	return (newln);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_freebuffer(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		buffer[i] = 0;
		i++;
	}
	return (NULL);
}