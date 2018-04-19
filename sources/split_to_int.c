/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_to_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 11:45:22 by axbal             #+#    #+#             */
/*   Updated: 2018/04/19 16:50:34 by axbal            ###   ########.fr       */
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

char	*skip_hex(char *s)
{
	while (*s != ' ' && *s != '\0')
		s++;
	return (s);
}

int		**split_to_int(char **map, int x, int y)
{
	int		i;
	int		j;
	int		**tab;
	char	*s;
	int		levier;

	i = 0;
	if (!(tab = malloc_tab(x, y)))
		ft_error(4);
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
			if (*s == ',')
				s += 9;
			while ((*s > '9' || *s < '0') && *s != '\0' && *s != '-')
				s++;
		}
		i++;
	}
	return (tab);
}
