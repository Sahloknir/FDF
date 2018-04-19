/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 13:05:40 by axbal             #+#    #+#             */
/*   Updated: 2018/04/19 16:50:25 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		count_dots(char *str, int nb, int i)
{
	int		levier;

	while (str[i] != '\0')
	{
		levier = 0;
		if (str[i] != '-' && str[i] != ' ' && str[i] != '\t' &&
		(str[i] > '9' || str[i] < '0'))
			return (-1);
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		while (str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
		{
			if (levier == 0)
			{
				nb++;
				levier = 1;
			}
			i++;
		}
		if (str[i] == ',')
			i += 9;
	}
	return (nb);
}

int		check_length(char **map, int size)
{
	int		i;
	int		nb;
	int		ret;

	i = 0;
	nb = -1;
	while (i < size)
	{
		ret = count_dots(map[i], 0, 0);
		if (nb == -1)
			nb = ret;
		else if (ret != nb)
			return (-1);
		i++;
	}
	return (nb);
}

void	read_dots(int fd, t_data *data, int i)
{
	int		size_x;
	int		size_y;
	char	*line;
	char	**map;
	int		ret;

	size_x = 0;
	size_y = 0;
	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * 2048)))
		ft_error(4);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		map[i++] = line;
		size_y++;
		if (size_y == 2048)
			ft_error(4);
	}
	if (size_y == 0)
		ft_error(1);
	if ((size_x = check_length(map, i)) == -1)
		ft_error(1);
	data->size_y = size_y;
	data->size_x = size_x;
	data->dots = split_to_int(map, size_x, size_y);
}
