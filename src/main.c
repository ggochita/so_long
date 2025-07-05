/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggochita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:24:12 by ggochita          #+#    #+#             */
/*   Updated: 2024/05/08 15:24:15 by ggochita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		if (check_ber(av[1]) == FAIL)
		{
			error_msg("[Map? '.ber']\n");
			return (0);
		}
		create_map(av[1], &data);
		map_init(&data);
		check_map(&data);
		player_init(&data);
		is_enclosed(&data, data.p_x, data.p_y);
		is_map_playable(&data);
		if (!window_init(&data))
			exit_w_error("[Failed to init window]\n", &data, 1);
		images_init(&data);
		render(&data);
		loop_images(&data);
		destroy_images(&data);
		clean_game(&data);
	}
	error_msg("[game needs 1 map]\n");
	return (0);
}
