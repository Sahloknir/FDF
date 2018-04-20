/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:51:38 by axbal             #+#    #+#             */
/*   Updated: 2018/04/20 16:22:32 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

t_util		init_util(t_dot p1, t_dot p2, int mode)
{
	t_util		u;

	if (mode == 1)
	{
		u.ratio = p2.y < p1.y ? (float)(p1.y - p2.y) / (p2.x - p1.x) :
		(float)(p2.y - p1.y) / (p2.x - p1.x);
	}
	else
	{
		u.ratio = p2.y < p1.y ? (float)(p2.x - p1.x) / (p1.y - p2.y) :
		(float)(p2.x - p1.x) / (p2.y - p1.y);
	}
	u.ratio_s = 1;
	u.c_x = p1.x;
	u.c_y = p1.y;
	u.growth = p2.y < p1.y ? -1 : 1;
	u.c_ratio = 0;
	u.c_ratio_s = 1;
	u.color_index = 1;
	return (u);
}
