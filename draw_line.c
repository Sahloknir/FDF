/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 12:44:40 by axbal             #+#    #+#             */
/*   Updated: 2018/01/29 13:59:41 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	large_angle(int x1, int y1, int x2, int y2, t_data *data)
{
	float	ratio;
	float	ratio_scale;
	int		current_x;
	int		current_y;
	int		growth;

	ft_putstr("large\n");
	growth = y2 < y1 ? -1 : 1;
	ratio = y1 > y2 ? (y2 - y1) / (x1 - x2) : (y2 - y1) / (x2 - x1);
	ratio_scale = 1;
	current_x = x1;
	current_y = y1;
	while (current_y != y2)
	{
		if (ratio_scale >= ratio)
		{
			current_x++;
			ratio_scale -= ratio;
		}
		mlx_pixel_put(MLX, WIN, current_x, current_y, 0xFFFFFF);
		ratio_scale += 1;
		current_y += growth;
	}
	mlx_pixel_put(MLX, WIN, x1, y1, 0xFF0000);
	mlx_pixel_put(MLX, WIN, x2, y2, 0xFF0000);
}

void	sharp_angle(int x1, int y1, int x2, int y2, t_data *data)
{
	float	ratio;
	float	ratio_scale;
	int		current_x;
	int		current_y;
	int		growth;

	ft_putstr("sharp\n");
	growth = y2 < y1 ? -1 : 1;
	ratio = y1 > y2 ? (x2 - x1) / (y1 - y2) : (x2 - x1) / (y2 - y1);
	ratio_scale = 1;
	current_x = x1;
	current_y = y1;
	while (current_x != x2)
	{
		if (ratio_scale >= ratio)
		{
			current_y += growth;
			ratio_scale -= ratio;
		}
		mlx_pixel_put(MLX, WIN, current_x, current_y, 0xFFFFFF);
		ratio_scale += 1;
		current_x++;
	}
	mlx_pixel_put(MLX, WIN, x1, y1, 0xFF0000);
	mlx_pixel_put(MLX, WIN, x2, y2, 0xFF0000);
}

void	draw_line(int x1, int y1, int x2, int y2, t_data *data)
{
	int		tmp;

	if (x1 > x2)
	{
		tmp = x2;
		x2 = x1;
		x1 = tmp;
		tmp = y2;
		y2 = y1;
		y1 = tmp;
	}
	if (y2 > y1)
	{
		if ((y2 - y1) > (x2 - x1))
			large_angle(x1, y1, x2, y2, data);
		else
			sharp_angle(x1, y1, x2, y2, data);
	}
	else if (y2 < y1)
	{
		if ((y1 - y2) > (x2 - x1))
			large_angle(x1, y1, x2, y2, data);
		else
			sharp_angle(x1, y1, x2, y2, data);
	}
}
