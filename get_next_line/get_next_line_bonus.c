/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:01:42 by ratavare          #+#    #+#             */
/*   Updated: 2022/12/07 17:36:33 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*stash[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		while (stash[fd])
		{
			free (stash[fd]);
			stash[fd] = NULL;
		}
		return (NULL);
	}
	if (stash[fd] == NULL)
	{
		stash[fd] = malloc(1);
		stash[fd][0] = 0;
	}
	stash[fd] = buff_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_linetrans(stash[fd]);
	stash[fd] = ft_whatsleft(stash[fd]);
	return (line);
}

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;
// 	fd1 = open("a.txt", O_RDONLY);

// 	i = 1;
// 	while (i < 5)
// 	{
// 		line = get_next_line(fd1);
// 		printf("line [%02d]: %s", i, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	return (0);
// }
