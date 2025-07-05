/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggochita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:24:28 by ggochita          #+#    #+#             */
/*   Updated: 2024/05/08 15:24:32 by ggochita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	check_chars(t_data *data)
{
	int		y;
	size_t	x;
	char	current;

	y = 0;
	current = 't';
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x] != '\0')
		{
			current = data->map.map[y][x];
			if (current == '\n')
				break ;
			if (ft_strchr("01CEP", current) == NULL)
				exit_w_error("[there is wrong sym in map]\n", data, 1);
			count_sym(current, data);
			x++;
		}
		y++;
	}
	if (!data->map.count_p || !data->map.count_e || !data->map.count_c)
		return (FAIL);
	else
		return (OK);
}

int	check_top_bot(int row, char **map)
{
	int	i;

	i = 0;
	while (map[row][i] && map[row][i] != '\n')
	{
		if (map[row][i] != '1')
			return (FAIL);
		i++;
	}
	return (OK);
}

int	check_edges(int line_count, char **map)
{
	int	i;

	i = 1;
	if (check_top_bot(0, map) == FAIL
		|| check_top_bot(line_count, map) == FAIL)
		return (FAIL);
	while (i < line_count)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[0]) - 2] != '1')
			return (FAIL);
		i++;
	}
	return (OK);
}

int	check_rectangle(t_data *data)
{
	int		y;
	size_t	x;

	y = 0;
	x = 0;
	data->map.line_len = ft_strlen(data->map.map[y]) - 1;
	while (data->map.map[y])
	{
		while (data->map.map[y][x] && data->map.map[y][x] != '\n')
			x++;
		if (x != data->map.line_len)
			return (FAIL);
		x = 0;
		y++;
	}
	return (OK);
}

int	check_map(t_data *data)
{
	if (check_chars(data) == FAIL)
	{
		error_msg("[there is not P , C or E]\n");
		exit_game(data, 0);
	}
	if ((data->map.count_p > 1) || (data->map.count_e > 1))
	{
		error_msg("[there is more P or E than it should be]\n");
		exit_game(data, 0);
	}
	if (check_rectangle(data) == FAIL)
	{
		error_msg("[map is not rectangular]\n");
		exit_game(data, 0);
	}
	if (check_edges(data->map.line_count - 1, data->map.map) == FAIL)
	{
		error_msg("[no wall on edges]\n");
		exit_game(data, 0);
	}
	return (OK);
}
