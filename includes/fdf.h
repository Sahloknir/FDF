/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 16:38:06 by axbal             #+#    #+#             */
/*   Updated: 2018/03/05 16:28:44 by axbal            ###   ########.fr       */
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
# define IMG data->img
# define IMG_STR data->img_str
# define BPP data->bpp
# define S_L data->s_l
# define ENDIAN data->endian
# define IMG_X data->img_x
# define IMG_Y data->img_y
# define IMG_W data->img_w
# define IMG_H data->img_h

# define XO data->x0
# define YO data->y0
# define GAP_Y data->gap_y
# define GAP_X data->gap_x
# define COEF data->coef

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
	int				alpha;
}					t_color;

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				**dots;
	void			*img;
	char			*img_str;
	int				bpp;
	int				s_l;
	int				endian;
	int				img_x;
	int				img_y;
	int				img_h;
	int				img_w;
	int				max_val;
	int				max_x;
	int				max_y;
	int				min_val;
	int				min_x;
	int				min_y;
	int				size_x;
	int				size_y;
	int				win_h;
	int				win_w;
	int				gap_y;
	int				gap_x;
	int				x0;
	int				y0;
	float			coef;
	t_color			*colors;
	int				decal;
	int				range;
	int				c_y1;
	int				c_y2;
	int				cgrowth;
	int				nocolor;
	int				controls;
}					t_data;

void	draw_line(int x1, int y1, int x2, int y2, t_data *data);
void	read_dots(int fd, t_data *data);
void	ft_error(int error);
void	gen_map(t_data *data);
void	size_map(t_data *data);
void	gen_colors(t_data *data);
void	color_set(t_data *data, int c_y1, int c_y2);
void	get_options(t_data *data, char **input, int argc);
void	put_pixel_to_image(int x, int y, t_data *data, t_color color);
void	show_controls(t_data *data, int mode);
void	move_img(int key, t_data *data);
int		refresh_expose(t_data *data);
void	edit_coef(int key, t_data *data);

#endif
