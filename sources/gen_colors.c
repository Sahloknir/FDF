/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 14:48:07 by axbal             #+#    #+#             */
/*   Updated: 2018/03/05 15:05:00 by axbal            ###   ########.fr       */
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
	data->max_x = 0;
	data->max_y = 0;
	data->min_x = 0;
	data->min_y = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (dots[i][j] > max)
			{
				max = dots[i][j];
				data->max_x = j;
				data->max_y = i;
			}
			if (dots[i][j] < min)
			{
				min = dots[i][j];
				data->min_x = j;
				data->min_y = i;
			}
			j++;
		}
		i++;
	}
	data->decal = min * -1;
	data->max_val = max;
	data->min_val = min;
	return (max - min);
}

void	gen_colors(t_data *data)
{
	t_color		*tab;
	int			range;
	int			i;

	range = calc_range(data->dots, data, data->size_y, data->size_x);
	if (!(tab = (t_color *)malloc(sizeof(t_color) * 8)))
		data->colors = NULL;
	i = -1;
	/*	tab[0] = 0xB3DAFB;
		tab[1] = 0xFBE04C;
		tab[2] = 0xCCEAB8;
		tab[3] = 0xA7C579;
		tab[4] = 0x546832;
		tab[5] = 0x2B3F2B;
		tab[6] = 0x563D1D;
		tab[7] = 0xF1EEE9;*/
	if (data->nocolor == 0)
	{
		tab[0].r = 179;
		tab[0].g = 218;
		tab[0].b = 251;
		tab[0].alpha = 0;
		tab[1].r = 251;
		tab[1].g = 224;
		tab[1].b = 76;
		tab[1].alpha = 0;
		tab[2].r = 204;
		tab[2].g = 234;
		tab[2].b = 184;
		tab[2].alpha = 0;
		tab[3].r = 167;
		tab[3].g = 197;
		tab[3].b = 121;
		tab[3].alpha = 0;
		tab[4].r = 84;
		tab[4].g = 104;
		tab[4].b = 50;
		tab[4].alpha = 0;
		tab[5].r = 43;
		tab[5].g = 63;
		tab[5].b = 43;
		tab[5].alpha = 0;
		tab[6].r = 86;
		tab[6].g = 61;
		tab[6].b = 29;
		tab[6].alpha = 0;
		tab[7].r = 241;
		tab[7].g = 238;
		tab[7].b = 233;
		tab[7].alpha = 0;
	}
	else
	{
		while (++i < 8)
		{
			tab[i].r = 255;
			tab[i].g = 255;
			tab[i].b = 255;
			tab[i].alpha = 0;
		}
	}
	data->colors = tab;
	data->range = range;
	//	printf("\ncreating color array of %i\n", range);
}
