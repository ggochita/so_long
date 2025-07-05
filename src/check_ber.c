/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggochita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:22:34 by ggochita          #+#    #+#             */
/*   Updated: 2024/05/08 15:22:40 by ggochita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	check_ber(char *path)
{
	size_t	len;
	int		fd;

	len = ft_strlen(path);
	fd = open(path, O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		return (FAIL);
	}
	else
	{
		fd = open(path, O_RDONLY);
		if (fd < 0)
			return (FAIL);
		close(fd);
		if ((path[len - 1] != 'r' || path[len - 2] != 'e')
			|| (path[len - 3] != 'b' || path[len - 4] != '.'))
			return (FAIL);
		else
			return (OK);
	}
}
