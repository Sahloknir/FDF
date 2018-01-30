/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 16:40:19 by axbal             #+#    #+#             */
/*   Updated: 2018/01/30 15:00:29 by axbal            ###   ########.fr       */
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

t_data	*global_init(char *name)
{
	t_data	*data;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIN_WIDTH, WIN_HEIGHT, name);
	return (data);
}

int		main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 1)
		return (0);
	argv = 0;
	data = global_init("test");
	mlx_key_hook(WIN, print_key, (void *)0);
//	draw_circle(400, 250, 200, data);
	draw_line(400, 250, 410, 100, data);
	draw_line(400, 250, 450, 150, data);
	draw_line(100, 250, 700, 250, data);
	draw_line(400, 100, 400, 400, data);
	draw_line(400, 250, 600, 200, data);
	draw_line(400, 250, 700, 220, data);
	draw_line(400, 250, 600, 270, data);
	draw_line(400, 250, 450, 350, data);
	draw_line(400, 250, 410, 400, data);
	draw_line(400, 250, 200, 100, data);
	draw_line(400, 250, 150, 200, data);
	draw_line(400, 250, 100, 270, data);
	draw_line(400, 250, 300, 400, data);
	mlx_loop(MLX);
	return (0);
}
