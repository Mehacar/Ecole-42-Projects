/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_map_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehacar <mehacar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:20:02 by mehacar           #+#    #+#             */
/*   Updated: 2023/04/09 02:24:46 by mehacar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	recursive_control(t_data *data, int y, int x)
{
	start_control(data, y, x);
	second_control(data, y, x);
	third_control(data, y, x);
	fourth_control(data, y, x);
}

void	start_control(t_data *data, int y, int x)
{
	if (data->controlmap[y + 1][x] != '.' &&
		data->controlmap[y + 1][x] != '1')
	{
		y++;
		if (data->controlmap[y][x] == 'E')
			data->exit++;
		if (data->controlmap[y][x] == 'C')
			data->collectnum++;
		data->controlmap[y][x] = '.';
		recursive_control(data, y, x);
		y--;
	}
}

void	second_control(t_data *data, int y, int x)
{
	if (data->controlmap[y][x + 1] != '.' &&
		data->controlmap[y][x + 1] != '1')
	{
		x++;
		if (data->controlmap[y][x] == 'E')
			data->exit++;
		if (data->controlmap[y][x] == 'C')
			data->collectnum++;
		data->controlmap[y][x] = '.';
		recursive_control(data, y, x);
		x--;
	}
}

void	third_control(t_data *data, int y, int x)
{
	if (data->controlmap[y - 1][x] != '.' &&
		data->controlmap[y - 1][x] != '1')
	{
		y--;
		if (data->controlmap[y][x] == 'E')
			data->exit++;
		if (data->controlmap[y][x] == 'C')
			data->collectnum++;
		data->controlmap[y][x] = '.';
		recursive_control(data, y, x);
		y++;
	}
}

void	fourth_control(t_data *data, int y, int x)
{
	if (data->controlmap[y][x - 1] != '.' &&
		data->controlmap[y][x - 1] != '1')
	{
		x--;
		if (data->controlmap[y][x] == 'E')
			data->exit++;
		if (data->controlmap[y][x] == 'C')
			data->collectnum++;
		data->controlmap[y][x] = '.';
		recursive_control(data, y, x);
		x++;
	}
}
