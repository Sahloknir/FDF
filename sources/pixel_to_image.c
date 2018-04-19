/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_to_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 00:52:25 by axbal             #+#    #+#             */
/*   Updated: 2018/04/19 16:33:58 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	put_pixel_to_image(int x, int y, t_data *data, t_color color)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		IMG_STR[(x * BPP) + (y * S_L) + 0] = (char)color.b;
		IMG_STR[(x * BPP) + (y * S_L) + 1] = (char)color.g;
		IMG_STR[(x * BPP) + (y * S_L) + 2] = (char)color.r;
		IMG_STR[(x * BPP) + (y * S_L) + 3] = (char)color.alpha;
	}
}
