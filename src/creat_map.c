/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggochita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:24:52 by ggochita          #+#    #+#             */
/*   Updated: 2024/05/08 15:25:03 by ggochita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.line_count)
	{
		free(data->map.map[i]);
		i++;
	}
	free(data->map.map);
	free(data);
}

int	count_lines(char *path)
{
	int		fd;
	int		line_count;
	char	*line;

	line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		error_msg("  [file opening failed]\n");
		return (1);
	}
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			line_count++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (line_count);
}

void	fill_map(int row, t_data *data)
{
	char	*line;

	line = get_next_line(data->map.fd);
	if (line == NULL || line[0] == '\0')
		exit_w_error("[Map is empty]\n", data, 1);
	while (line != NULL)
	{
		data->map.map[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->map.map[row])
			exit_game(data, 1);
		ft_strcpy(data->map.map[row], line);
		row++;
		free(line);
		line = get_next_line(data->map.fd);
	}
	free(line);
	data->map.map[row] = NULL;
}

void	create_map(char *path, t_data *data)
{
	int		row;

	row = 0;
	data->mlx = NULL;
	data->win = NULL;
	data->map.line_count = count_lines(path);
	data->map.path = path;
	data->map.map = ft_calloc(data->map.line_count + 1, sizeof(char *));
	if (!(data->map.map))
		exit_game(data, 1);
	data->map.fd = open(path, O_RDONLY);
	if (data->map.fd < 0)
		exit_w_error("  [file opening failed during map creating]\n", data, 1);
	else
	{
		fill_map(row, data);
		close(data->map.fd);
	}
}
