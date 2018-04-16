/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 12:44:40 by axbal             #+#    #+#             */
/*   Updated: 2018/04/16 12:59:11 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	large_angle(t_dot p1, t_dot p2, t_data *data)
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

	growth = p2.y < p1.y ? -1 : 1;
	ratio = p1.y > p2.y ? (float)(p1.y - p2.y)/(p2.x - p1.x) :
	(float)(p2.y - p1.y)/(p2.x - p1.x);
	ratio_scale = 1;
	current_x = p1.x;
	current_y = p1.y;
	t1 = 1;
	test = 1;
	abs = p2.y - p1.y;
	if (abs < 0)
		abs *= -1;
	t2 = abs / data->c_y2;
	cgrowth = data->cgrowth;
	while (current_y != p2.y)
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
		put_pixel_to_image(current_x, current_y, data, data->colors[data->c_y1]);
		ratio_scale += 1;
		current_y += growth;
		t1++;
	}
}

void	sharp_angle(t_dot p1, t_dot p2, t_data *data)
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

	growth = p2.y < p1.y ? -1 : 1;
	ratio = p1.y > p2.y ? (float)(p2.x - p1.x)/(p1.y - p2.y) :
	(float)(p2.x - p1.x)/(p2.y - p1.y);
	ratio_scale = 1;
	current_x = p1.x;
	current_y = p1.y;
	t1 = 1;
	test = 1;
	t2 = (p2.x - p1.x) / data->c_y2;
	cgrowth = data->cgrowth;
	while (current_x != p2.x)
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
		put_pixel_to_image(current_x, current_y, data, data->colors[data->c_y1]);
		ratio_scale += 1;
		current_x++;
		t1++;
	}
}

void	vertical_line(t_dot p1, t_dot p2, t_data *data)
{
	int		current_y;
	int		cgrowth;
	int		cpt;
	int		t1;
	int		t2;

	cpt = 1;
	cgrowth = data->cgrowth;
	if (p2.y < p1.y)
		ft_swap(&p2.y, &p1.y);
	t1 = 1;
	t2 = (p2.y - p1.y) / data->c_y2;
	current_y = p1.y;
	while (current_y != p2.y)
	{
		if (t1 >= t2 && cpt < data->c_y2)
		{
			t1 -= t2;
			cpt++;
			data->c_y1+= cgrowth;
		}
		put_pixel_to_image(p1.x, current_y, data, data->colors[data->c_y1]);
		current_y += 1;
		t1++;
	}
}

void	horizontal_line(t_dot p1, t_dot p2, t_data *data)
{
	int		current_x;
	int		cpt;
	int		t1;
	int		t2;
	int		cgrowth;

	cpt = 1;
	t1 = 1;
	t2 = (p2.x - p1.x) / data->c_y2;
	cgrowth = data->cgrowth;
	current_x = p1.x;
	while (current_x != p2.x)
	{
		if (t1 >= t2 && cpt < data->c_y2)
		{
			cpt++;
			t1 -= t2;
			data->c_y1 += cgrowth;
		}
		put_pixel_to_image(current_x, p1.y, data, data->colors[data->c_y1]);
		current_x++;
		t1++;
	}
}

void	draw_line(t_dot p1, t_dot p2, t_data *data)
{
	if (p1.x > p2.x)
	{
		ft_swap(&p1.x, &p2.x);
		ft_swap(&p1.y, &p2.y);
	}
	if (p1.x == p2.x)
		vertical_line(p1, p2, data);
	else if (p1.y == p2.y)
		horizontal_line(p1, p2, data);
	else if (p2.y > p1.y)
	{
		if ((p2.y - p1.y) > (p2.x - p1.x))
			large_angle(p1, p2, data);
		else
			sharp_angle(p1, p2, data);
	}
	else if (p2.y < p1.y)
	{
		if ((p1.y - p2.y) > (p2.x - p1.x))
			large_angle(p1, p2, data);
		else
			sharp_angle(p1, p2, data);
	}
}
