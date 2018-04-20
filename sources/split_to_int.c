/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_to_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 11:45:22 by axbal             #+#    #+#             */
/*   Updated: 2018/04/20 15:37:43 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		**malloc_tab(int x, int y)
{
	int		i;
	int		**tab;

	i = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * y)))
		return (NULL);
	while (i < y)
	{
		if (!(tab[i] = (int *)malloc(sizeof(int) * x)))
			return (NULL);
		i++;
	}
	return (tab);
}

char	*fill_int_tab(int *nb, char *s)
{
	int		levier;

	levier = 0;
	while ((*s >= '0' && *s <= '9') || *s == '-')
	{
		if (levier == 0)
		{
			*nb = ft_atoi(s);
			levier = 1;
		}
		s++;
	}
	return (s);
}

void	fill_tab(int **tab, t_dot *d, char **s, int *levier)
{
	if (*levier == 0)
	{
		tab[d->y][d->x] = ft_atoi(*s);
		d->x++;
		*levier = 1;
	}
	(*s)++;
}

int		**split_to_int(char **map, int x, int y)
{
	t_dot	d;
	int		**tab;
	char	*s;
	int		levier;

	d.y = 0;
	if (!(tab = malloc_tab(x, y)))
		ft_error(4);
	while (d.y < y)
	{
		s = map[d.y];
		d.x = 0;
		while (*s != '\0')
		{
			levier = 0;
			while ((*s >= '0' && *s <= '9') || *s == '-')
				fill_tab(tab, &d, &s, &levier);
			if (*s == ',')
				s += 9;
			while ((*s > '9' || *s < '0') && *s != '\0' && *s != '-')
				s++;
		}
		d.y++;
	}
	return (tab);
}
