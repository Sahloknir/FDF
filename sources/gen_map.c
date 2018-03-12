/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:14:21 by axbal             #+#    #+#             */
/*   Updated: 2018/03/08 12:47:43 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	gen_map(t_data *data)
{
	int		xo;
	int		yo;
	int		x;
	int		y;

	xo = XO;
	yo = YO;
	y = 0;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			if (y != 0)
			{
				color_set(data, data->dots[y][x], data->dots[y - 1][x]);
				//				printf("start from index %i, divide in %i colors with growth = %i\n", data->c_y1, data->c_y2, data->cgrowth);
				draw_line(xo + (x * GAP_X), yo + (x * GAP_Y) - (data->dots[y][x] * COEF), (xo + GAP_Y) + (x * GAP_X), (yo - GAP_X) + (x * GAP_Y) - (data->dots[y - 1][x] * COEF), data);
			}
			if (x + 1 != data->size_x)
			{
				color_set(data, data->dots[y][x], data->dots[y][x + 1]);
				//				printf("start from index %i, divide in %i colors with growth = %i\n", data->c_y1, data->c_y2, data->cgrowth);
				draw_line(xo + (x * GAP_X), yo + (x * GAP_Y) - (data->dots[y][x] * COEF), xo + ((x + 1) * GAP_X), yo + ((x + 1) * GAP_Y) - (data->dots[y][x + 1] * COEF), data);
			}
			x++;
		}
		y++;
		xo -= GAP_Y;
		yo += GAP_X;
	}
}

void	adapt_coef(t_data *data)
{
	int		max_alt;
	int		min_alt;

	max_alt = (YO + (data->max_y * GAP_X)) + (data->max_x * GAP_Y)
	- (data->max_val * COEF);
	min_alt = (YO + (data->min_y * GAP_X)) + (data->min_x * GAP_Y)
	- (data->dots[data->min_y][data->min_x] * COEF);
	while (max_alt < 0 || min_alt > IMG_H)
	{
		COEF -= COEF > 1 ? 1 : 0.1;
		max_alt = (YO + (data->max_y * GAP_X)) + (data->max_x * GAP_Y)
		- (data->dots[data->max_y][data->max_x] * COEF);
		min_alt = (YO + (data->min_y * GAP_X)) + (data->min_x * GAP_Y)
		- (data->dots[data->min_y][data->min_x] * COEF);
	}
}

void	size_map(t_data *data)
{
	if (data->gap_x == 0)
		data->gap_x = 40;
	data->gap_y = data->gap_x / 5;
	if (data->gap_y <= 0)
		data->gap_y = 1;
	if (data->win_w == 0)
	{
		WIN_WIDTH = (GAP_X * data->size_x) + (GAP_Y * data->size_y) + 30;
		WIN_HEIGHT = (GAP_X * data->size_y) + (GAP_Y * data->size_x) + 50;
	}
	while ((data->win_w > 1900 || data->win_h > 800) && data->gap_x > 1)
	{
		data->gap_x--;
		data->gap_y = data->gap_x / 5;
		if (data->gap_y <= 0)
			data->gap_y = 1;
		WIN_WIDTH = (GAP_X * data->size_x) + (GAP_Y * data->size_y) + 30;
		WIN_HEIGHT = (GAP_X * data->size_y) + (GAP_Y * data->size_x) + 50;
	}
	data->x0 = data->size_y * data->gap_y + 30;
	data->y0 = 50;
	IMG_W = (GAP_X * data->size_x) + (GAP_Y * data->size_y) + 30;
	IMG_H = (GAP_X * data->size_y) + (GAP_Y * data->size_x) + 50;
	adapt_coef(data);
}
