/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 16:40:19 by axbal             #+#    #+#             */
/*   Updated: 2018/03/27 11:17:11 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		refresh_expose(t_data *data)
{
	mlx_clear_window(MLX, WIN);
	mlx_put_image_to_window(MLX, WIN, IMG, IMG_X, IMG_Y);
	if (data->controls == 1)
		show_controls(data, 1);
	return (0);
}

int		redirect_key(int key, t_data *data)
{
	if (key == 53)
		exit(0);
	else if (key >= 123 && key <= 126)
		move_img(key, data);
	else if (key == 8)
		show_controls(data, 0);
	else if (key == 24 || key == 27 || key == 30 || key == 33)
		edit_coef(key, data);
	else if (key == 12 || key == 14)
		rotate(key, data);
	ft_putnbr(key);
	return (0);
}

void	ft_error(int error)
{
	if (error == 0)
		ft_putstr("usage : ./fdf <filename>\n");
	if (error == 1)
		ft_putstr("incorrect file\n");
	if (error == 2)
		ft_putstr("invalid option\n");
	if (error == 3)
		ft_putstr("cannot find this file\n");
	exit(1);
}

t_data	*global_init(char **argv, int fd, int argc)
{
	t_data	*data;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	data->coef = 1;
	data->coef_gap = 1;
	data->nocolor = 0;
	data->controls = -1;
	data->gap_x = 0;
	WIN_WIDTH = 0;
	WIN_HEIGHT = 0;
	IMG_X = 0;
	IMG_Y = 0;
	read_dots(fd, data, 0);
	get_options(data, argv, argc);
	gen_colors(data);
	size_map(data);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIN_WIDTH, WIN_HEIGHT, argv[1]);
	IMG = mlx_new_image(MLX, IMG_W, IMG_H);
	IMG_STR = mlx_get_data_addr(IMG, &BPP, &S_L, &ENDIAN);
	BPP = BPP / 8;
	gen_map(data);
	return (data);
}

int		main(int argc, char **argv)
{
	t_data	*data;
	int		fd;

	if (argc < 2)
		ft_error(0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 3 && fd != 0)
		ft_error(3);
	data = global_init(argv, fd, argc);
	mlx_key_hook(WIN, redirect_key, data);
	mlx_expose_hook(WIN, refresh_expose, data);
	mlx_loop(MLX);
	return (0);
}