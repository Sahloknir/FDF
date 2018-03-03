/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 16:38:06 by axbal             #+#    #+#             */
/*   Updated: 2018/03/03 17:45:38 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define WIN_HEIGHT data->win_h
# define WIN_WIDTH data->win_w
# define MLX data->mlx_ptr
# define WIN data->win_ptr

# define XO data->x0
# define YO data->y0
# define GAP_Y data->gap_y
# define GAP_X data->gap_x
# define COEF data->coef

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				**dots;
	int				size_x;
	int				size_y;
	int				win_h;
	int				win_w;
	int				gap_y;
	int				gap_x;
	int				x0;
	int				y0;
	float			coef;
	int				*colors;
	int				decal;
	int				range;
	int				c_y1;
	int				c_y2;
	int				cgrowth;
	int				nocolor;
}					t_data;

void	draw_line(int x1, int y1, int x2, int y2, t_data *data);
void	read_dots(int fd, t_data *data);
void	ft_error(int error);
void	gen_map(t_data *data);
void	size_map(t_data *data);
void	gen_colors(t_data *data);
void	color_set(t_data *data, int c_y1, int c_y2);
void	get_options(t_data *data, char **input, int argc);

#endif
