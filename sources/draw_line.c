/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 12:44:40 by axbal             #+#    #+#             */
/*   Updated: 2018/04/20 16:22:44 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	large_angle(t_dot p1, t_dot p2, t_data *data, t_util u)
{
	u.c_ratio = ft_abs(p2.y - p1.y) / data->c_y2;
	while (u.c_y != p2.y)
	{
		if (u.ratio_s >= u.ratio)
		{
			u.c_x++;
			u.ratio_s -= u.ratio;
		}
		if (u.c_ratio_s >= u.c_ratio && u.color_index < data->c_y2)
		{
			u.c_ratio_s -= u.c_ratio;
			data->c_y1 += data->cgrowth;
			u.color_index++;
		}
		put_pixel_to_image(u.c_x, u.c_y, data, data->colors[data->c_y1]);
		u.ratio_s += 1;
		u.c_ratio_s += 1;
		u.c_y += u.growth;
	}
}

void	sharp_angle(t_dot p1, t_dot p2, t_data *data, t_util u)
{
	u.c_ratio = (p2.x - p1.x) / data->c_y2;
	while (u.c_x != p2.x)
	{
		if (u.ratio_s >= u.ratio)
		{
			u.c_y += u.growth;
			u.ratio_s -= u.ratio;
		}
		if (u.c_ratio_s >= u.c_ratio && u.color_index < data->c_y2)
		{
			u.c_ratio_s -= u.c_ratio;
			u.color_index++;
			data->c_y1 += data->cgrowth;
		}
		put_pixel_to_image(u.c_x, u.c_y, data, data->colors[data->c_y1]);
		u.ratio_s += 1;
		u.c_ratio_s += 1;
		u.c_x++;
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
			data->c_y1 += cgrowth;
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
			large_angle(p1, p2, data, init_util(p1, p2, 1));
		else
			sharp_angle(p1, p2, data, init_util(p1, p2, 2));
	}
	else if (p2.y < p1.y)
	{
		if ((p1.y - p2.y) > (p2.x - p1.x))
			large_angle(p1, p2, data, init_util(p1, p2, 1));
		else
			sharp_angle(p1, p2, data, init_util(p1, p2, 2));
	}
}
