/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 12:44:40 by axbal             #+#    #+#             */
/*   Updated: 2018/02/13 11:59:02 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	large_angle(int x1, int y1, int x2, int y2, t_data *data)
{
	float	ratio;
	float	ratio_scale;
	int		current_x;
	int		current_y;
	int		growth;

//	printf("drawing large angle from (%i;%i) to (%i;%i)\n", x1, y1, x2, y2);
	growth = y2 < y1 ? -1 : 1;
	ratio = y1 > y2 ? (float)(y1 - y2)/(x2 - x1) : (float)(y2 - y1)/(x2 - x1);
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
//	mlx_pixel_put(MLX, WIN, x1, y1, 0xFF0000);
//	mlx_pixel_put(MLX, WIN, x2, y2, 0xFF0000);
}

void	sharp_angle(int x1, int y1, int x2, int y2, t_data *data)
{
	float	ratio;
	float	ratio_scale;
	int		current_x;
	int		current_y;
	int		growth;

//	printf("drawing sharp angle from (%i;%i) to (%i;%i)\n", x1, y1, x2, y2);
	growth = y2 < y1 ? -1 : 1;
	ratio = y1 > y2 ? (float)(x2 - x1)/(y1 - y2) : (float)(x2 - x1)/(y2 - y1);
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
//	mlx_pixel_put(MLX, WIN, x1, y1, 0xFF0000);
//	mlx_pixel_put(MLX, WIN, x2, y2, 0xFF0000);
}

void	vertical_line(int x1, int y1, int x2, int y2, t_data *data)
{
	int		current_y;

//	printf("drawing vertical line from (%i;%i) to (%i;%i)\n", x1, y1, x2, y2);
	x2 = 0;
	current_y = y1;
	while (current_y != y2)
	{
		mlx_pixel_put(MLX, WIN, x1, current_y, 0xFFFFFF);
		current_y++;
	}
//	mlx_pixel_put(MLX, WIN, x1, y1, 0xFF0000);
//	mlx_pixel_put(MLX, WIN, x2, y2, 0xFF0000);
}

void	horizontal_line(int x1, int y1, int x2, int y2, t_data *data)
{
	int		current_x;

//	printf("drawing horizontal line from (%i;%i) to (%i;%i)\n", x1, y1, x2, y2);
	y2 = 0;
	current_x = x1;
	while (current_x != x2)
	{
		mlx_pixel_put(MLX, WIN, current_x, y1, 0xFFFFFF);
		current_x++;
	}
//	mlx_pixel_put(MLX, WIN, x1, y1, 0xFF0000);
//	mlx_pixel_put(MLX, WIN, x2, y2, 0xFF0000);
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
	if (x1 == x2)
		vertical_line(x1, y1, x2, y2, data);
	else if (y1 == y2)
		horizontal_line(x1, y1, x2, y2, data);
	else if (y2 > y1)
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
