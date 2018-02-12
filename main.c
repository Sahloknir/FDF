/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 16:40:19 by axbal             #+#    #+#             */
/*   Updated: 2018/02/12 16:04:36 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	draw_circle(int x0, int y0, int radius, t_data *data)
{
	int		color;
	int		x;
	int		y;
	int		d;

	x = 0;
	y = radius;
	d = y - 1;
	color = 0x0000FF;
	while (y >= x)
	{
		mlx_pixel_put(MLX, WIN, x0 + x, y0 + y, color);
		mlx_pixel_put(MLX, WIN, x0 + y, y0 + x, color);
		mlx_pixel_put(MLX, WIN, x0 - x, y0 + y, color);
		mlx_pixel_put(MLX, WIN, x0 - y, y0 + x, color);
		mlx_pixel_put(MLX, WIN, x0 + x, y0 - y, color);
		mlx_pixel_put(MLX, WIN, x0 + y, y0 - x, color);
		mlx_pixel_put(MLX, WIN, x0 - x, y0 - y, color);
		mlx_pixel_put(MLX, WIN, x0 - y, y0 - x, color);
		if (d > 2 * x)
		{
			d -= 2 * x + 1;
			x++;
		}
		else if (d < 2 * (radius - y))
		{
			d += 2 * y - 1;
			y--;
		}
		else
		{
			d += 2 * (y - x - 1);
			y--;
			x++;
		}
	}
}

int		print_key(int key, void *param)
{
	param = 0;
	if (key == 12)
		exit(0);
	ft_putnbr(key);
	return (0);
}

int		ft_error(int error)
{
	if (error == 0)
		ft_putstr("usage : ./fdf <filename>\n");
	if (error == 1)
		ft_putstr("incorrect file\n");
	if (error < 3)
		exit(1);
	return (0);
}

t_data	*global_init(char *name, int fd)
{
	t_data	*data;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIN_WIDTH, WIN_HEIGHT, name);
	read_dots(fd, data);
	return (data);
}

int		main(int argc, char **argv)
{
	t_data	*data;
	int		fd;

	if (argc != 2)
		return (ft_error(0));
	fd = open(argv[1], O_RDONLY);
	if (fd < 3 && fd != 1)
		ft_error(1);
	data = global_init("fdf", fd);
	mlx_key_hook(WIN, print_key, (void *)0);
	gen_map(data);
//	draw_circle(400, 250, 200, data);
//	draw_line(100, 100, 120, 115, data);
//	draw_line(85, 120, 100, 100, data);
//	draw_line(105, 135, 120, 115, data);
//	draw_line(85, 120, 105, 135, data);
	mlx_loop(MLX);
	return (0);
}
