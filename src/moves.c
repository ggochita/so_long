/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggochita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:27:36 by ggochita          #+#    #+#             */
/*   Updated: 2024/05/08 15:27:38 by ggochita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	move_msg(t_data *data)
{
	ft_putstr_fd("\E[H\E[2J", 1);
	ft_putstr_fd(PEACH, 1);
	ft_printf("Moves counter : %d\n", data->steps_count);
	ft_putstr_fd(RESET, 1);
}

int	check_next_tile(t_data *data, char direction, char tile)
{
	if ((direction == 'd' && data->map.map[data->p_y][data->p_x + 1] == tile)
		|| (direction == 'a' && data->map.map[data->p_y][data->p_x - 1] == tile)
		|| (direction == 's' && data->map.map[data->p_y + 1][data->p_x] == tile)
		|| (direction == 'w' && data->map.map[data->p_y - 1][data->p_x] == tile)
		)
		return (OK);
	else
		return (FAIL);
}

void	collect_coins(t_data *data, char direction)
{
	if ((direction == 'd' && data->map.map[data->p_y][data->p_x + 1] == 'C')
		|| (direction == 'a' && data->map.map[data->p_y][data->p_x - 1] == 'C')
		|| (direction == 's' && data->map.map[data->p_y + 1][data->p_x] == 'C')
		|| (direction == 'w' && data->map.map[data->p_y - 1][data->p_x] == 'C'))
		data->map.collected++;
}

int	win_game(t_data *data)
{
	if (data->map.can_exit == 1)
	{
		exit_game(data, 1);
		return (FAIL);
	}
	else
		return (OK);
}

void	move_player(t_data *data, char direction)
{
	if (check_next_tile(data, direction, '1') == OK
		|| (data->map.can_exit == 0
			&& check_next_tile(data, direction, 'E') == OK))
		return ;
	data->steps_count++;
	collect_coins(data, direction);
	if (data->map.collected == data->map.count_c)
		data->map.can_exit = 1;
	data->map.map[data->p_y][data->p_x] = '0';
	if (direction == 'd')
		data->p_x++;
	else if (direction == 'a')
		data->p_x--;
	else if (direction == 's')
		data->p_y++;
	else if (direction == 'w')
		data->p_y--;
	move_msg(data);
	if (data->map.can_exit == 1 && data->map.map[data->p_y][data->p_x] == 'E')
		win_game(data);
	data->map.map[data->p_y][data->p_x] = 'P';
}
