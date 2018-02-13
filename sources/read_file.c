/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 13:05:40 by axbal             #+#    #+#             */
/*   Updated: 2018/02/13 11:52:08 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		count_dots(char *str)
{
	int		nb;
	int		levier;
	int		i;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		levier = 0;
		if (str[i] != '-' && str[i] != ' ' && str[i] != '\t' &&
		(str[i] > '9' || str[i] < '0'))
			return (-1);
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '-')
		{
			if (str[i] == '-' && ((i == 0 || str[i - 1] != ' ') ||
			(str[i + 1] > '9' || str[i + 1] < '0')))
				return (-1);
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			if (levier == 0)
			{
				nb++;
				levier = 1;
			}
			i++;
		}
	}
	return (nb);
}

int		check_length(char **map, int size)
{
	int		i;
	int		nb;
	int		ret;

	i = 0;
	nb = 0;
	while (i < size)
	{
		ret = count_dots(map[i]);
		if (ret > nb)
			nb = ret;
//		else if (nb != ret)
//			return (-1);
		i++;
	}
	return (nb);
}

int		**split_to_int(char **map, int x, int y)
{
	int		i;
	int		j;
	int		**tab;
	char	*s;
	int		levier;

	i = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * y)))
		ft_error(3);
	while (i < y)
	{
		if (!(tab[i] = (int *)malloc(sizeof(int) * x)))
			ft_error(3);
		i++;
	}
	i = 0;
	while (i < y)
	{
		s = map[i];
		j = 0;
		while (*s != '\0')
		{
			levier = 0;
			while ((*s >= '0' && *s <= '9') || *s == '-')
			{
				if (levier == 0)
				{
					tab[i][j] = ft_atoi(s);
					j++;
					levier = 1;
				}
				s++;
			}
			while ((*s > '9' || *s < '0') && *s != '\0' && *s != '-')
				s++;
		}
		i++;
	}
	return (tab);
}

void	read_dots(int fd, t_data *data)
{
	int		size_x;
	int		size_y;
	int		i;
	char	*line;
	char	**map;

	size_x = 0;
	size_y = 0;
	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * 2048)))
		ft_error(3);
	while (get_next_line(fd, &line) != 0)
	{
		map[i++] = line;
		size_y++;
	}
	if ((size_x = check_length(map, i)) == -1)
		ft_error(1);
	data->size_y = size_y;
	data->size_x = size_x;
	data->dots = NULL;
	data->dots = split_to_int(map, size_x, size_y);
	i = 0;
//	while (i < size_y)
//	{
//		ft_print_nbrs(data->dots[i], size_x);
//		ft_putchar('\n');
//		i++;
//	}
	if (size_y == 0)
		ft_error(1);
}
