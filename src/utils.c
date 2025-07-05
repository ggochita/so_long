/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggochita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:27:25 by ggochita          #+#    #+#             */
/*   Updated: 2024/05/08 15:27:30 by ggochita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	count_sym(char current, t_data *data)
{
	if (current == 'P')
		data->map.count_p += 1;
	if (current == 'E')
		data->map.count_e += 1;
	if (current == 'C')
		data->map.count_c += 1;
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	find_coin(t_data *data, int *coin_x, int *coin_y)
{
	int	y;
	int	x;
	int	rows;
	int	cols;

	x = 0;
	y = 0;
	rows = data->map.line_count;
	cols = data->map.line_len;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			if (data->map.map[y][x] == 'C')
			{
				*coin_x = x;
				*coin_y = y;
				return (OK);
			}
			x++;
		}
		y++;
	}
	return (FAIL);
}

void	clean_reach_res(t_params *params)
{
	if (params->visited)
		free_visited_array(params->visited, params->data->map.line_count);
	free(params->queue);
}
