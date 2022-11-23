/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:01:42 by ratavare          #+#    #+#             */
/*   Updated: 2022/11/23 17:26:19 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buff_stash(int fd, char *stash)
{
	char	*buff;
	int		read_b;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	read_b = 1;
	while (!(ft_strchr(stash, '\n')) && read_b != 0)
	{
		read_b = read(fd, buff, BUFFER_SIZE);
		if (read_b == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[read_b] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free (buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = buff_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_linetrans(stash);
	stash = ft_whatsleft(stash);
	return (line);
}
