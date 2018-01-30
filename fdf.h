/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 16:38:06 by axbal             #+#    #+#             */
/*   Updated: 2018/01/29 12:46:13 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdlib.h>

# define WIN_HEIGHT 500
# define WIN_WIDTH 800
# define MLX data->mlx_ptr
# define WIN data->win_ptr

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_data;

void	draw_line(int x1, int y1, int x2, int y2, t_data *data);

#endif
