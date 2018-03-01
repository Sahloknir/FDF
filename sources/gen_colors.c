/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 14:48:07 by axbal             #+#    #+#             */
/*   Updated: 2018/03/01 01:20:50 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

int		calc_range(int **dots, t_data *data, int y, int x)
{
	int		max;
	int		min;
	int		i;
	int		j;

	i = 0;
	min = dots[0][0];
	max = dots[0][0];
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (dots[i][j] > max)
				max = dots[i][j];
			if (dots[i][j] < min)
				min = dots[i][j];
			j++;
		}
		i++;
	}
	data->decal = min * -1;
	return (max - min);
}

void	gen_colors(t_data *data)
{
	int		*tab;
	int		range;
	int		i;

	range = calc_range(data->dots, data, data->size_y, data->size_x);
	if (!(tab = (int *)malloc(sizeof(int) * 6)))
		data->colors = NULL;
	i = -1;
	if (data->nocolor == 0)
	{
		tab[0] = 0xB3DAFB;
		tab[1] = 0xFBE04C;
	tab[2] = 0xCCEAB8;
	tab[3] = 0xA7C579;
	tab[4] = 0x546832;
	tab[5] = 0x2B3F2B;
	tab[6] = 0x563D1D;
	tab[7] = 0xF1EEE9;
	}
	else
	{
		while (++i < 8)
			tab[i] = 0xFFFFFF;
	}
	data->colors = tab;
	data->range = range;
	//	printf("\ncreating color array of %i\n", range);
}
