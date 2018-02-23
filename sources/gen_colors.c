/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 14:48:07 by axbal             #+#    #+#             */
/*   Updated: 2018/02/22 16:30:47 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	color_set(t_data *data)
{
	if (data->c_y1 == 0 && data->c_y2 == 0)
		data->c_y2 = 1;
	else if (!(data->c_y1 > data->range - (data->range / 10) && data->c_y1 > data->range - (data->range / 10)))
	{
		data->c_y1 = 0;
		data->c_y2 = 1;
	}
	else
	{
		data->c_y1 = 0;
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
	i = 1;
	tab[0] = 0xB3DAFB;
	tab[1] = 0xDAEEC7;
	tab[2] = 0xCCEAB8;
	tab[3] = 0xC8E5B4;
	tab[4] = 0xC3E0B0;
	tab[5] = 0xF1EEE9;
	data->colors = tab;
	data->range = range;
//	printf("\ncreating color array of %i\n", range);
}
