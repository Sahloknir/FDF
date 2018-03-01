/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 00:59:30 by axbal             #+#    #+#             */
/*   Updated: 2018/03/01 16:04:03 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_coef(char *str, t_data *data)
{
	int		size;
	int		i;

	size = 1;
	if (str[0] > '9' || str[0] < '0')
		ft_error(2);
	if (ft_strncmp(str, "0.", 2) == 0)
	{
		i = 2;
		while (str[i])
		{
			i++;
			size = size * 10;
		}
		data->coef = ft_atoi(str + 2);
		data->coef = data->coef / size;
	}
	else
		data->coef = ft_atoi(str);
}

void	get_options(t_data *data, char *input)
{
	if (ft_strcmp(input, "-nocolor") == 0)
		data->nocolor = 1;
	else if (ft_strncmp(input, "-coef", 5) == 0)
		get_coef(input + 5, data);
	else
		ft_error(2);
}
