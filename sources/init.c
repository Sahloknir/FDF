/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:38:52 by axbal             #+#    #+#             */
/*   Updated: 2018/04/20 15:39:10 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_data	*global_init(char **argv, int fd, int argc)
{
	t_data	*data;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	data->coef = 1;
	data->coef_gap = 1;
	data->nocolor = 0;
	data->controls = 1;
	data->gap_x = 0;
	WIN_WIDTH = 0;
	WIN_HEIGHT = 0;
	IMG_X = 0;
	IMG_Y = 0;
	ZOOM = 0;
	read_dots(fd, data, 0);
	get_options(data, argv, argc);
	gen_colors(data);
	size_map(data);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIN_WIDTH, WIN_HEIGHT, "FDF");
	IMG = mlx_new_image(MLX, IMG_W, IMG_H);
	IMG_STR = mlx_get_data_addr(IMG, &BPP, &S_L, &ENDIAN);
	BPP = BPP / 8;
	return (data);
}
