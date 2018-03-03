/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 16:40:19 by axbal             #+#    #+#             */
/*   Updated: 2018/03/03 18:45:34 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int		print_key(int key, void *param)
{
	param = 0;
	if (key == 53)
		exit(0);
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
	exit(1);
}

t_data	*global_init(char **argv, int fd, int argc)
{
	t_data	*data;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	data->coef = 2;
	data->nocolor = 0;
	data->gap_x = 0;
	WIN_WIDTH = 0;
	WIN_HEIGHT = 0;
	get_options(data, argv, argc);
	read_dots(fd, data);
	size_map(data);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIN_WIDTH, WIN_HEIGHT, argv[1]);
	return (data);
}

int		main(int argc, char **argv)
{
	t_data	*data;
	int		fd;

	if (argc < 2)
		ft_error(0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 3 && fd != 1)
		ft_error(1);
	data = global_init(argv, fd, argc);
	gen_colors(data);
	gen_map(data);
	mlx_key_hook(WIN, print_key, (void *)0);
	mlx_loop(MLX);
	return (0);
}
