/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggochita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:23:41 by ggochita          #+#    #+#             */
/*   Updated: 2024/05/08 15:23:44 by ggochita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	parse_chars(t_data *data, int width, int y, int x)
{
	if (data->map.map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall,
			width, y * IMG_SIZE);
	else if (data->map.map[y][x] == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img.ground,
			width, y * IMG_SIZE);
	else if (data->map.map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->img.player,
			width, y * IMG_SIZE);
	else if (data->map.map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img.exit,
			width, y * IMG_SIZE);
	else if (data->map.map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img.coin,
			width, y * IMG_SIZE);
}

int	render(t_data *data)
{
	int		y;
	size_t	x;
	int		width;

	if (data->win == NULL)
		return (FAIL);
	y = 0;
	x = 0;
	width = 0;
	while (data->map.map[y] != NULL)
	{
		while (data->map.map[y][x] && data->map.map[y][x] != '\n')
		{
			parse_chars(data, width, y, x);
			width += IMG_SIZE;
			x++;
		}
		x = 0;
		width = 0;
		y++;
	}
	return (OK);
}
