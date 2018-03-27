/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axbal <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 15:34:03 by axbal             #+#    #+#             */
/*   Updated: 2018/03/10 18:31:26 by axbal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*cat_buff(char *save, char *buf)
{
	char	*tmp;

	tmp = ft_strdup(save);
	free(save);
	if (!(save = (char *)malloc(sizeof(char)
		* (ft_strlen(tmp) + ft_strlen(buf) + 1))))
		return (NULL);
	save = ft_strcpy(save, tmp);
	free(tmp);
	save = ft_strcat(save, buf);
	return (save);
}

int		find_line(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

int		fill_line(char **save, char **line, int mode)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*save)[i] != '\n' && (*save)[i] != '\0')
		i++;
	if (!(*line = (char *)malloc(sizeof(char) * (i + 1))))
		return (-1);
	*line = ft_strncpy(*line, *save, i);
	(*line)[i] = '\0';
	if (mode == 1 || mode == 2)
	{
		tmp = ft_strdup(*save + i + 1);
		ft_bzero(*save, ft_strlen(*save));
		*save = ft_strcpy(*save, tmp);
		free(tmp);
	}
	if (mode == 2 || mode == 3)
		ft_bzero(*save, ft_strlen(*save));
	if (mode == 3)
		*line = "";
	if (mode != 3)
		return (1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char			*buf;
	static char		*save;
	int				ret;
	int				stop;

	if ((fd < 3 && fd != 0) || !line
		|| !(buf = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	stop = find_line(save);
	while (stop == 0 && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		save = save ? cat_buff(save, buf) : ft_strdup(buf);
		stop = find_line(save);
	}
	free(buf);
	if (ret == -1)
		return (-1);
	else if (stop == 1)
		return (fill_line(&save, line, 1));
	else if (ft_strlen(save) > 0)
		return (fill_line(&save, line, 2));
	return (fill_line(&save, line, 3));
}
