/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggochita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:25:09 by ggochita          #+#    #+#             */
/*   Updated: 2024/05/08 15:25:12 by ggochita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	player_init(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->map.map[y])
	{
		while (data->map.map[y][x])
		{
			if (data->map.map[y][x] == 'P')
			{
				data->p_y = y;
				data->p_x = x;
			}
			x++;
		}
		x = 0;
		y++;
	}
}
