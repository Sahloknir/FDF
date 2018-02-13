/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:14:21 by axbal             #+#    #+#             */
/*   Updated: 2018/02/13 12:19:39 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	gen_map(t_data *data)
{
	int		xo;
	int		yo;
	int		x;
	int		y;

	xo = 280;
	yo = 180;
	y = 0;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			if (y != 0)
			{
				draw_line(xo + (x * GAP_X), yo + (x * GAP_Y) - (data->dots[y][x] * COEF), (xo + GAP_Y) + (x * GAP_X), (yo - GAP_X) + (x * GAP_Y) - (data->dots[y - 1][x] * COEF), data);
			}
			if (x + 1 != data->size_x)
			{
				draw_line(xo + (x * GAP_X), yo + (x * GAP_Y) - (data->dots[y][x] * COEF), xo + ((x + 1) * GAP_X), yo + ((x + 1) * GAP_Y) - (data->dots[y][x + 1] * COEF), data);
			}
			x++;
		}
		y++;
		xo -= GAP_Y;
		yo += GAP_X;
	}
}
