/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:37:51 by mjacobs           #+#    #+#             */
/*   Updated: 2018/07/16 09:03:14 by mjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_read(int const fd, char **line)
{
	char	*buff;
	int		i;
	char	*temp;

	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	i = read(fd, buff, BUFF_SIZE);
	if (i > 0)
	{
		buff[i] = 0;
		if (!(temp = ft_strjoin(*line, buff)))
			return (-1);
		free(*line);
		*line = temp;
		free(buff);
	}
	if (i == 0)
		free(buff);
	return (i);
}

int				get_next_line(int const fd, char **line)
{
	static char	*temp;
	char		*temp2;
	int			i;

	if (!temp && (!(temp = ft_strnew(BUFF_SIZE))))
		return (-1);
	if (fd < 0 || BUFF_SIZE < 1)
		return (-1);
	temp2 = ft_strchr(temp, '\n');
	while (!temp2)
	{
		i = ft_read(fd, &temp);
		if (i == 0 && !ft_strlen(temp))
			return (0);
		if (i == 0)
			ft_strcat(temp, "\n");
		if (i < 0)
			return (-1);
		temp2 = ft_strchr(temp, '\n');
	}
	if (!(*line = ft_strsub(temp, 0, ft_strlen(temp) - ft_strlen(temp2))))
		return (-1);
	ft_strcpy(temp, temp2 + 1);
	return (1);
}
