/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 00:59:30 by axbal             #+#    #+#             */
/*   Updated: 2018/03/05 16:40:00 by axbal            ###   ########.fr       */
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
	if (key == 123)
		IMG_X -= 10;
	else if (key == 124)
		IMG_X += 10;
	else if (key == 125)
		IMG_Y += 10;
	else if (key == 126)
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
		mlx_string_put(MLX, WIN, 50, 50, 0xFFFFFF, "Henlo Fren !");
	}
}

void	edit_coef(int key, t_data *data)
{
	if (key == 24)
		COEF += 0.1;
	else if (key == 27)
		COEF -= 0.1;
	mlx_destroy_image(MLX, IMG);
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
