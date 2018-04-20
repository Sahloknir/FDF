/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:14:21 by axbal             #+#    #+#             */
/*   Updated: 2018/04/20 15:05:37 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	pick_line(t_data *data, t_dot d, int xo, int yo)
{
	t_dot	p1;
	t_dot	p2;

	p1.x = xo + (d.x * GAP_X);
	p1.y = (yo + (d.x * GAP_Y)) - (data->dots[d.y][d.x] * COEF);
	if (d.y != 0)
	{
		p2.x = (xo + GAP_Y) + (d.x * GAP_X);
		p2.y = (yo - GAP_X) + (d.x * GAP_Y) - (data->dots[d.y - 1][d.x] * COEF);
		color_set(data, data->dots[d.y][d.x], data->dots[d.y - 1][d.x]);
		draw_line(p1, p2, data);
	}
	if (d.x + 1 != data->size_x)
	{
		p2.x = xo + ((d.x + 1) * GAP_X);
		p2.y = yo + ((d.x + 1) * GAP_Y) - (data->dots[d.y][d.x + 1] * COEF);
		color_set(data, data->dots[d.y][d.x], data->dots[d.y][d.x + 1]);
		draw_line(p1, p2, data);
	}
}

void	gen_map(t_data *data)
{
	int		xo;
	int		yo;
	t_dot	d;

	xo = XO;
	yo = YO;
	d.y = 0;
	while (d.y < data->size_y)
	{
		d.x = 0;
		while (d.x < data->size_x)
		{
			pick_line(data, d, xo, yo);
			d.x++;
		}
		d.y++;
		xo -= GAP_Y;
		yo += GAP_X;
	}
}

void	set_ini(t_data *data)
{
	data->ini_x = XO;
	data->ini_y = YO;
}

void	size_map(t_data *data)
{
	data->gap_x = 40;
	data->gap_y = data->gap_x / 5;
	if (data->gap_y <= 0)
		data->gap_y = 1;
	WIN_WIDTH = (GAP_X * data->size_x) + (GAP_Y * data->size_y) + 30;
	WIN_HEIGHT = (GAP_X * data->size_y) + (GAP_Y * data->size_x) + 50;
	while ((data->win_w > 1900 || data->win_h > 800) && data->gap_x > 1)
	{
		data->gap_x--;
		data->gap_y = data->gap_x / 5;
		if (data->gap_y <= 0)
			data->gap_y = 1;
		WIN_WIDTH = (GAP_X * data->size_x) + (GAP_Y * data->size_y) + 30;
		WIN_HEIGHT = (GAP_X * data->size_y) + (GAP_Y * data->size_x) + 50;
	}
	if (data->win_w > 1900 || data->win_h > 800)
	{
		WIN_WIDTH = WIN_WIDTH > 1900 ? 1900 : WIN_WIDTH;
		WIN_HEIGHT = WIN_HEIGHT > 800 ? 800 : WIN_HEIGHT;
	}
	data->x0 = data->size_y * data->gap_y + 30;
	data->y0 = 50;
	set_ini(data);
	IMG_W = WIN_WIDTH;
	IMG_H = WIN_HEIGHT;
}
