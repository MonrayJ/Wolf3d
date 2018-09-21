/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 11:19:57 by mjacobs           #+#    #+#             */
/*   Updated: 2018/08/23 18:00:36 by mjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_get_size(int fd, int *w, int *h)
{
	char	*line;
	char	**str;

	*h = 0;
	while (get_next_line(fd, &line) > 0)
	{
		*w = 0;
		str = ft_strsplit(line, ' ');
		free(line);
		while (str[*w])
		{
			free(str[*w]);
			(*w)++;
		}
		free(str);
		(*h)++;
	}
}

double	**malloc_2d(double **map, int m_h, int m_w)
{
	int		i;

	i = 0;
	map = (double**)malloc(sizeof(double*) * m_h);
	while (i < m_h)
	{
		map[i] = (double*)malloc(sizeof(double) * m_w);
		i++;
	}
	return (map);
}

double	**ft_map(char ***str, int m_h, int m_w)
{
	int		y;
	int		x;
	double	**map;

	map = malloc_2d(map, m_h, m_w);
	y = 0;
	while (y < m_h)
	{
		x = 0;
		while (x < m_w)
		{
			map[y][x] = ft_atoi(str[y][x]);
			free(str[y][x]);
			x++;
		}
		free(str[y]);
		y++;
	}
	free(str);
	return (map);
}

double	**read_file(int fd, int m_h, int m_w)
{
	int		i;
	int		j;
	char	***str;
	char	*line;
	double	**map;

	i = 0;
	str = (char***)malloc(sizeof(char**) * m_h);
	while (get_next_line(fd, &line) > 0)
	{
		str[i++] = ft_strsplit(line, ' ');
		free(line);
	}
	map = ft_map(str, m_h, m_w);
	return (map);
}
