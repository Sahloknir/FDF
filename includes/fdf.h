/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 16:38:06 by axbal             #+#    #+#             */
/*   Updated: 2018/02/13 14:30:42 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define WIN_HEIGHT 800
# define WIN_WIDTH 1200
# define MLX data->mlx_ptr
# define WIN data->win_ptr

# define XO 100
# define YO 80
# define GAP_Y 8
# define GAP_X 40
# define COEF 4

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				**dots;
	int				size_x;
	int				size_y;
}					t_data;

void	draw_line(int x1, int y1, int x2, int y2, t_data *data);
void	read_dots(int fd, t_data *data);
int		ft_error(int error);
void	gen_map(t_data *data);

#endif
