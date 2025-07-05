/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggochita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 12:57:47 by ggochita          #+#    #+#             */
/*   Updated: 2023/04/08 13:20:12 by ggochita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h>
//#include <fcntl.h>

char	*ft_read_file(int fd, char *stash)
{
	int		read_b;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_b = 1;
	while (!ft_strchr(stash, '\n') && read_b != 0)
	{
		read_b = read(fd, buffer, BUFFER_SIZE);
		if (read_b == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_b] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = ft_read_file(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_alloc_line(stash);
	stash = ft_update_stash(stash);
	return (line);
}
