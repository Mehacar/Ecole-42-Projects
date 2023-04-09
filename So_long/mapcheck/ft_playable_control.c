/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_playable_control.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehacar <mehacar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:20:44 by mehacar           #+#    #+#             */
/*   Updated: 2023/04/09 02:29:57 by mehacar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	line_control(t_data *data)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	while (data->map[0][j])
		j++;
	flag = j;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
			j++;
		if (j != flag)
		{
			ft_printf("Map length error!");
			exit(1);
		}
		i++;
	}
}

void	collectable_control(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C' && data->controlmap[i][j] != '.')
			{
				ft_printf("Unreachable coin. Coordinate : y = %d, \
                    x = %d", i, j);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	unreachable_exit_control(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E' && data->controlmap[i][j] != '.')
			{
				ft_printf("Unreachable exit. Coordinate : y = %d, \
                    x = %d", i, j);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	door_control(t_data *data)
{
	if (data->exit > 1)
	{
		ft_printf("There are exit more than one!");
		exit(1);
	}
}
