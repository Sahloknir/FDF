/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:51:38 by axbal             #+#    #+#             */
/*   Updated: 2018/04/21 16:25:10 by axbal            ###   ########.fr       */
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

void		win_size_error(void)
{
	ft_putstr("size must be between 100 and 2000 and separated by ':'\n");
	ft_error(2);
}

void		get_win_size(t_data *data, char *input)
{
	int		i;
	int		nb;

	i = 0;
	nb = ft_atoi(input + 5);
	if (nb < 100 || nb > 2000)
		win_size_error();
	WIN_WIDTH = nb;
	while (input[i] != '\0' && input[i] != ':')
		i++;
	if (input[i] != ':')
		win_size_error();
	else
	{
		nb = ft_atoi(input + i + 1);
		if (nb < 100 || nb > 2000)
			win_size_error();
		else
			WIN_HEIGHT = nb;
	}
}
