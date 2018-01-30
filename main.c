/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 16:40:19 by axbal             #+#    #+#             */
/*   Updated: 2018/01/29 14:23:31 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_data *data)
{
	int		x;
	int		y;
	int		current_x;
	int		current_y;
	int		color;

	color = 0x0000FF;
	x = (WIN_WIDTH / 2) - 50;
	y = (WIN_HEIGHT / 2) - 50;
	current_x = 0;
	current_y = 0;
	while (current_x < 100)
	{
		if (current_x == 34)
			color = 0xFFFFFF;
		if (current_x == 67)
			color = 0xFF0000;
		while (current_y < 100)
		{
			mlx_pixel_put(MLX, WIN, (x + current_x), (y + current_y), color);
			current_y++;
		}
		current_x++;
		current_y = 0;
	}
}

int		print_key(int key, void *param)
{
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

	if (argc == 1)
		return (0);
	data = global_init(argv[1]);
	mlx_key_hook(WIN, print_key, (void *)0);
//	draw(data);
	draw_line(400, 250, 410, 100, data);
	draw_line(400, 250, 450, 150, data);
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
