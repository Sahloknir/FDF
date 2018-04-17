/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:55:56 by axbal             #+#    #+#             */
/*   Updated: 2018/04/17 14:27:36 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		close_window(t_data *data)
{
	mlx_destroy_window(MLX, WIN);
	exit(0);
	return (0);
}

void	reset_image(t_data *data)
{
	mlx_destroy_image(MLX, IMG);
	IMG = mlx_new_image(MLX, WIN_WIDTH, WIN_HEIGHT);
	IMG_STR = mlx_get_data_addr(IMG, &BPP, &S_L, &ENDIAN);
	BPP /= 8;
}

void	get_value1(t_data *data)
{
	if (data->c_y1 <= data->range / 50)
		data->c_y1 = 1;
	else if (data->c_y1 < data->range / 10)
		data->c_y1 = 2;
	else if (data->c_y1 < data->range / 4)
		data->c_y1 = 3;
	else if (data->c_y1 < data->range / 2)
		data->c_y1 = 4;
	else if (data->c_y1 < data->range - (data->range / 3))
		data->c_y1 = 5;
	else if (data->c_y1 < data->range - (data->range / 5))
		data->c_y1 = 6;
	else
		data->c_y1 = 7;
}

void	get_value2(t_data *data)
{
	if (data->c_y2 <= data->range / 50)
		data->c_y2 = 1;
	else if (data->c_y2 < data->range / 10)
		data->c_y2 = 2;
	else if (data->c_y2 < data->range / 4)
		data->c_y2 = 3;
	else if (data->c_y2 < data->range / 2)
		data->c_y2 = 4;
	else if (data->c_y2 < data->range - (data->range / 3))
		data->c_y2 = 5;
	else if (data->c_y2 < data->range - (data->range / 5))
		data->c_y2 = 6;
	else
		data->c_y2 = 7;
}

void	color_set(t_data *data, int c_y1, int c_y2)
{
	data->c_y1 = c_y1 + data->decal;
	data->c_y2 = c_y2 + data->decal;
	if (data->c_y1 == 0 && data->c_y2 == 0)
	{
		data->c_y2 = 1;
		data->cgrowth = 1;
	}
	else
	{
		get_value1(data);
		get_value2(data);
		if (data->c_y2 < data->c_y1)
		{
			data->c_y1--;
			data->c_y2 = (data->c_y1 - data->c_y2) + 1;
			data->cgrowth = -1;
		}
		else
		{
			data->c_y2 = (data->c_y2 - data->c_y1);
			data->cgrowth = 1;
		}
		if (data->c_y2 == 0)
			data->c_y2 = 1;
	}
}
