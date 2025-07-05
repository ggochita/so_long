/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggochita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:27:48 by ggochita          #+#    #+#             */
/*   Updated: 2024/05/08 15:27:54 by ggochita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	handle_resize(t_data *data)
{
	render(data);
	return (0);
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		exit_game(data, 1);
	}
	else
	{
		if (keycode == XK_w || keycode == XK_W)
			move_player(data, 'w');
		else if (keycode == XK_a || keycode == XK_A)
			move_player(data, 'a');
		else if (keycode == XK_s || keycode == XK_S)
			move_player(data, 's');
		else if (keycode == XK_d || keycode == XK_D)
			move_player(data, 'd');
	}
	return (0);
}

int	handle_btnrelease(t_data *data)
{
	exit_game(data, 1);
	return (0);
}
