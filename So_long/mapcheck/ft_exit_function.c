/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehacar <mehacar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:20:14 by mehacar           #+#    #+#             */
/*   Updated: 2023/04/09 02:34:55 by mehacar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	exit_function(t_data *data)
{
	int	i;

	i = -1;
	while (i++ < 4)
		mlx_destroy_image(data->mlx, data->img[i]);
	free(data->img);
	mlx_destroy_window(data->mlx, data->mlx_window);
	exit(1);
	return (1);
}
