/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggochita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:23:27 by ggochita          #+#    #+#             */
/*   Updated: 2024/05/10 17:10:53 by ggochita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	**create_visited_array(int rows, int cols)
{
	int	**array;
	int	i;

	array = (int **)malloc(rows * sizeof(int *));
	if (!array)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		array[i] = (int *)calloc(cols, sizeof(int));
		if (!array[i])
		{
			while (--i >= 0)
				free(array[i]);
			free(array);
			return (NULL);
		}
		i++;
	}
	return (array);
}

void	free_visited_array(int **array, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	proces_xy(t_point p, int dx, int dy, t_params *params)
{
	int	nx;
	int	ny;
	int	cols;
	int	rows;

	nx = p.x + dx;
	ny = p.y + dy;
	cols = params->data->map.line_len;
	rows = params->data->map.line_count;
	if ((nx >= 0 && nx < cols && ny >= 0)
		&& (ny < rows && !params->visited[ny][nx]))
	{
		params->visited[ny][nx] = 1;
		if (params->data->map.map[ny][nx] == '1')
			return (0);
		if ((params->data->map.map[ny][nx] == 'E')
				&& (params->data->coins_checked != params->data->map.count_c))
			return (0);
		if (params->data->map.map[ny][nx] == params->target)
			return (1);
		params->queue[*(params->rear)] = (t_point){nx, ny};
		(*(params->rear))++;
	}
	return (0);
}

int	is_reachable(t_data *data, int start_x, int start_y, char target)
{
	t_params	params;
	int			front;
	int			rear;
	t_point		p;

	rear = 0;
	params.rear = &rear;
	if (!init_reach_res(&params, data, target, &front))
		return (0);
	params.queue[rear++] = (t_point){start_x, start_y};
	params.visited[start_y][start_x] = 1;
	while (front < rear)
	{
		p = params.queue[front++];
		if (proces_xy(p, 1, 0, &params) || proces_xy(p, -1, 0, &params)
			|| proces_xy(p, 0, 1, &params) || proces_xy(p, 0, -1, &params))
		{
			if (target == 'C')
				data->coins_checked++;
			clean_reach_res(&params);
			return (1);
		}
	}
	clean_reach_res(&params);
	return (0);
}

void	is_map_playable(t_data *data)
{
	int		coin_x;
	int		coin_y;
	t_data	*sim_data;

	sim_data = NULL;
	assign_sim(&sim_data, data, &coin_x, &coin_y);
	if (!sim_data->map.map)
		exit_w_error("[Failed to allocate memory for map copy]", data, 1);
	while (data->coins_checked < sim_data->map.count_c)
	{
		if (!find_coin(sim_data, &coin_x, &coin_y))
			exit_w_error("[MAP has no solution]", data, 1);
		if (!is_reachable(sim_data, sim_data->p_x, sim_data->p_y, 'C'))
			exit_w_error("[MAP has no solution]", data, 1);
		sim_data->map.map[coin_y][coin_x] = '0';
		sim_data->p_x = coin_x;
		sim_data->p_y = coin_y;
		if (data->coins_checked == sim_data->map.count_c - 1)
		{
			if (!is_reachable(sim_data, coin_x, coin_y, 'E'))
				exit_w_error("[MAP has no solution]", data, 1);
		}
		data->coins_checked++;
	}
	free_map(sim_data);
}
