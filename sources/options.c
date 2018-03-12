/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 00:59:30 by axbal             #+#    #+#             */
/*   Updated: 2018/03/09 16:49:07 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_coef(char *str, t_data *data)
{
	int		size;
	int		i;

	size = 1;
	if (str[0] > '9' || str[0] < '0')
		ft_error(2);
	if (ft_strncmp(str, "0.", 2) == 0)
	{
		i = 2;
		while (str[i])
		{
			i++;
			size = size * 10;
		}
		data->coef = ft_atoi(str + 2);
		data->coef = data->coef / size;
	}
	else
		data->coef = ft_atoi(str);
}

int		ft_isnum(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (-1);
		i++;
	}
	return (1);
}

void	move_img(int key, t_data *data)
{
	if (key == 124)
		IMG_X -= 10;
	else if (key == 123)
		IMG_X += 10;
	else if (key == 126)
		IMG_Y += 10;
	else if (key == 125)
		IMG_Y -= 10;
	refresh_expose(data);
}

void	show_controls(t_data *data, int mode)
{
	if (mode == 0)
	{
		data->controls *= -1;
		refresh_expose(data);
	}
	else
	{
		mlx_string_put(MLX, WIN, 5, 1, 0xBBBBBB, "press 'c' to hide controls");
		mlx_string_put(MLX, WIN, 5, 21, 0xBBBBBB, "Use arrow keys to move");
		mlx_string_put(MLX, WIN, 5, 41, 0xBBBBBB,
		"Use '+' and '-' to change the map height");
		mlx_string_put(MLX, WIN, 5, 61, 0xBBBBBB,
		"change the calibration with '[' and ']'");
	}
}

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
	printf("Coef_gap is %lf and coef is %lf\n", COEF_GAP, COEF);
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
	if (key == 12)
	{
		GAP_X *= 2;
		COEF *= 2;
	}
	else if (key == 14 && GAP_X > 5)
	{
		GAP_X /= 2;
		COEF /= 2;
	}
	GAP_Y = GAP_X / 5;
	if (GAP_Y == 0)
		GAP_Y = 1;
	mlx_destroy_image(MLX, IMG);
//	refresh_map_pos(key, data);
	IMG_W = (GAP_X * data->size_x) + (GAP_Y * data->size_y) + 30;
	IMG_H = (GAP_X * data->size_y) + (GAP_Y * data->size_x) + 50;
	IMG = mlx_new_image(MLX, IMG_W, IMG_H);
	IMG_STR = mlx_get_data_addr(IMG, &BPP, &S_L, &ENDIAN);
	BPP /= 8;
	gen_map(data);
	refresh_expose(data);
}

void	get_options(t_data *data, char **input, int argc)
{
	int		i;

	i = 2;
	if (argc >= 4 && ft_isnum(input[2]) == 1 && ft_isnum(input[3]) == 1)
	{
		WIN_WIDTH = ft_atoi(input[2]);
		WIN_HEIGHT = ft_atoi(input[3]);
		i = 4;
	}
	while (i < argc)
	{
		if (ft_strcmp(input[i], "-nocolor") == 0)
			data->nocolor = 1;
		else if (ft_strncmp(input[i], "-coef", 5) == 0)
			get_coef(input[i] + 5, data);
		else if (ft_strncmp(input[i], "-size", 5) == 0)
			data->gap_x = ft_atoi(input[i] + 5);
		else
			ft_error(2);
		i++;
	}
}
