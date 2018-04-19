/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 12:11:58 by axbal             #+#    #+#             */
/*   Updated: 2018/04/19 16:54:09 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_coef_gap(int key, t_data *data)
{
	if (key == 33)
	{
		if (COEF_GAP > 1)
			COEF_GAP -= 1;
		else if (COEF_GAP <= 1 && COEF_GAP > 0.1)
			COEF_GAP -= 0.1;
		else if (COEF_GAP <= 0.1 && COEF_GAP > 0.01)
			COEF_GAP -= 0.01;
		else
			ft_putstr("cannot reduce more.\n");
	}
	else if (key == 30)
	{
		if (COEF_GAP >= 1 && COEF_GAP < 10)
			COEF_GAP += 1;
		else if (COEF_GAP < 1 && COEF_GAP > 0.09)
			COEF_GAP += 0.1;
		else if (COEF_GAP < 0.1 && COEF_GAP > 0)
			COEF_GAP += 0.01;
		else
			ft_putstr("cannot raise more.\n");
	}
//	printf("Coef_gap is %lf and coef is %lf\n", COEF_GAP, COEF);
}

void	edit_coef(int key, t_data *data)
{
	if (key == 33 || key == 30)
		get_coef_gap(key, data);
	else
	{
		if (key == 24)
			COEF += COEF_GAP;
		else if (key == 27)
			COEF -= COEF_GAP;
		mlx_destroy_image(MLX, IMG);
		IMG = mlx_new_image(MLX, IMG_W, IMG_H);
		IMG_STR = mlx_get_data_addr(IMG, &BPP, &S_L, &ENDIAN);
		BPP /= 8;
		gen_map(data);
		refresh_expose(data);
	}
}

void	refresh_map_pos(int key, t_data *data)
{
	int		gap_x;
	int		gap_y;
	int		center_x;
	int		center_y;

	center_x = WIN_WIDTH / 2;
	center_y = WIN_HEIGHT / 2;
	gap_x = center_x - IMG_X;
	gap_y = center_y - IMG_Y;
	if (key == 12)
	{
		gap_x *= 2;
		gap_y *= 2;
	}
	if (key == 14)
	{
		gap_x /= 2;
		gap_y /= 2;
	}
	IMG_X = center_x - gap_x;
	IMG_Y = center_y - gap_y;
}

void	rotate(int key, t_data *data)
{
	if (key == 12 && ZOOM < 5)
	{
		GAP_X *= 2;
		GAP_Y *= 2;
		COEF *= 2;
		ZOOM++;
	}
	else if (key == 14 && GAP_X >= 2 && GAP_Y >= 2)
	{
		GAP_X /= 2;
		GAP_Y /= 2;
		COEF /= 2;
		ZOOM--;
	}
	else if (key == 12)
		ft_putstr("Cannot zoom in more\n");
	else if (key == 14)
		ft_putstr("Cannot zoom out more\n");
	reset_image(data);
	gen_map(data);
	refresh_expose(data);
}
