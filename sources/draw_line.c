/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 12:44:40 by axbal             #+#    #+#             */
/*   Updated: 2018/03/01 11:25:18 by axbal            ###   ########.fr       */
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

	float	t1;
	float	t2;
	int		cgrowth;
	int		abs;
	int		test;

//	printf("drawing large angle from (%i;%i) to (%i;%i)\n", x1, y1, x2, y2);
	growth = y2 < y1 ? -1 : 1;
	ratio = y1 > y2 ? (float)(y1 - y2)/(x2 - x1) : (float)(y2 - y1)/(x2 - x1);
	ratio_scale = 1;
	current_x = x1;
	current_y = y1;

	t1 = 1;
	test = 1;
	abs = y2 - y1;
	if (abs < 0)
		abs *= -1;
	t2 = abs / data->c_y2;
	cgrowth = data->cgrowth;

	while (current_y != y2)
	{
		if (ratio_scale >= ratio)
		{
			current_x++;
			ratio_scale -= ratio;
		}
		if (t1 >= t2 && test < data->c_y2)
		{
			t1 -= t2;
			data->c_y1 += cgrowth;
			test++;
		}
		mlx_pixel_put(MLX, WIN, current_x, current_y, data->colors[data->c_y1]);
		ratio_scale += 1;
		current_y += growth;
		t1++;
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

	float	t1;
	float	t2;
	int		cgrowth;
	int		test;

//	printf("drawing sharp angle from (%i;%i) to (%i;%i)\n", x1, y1, x2, y2);
	growth = y2 < y1 ? -1 : 1;
	ratio = y1 > y2 ? (float)(x2 - x1)/(y1 - y2) : (float)(x2 - x1)/(y2 - y1);
	ratio_scale = 1;
	current_x = x1;
	current_y = y1;

	t1 = 1;
	test = 1;
	t2 = (x2 - x1) / data->c_y2;
	cgrowth = data->cgrowth;

//	printf("growth = %i\n", cgrowth);
	while (current_x != x2)
	{
		if (ratio_scale >= ratio)
		{
			current_y += growth;
			ratio_scale -= ratio;
		}
		if (t1 >= t2 && test < data->c_y2)
		{
			t1 -= t2;
			test++;
			data->c_y1 += cgrowth;
		}
		mlx_pixel_put(MLX, WIN, current_x, current_y, data->colors[data->c_y1]);
		ratio_scale += 1;
		current_x++;
		t1++;
	}
//	mlx_pixel_put(MLX, WIN, x1, y1, 0xFF0000);
//	mlx_pixel_put(MLX, WIN, x2, y2, 0xFF0000);
}

void	vertical_line(int x1, int y1, int x2, int y2, t_data *data)
{
	int		current_y;
	int		cgrowth;
	int		growth;
	int		cpt;
	int		t1;
	int		t2;

//	printf("drawing vertical line from (%i;%i) to (%i;%i)\n", x1, y1, x2, y2);
	x2 = 0;
	growth = 1;
	cgrowth = data->cgrowth;
	cpt = 1;
	if (y2 < y1)
	{
		t1 = y2;
		y2 = y1;
		y1 = t1;
	}
	t1 = 1;
	t2 = (y2 - y1) / data->c_y2;
	current_y = y1;
	while (current_y != y2)
	{
		if (t1 >= t2 && cpt < data->c_y2)
		{
			t1 -= t2;
			cpt++;
			data->c_y1+= cgrowth;
		}
		mlx_pixel_put(MLX, WIN, x1, current_y, data->colors[data->c_y1]);
		current_y += growth;
		t1++;
	}
//	mlx_pixel_put(MLX, WIN, x1, y1, 0xFF0000);
//	mlx_pixel_put(MLX, WIN, x2, y2, 0xFF0000);
}

void	horizontal_line(int x1, int y1, int x2, int y2, t_data *data)
{
	int		current_x;
	int		cpt;
	int		t1;
	int		t2;
	int		cgrowth;

//	printf("drawing horizontal line from (%i;%i) to (%i;%i)\n", x1, y1, x2, y2);
	y2 = 0;
	cpt = 1;
	t1 = 1;
	t2 = (x2 - x1) / data->c_y2;
	cgrowth = data->cgrowth;
	current_x = x1;
	while (current_x != x2)
	{
		if (t1 >= t2 && cpt < data->c_y2)
		{
			cpt++;
			t1 -= t2;
			data->c_y1 += cgrowth;
		}
		mlx_pixel_put(MLX, WIN, current_x, y1, data->colors[data->c_y1]);
		current_x++;
		t1++;
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
