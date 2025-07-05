/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_algo_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggochita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:23:09 by ggochita          #+#    #+#             */
/*   Updated: 2024/05/08 15:23:13 by ggochita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	init_reach_res(t_params *params, t_data *data, char target, int *front)
{
	params->data = data;
	params->target = target;
	*front = 0;
	params->visited = create_visited_array(data->map.line_count,
			data->map.line_len);
	params->queue = (t_point *)malloc(data->map.line_count
			* data->map.line_len * sizeof(t_point));
	if (!params->queue || !params->visited)
	{
		free(params->queue);
		if (params->visited)
			free_visited_array(params->visited, data->map.line_count);
		return (0);
	}
	*(params->rear) = 0;
	return (1);
}

void	assign_sim(t_data **dest, t_data *src, int *coin_x, int *coin_y)
{
	*coin_x = -1;
	*coin_y = -1;
	*dest = malloc(sizeof(t_data));
	if (!*dest)
		exit_w_error("[Failed to allocate memory for simulation data]", src, 1);
	**dest = *src;
	(*dest)->map.map = copy_map(src->map.map, src->map.line_count,
			src->map.line_len);
	if (!(*dest)->map.map)
	{
		free(*dest);
		*dest = NULL;
		exit_w_error("[Failed to copy map]", src, 1);
	}
}

char	**copy_map(char **src, int rows, size_t line_len)
{
	char	**dest;
	int		i;

	i = 0;
	dest = malloc(rows * sizeof(char *));
	if (!dest)
		return (NULL);
	while (i < rows)
	{
		dest[i] = malloc((line_len + 2) * sizeof(char));
		if (!dest[i])
		{
			while (--i >= 0)
				free(dest[i]);
			free(dest);
			return (NULL);
		}
		ft_strcpy(dest[i], src[i]);
		i++;
	}
	return (dest);
}

void	is_enclosed(t_data *data, int x, int y)
{
	if ((data->map.map[y][x + 1] == '1' || (size_t)x + 1 >= data->map.line_len)
	&& (data->map.map[y][x - 1] == '1' || x - 1 < 0) &&
		(data->map.map[y + 1][x] == '1' || y + 1 >= data->map.line_count) &&
		(data->map.map[y - 1][x] == '1' || y - 1 < 0))
	{
		error_msg("[Player is surrounded by walls]\n");
		exit_game(data, 1);
	}
}
