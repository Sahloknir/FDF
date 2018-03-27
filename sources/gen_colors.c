/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 14:48:07 by axbal             #+#    #+#             */
/*   Updated: 2018/03/27 10:42:51 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		set_max_val(t_data *data, int **dots, int y, int x)
{
	data->max_val = dots[y][x];
	data->max_x = x;
	data->max_y = y;
}

void		set_min_val(t_data *data, int **dots, int y, int x)
{
	data->min_val = dots[y][x];
	data->min_x = x;
	data->min_y = y;
}

int			calc_range(int **dots, t_data *data, int y, int x)
{
	int		i;
	int		j;

	i = 0;
	data->min_val = dots[0][0];
	data->max_val = dots[0][0];
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (dots[i][j] > data->max_val)
				set_max_val(data, dots, i, j);
			if (dots[i][j] < data->min_val)
				set_min_val(data, dots, i, j);
			j++;
		}
		i++;
	}
	data->decal = data->min_val * -1;
	return (data->max_val - data->min_val);
}

t_color		new_color(int r, int g, int b, int alpha)
{
	t_color		color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.alpha = alpha;
	return (color);
}

void		gen_colors(t_data *data)
{
	t_color		*tab;
	int			i;

	data->range = calc_range(data->dots, data, data->size_y, data->size_x);
	if (!(tab = (t_color *)malloc(sizeof(t_color) * 8)))
		data->colors = NULL;
	i = -1;
	if (data->nocolor == 0)
	{
		tab[0] = new_color(179, 218, 251, 0);
		tab[1] = new_color(251, 224, 76, 0);
		tab[2] = new_color(204, 234, 184, 0);
		tab[3] = new_color(167, 197, 121, 0);
		tab[4] = new_color(84, 104, 50, 0);
		tab[5] = new_color(43, 63, 43, 0);
		tab[6] = new_color(86, 61, 29, 0);
		tab[7] = new_color(241, 238, 233, 0);
	}
	else
	{
		while (++i < 8)
			tab[i] = new_color(255, 255, 255, 0);
	}
	data->colors = tab;
}
