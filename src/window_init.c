/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggochita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:25:36 by ggochita          #+#    #+#             */
/*   Updated: 2024/05/10 20:39:11 by ggochita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	window_init(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		exit_w_error("[mlx_init() failed]\n", data, 1);
	data->win = mlx_new_window(data->mlx, data->win_width,
			data->win_height, NAME);
	if (data->win == NULL)
	{
		free(data->win);
		return (ERROR);
	}
	return (OK);
}

void	images_init(t_data *data)
{
	data->img.ground = mlx_xpm_file_to_image(data->mlx, GROUND,
			&data->img.width, &data->img.height);
	if (!data->img.ground)
		exit_w_error("[problem with img]\n", data, 1);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, EXIT,
			&data->img.width, &data->img.height);
	if (!data->img.exit)
		exit_w_error("[problem with img]\n", data, 1);
	data->img.player = mlx_xpm_file_to_image(data->mlx, PLAYER,
			&data->img.width, &data->img.height);
	if (!data->img.player)
		exit_w_error("[problem with img]\n", data, 1);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, WALL,
			&data->img.width, &data->img.height);
	if (!data->img.wall)
		exit_w_error("[problem with img]\n", data, 1);
	data->img.coin = mlx_xpm_file_to_image(data->mlx, COIN,
			&data->img.width, &data->img.height);
	if (!data->img.coin)
		exit_w_error("[problem with img]\n", data, 1);
}

void	loop_images(t_data *data)
{
	mlx_loop_hook(data->mlx, &render, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask,
		&handle_btnrelease, data);
	mlx_loop(data->mlx);
}

void	destroy_images(t_data *data)
{
	if (data->img.ground)
	{
		mlx_destroy_image(data->mlx, data->img.ground);
		data->img.ground = NULL;
	}
	if (data->img.player)
	{
		mlx_destroy_image(data->mlx, data->img.player);
		data->img.player = NULL;
	}
	if (data->img.exit)
	{
		mlx_destroy_image(data->mlx, data->img.exit);
		data->img.exit = NULL;
	}
	if (data->img.wall)
	{
		mlx_destroy_image(data->mlx, data->img.wall);
		data->img.wall = NULL;
	}
	if (data->img.coin)
	{
		mlx_destroy_image(data->mlx, data->img.coin);
		data->img.coin = NULL;
	}
}
