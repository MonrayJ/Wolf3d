/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 10:38:46 by mjacobs           #+#    #+#             */
/*   Updated: 2018/08/31 12:12:01 by mjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	put_pixel_image(t_mlx *mlx, int x, int y, int c)
{
	int i;

	i = x * (mlx->bpp / 8) + y * mlx->ll;
	if (x >= 0 && x < mlx->scrn_x && y >= 0 && y < mlx->scrn_y)
	{
		mlx->data[i] = c & 0x000000ff;
		mlx->data[i + 1] = (c & 0x0000ff00) / 0x100;
		mlx->data[i + 2] = (c & 0x00ff0000) / 0x10000;
	}
}

void	clear_image(t_mlx *mlx)
{
	int x;
	int y;

	y = -1;
	while (++y < mlx->scrn_y)
	{
		x = -1;
		while (++x < mlx->scrn_x)
			put_pixel_image(mlx, x, y, 0);
	}
}

void	ft_start(t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	while (++y)
	{
		x = 0;
		while (++x < mlx->m_w)
			if (mlx->map[y][x] == -1)
			{
				mlx->start_x = x;
				mlx->start_y = y;
				return ;
			}
		if (y == mlx->m_h - 1)
		{
			ft_putendl("INVALID_MAP: PLAYER_START_UNDEFINED");
			exit(0);
		}
	}
}

void	initial(t_mlx *mlx)
{
	ft_start(mlx);
	mlx->dir_x = 1;
	mlx->dir_y = 1;
	mlx->cplane_x = -0.66;
	mlx->cplane_y = 0.66;
	mlx->scrn_x = 1600;
	mlx->scrn_y = 900;
	mlx->hit = 0;
	mlx->color = 0xcccccc;
	mlx->move = 0.17;
	mlx->rotate = 0.07;
}

int		main(int ac, char **av)
{
	t_mlx	mlx;
	int		fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		ft_get_size(fd, &mlx.m_w, &mlx.m_h);
		close(fd);
		fd = open(av[1], O_RDONLY);
		mlx.map = read_file(fd, mlx.m_h, mlx.m_w);
		initial(&mlx);
		mlx.mlx = mlx_init();
		mlx.win = mlx_new_window(mlx.mlx, mlx.scrn_x, mlx.scrn_y, "Wolf");
		mlx.image = mlx_new_image(mlx.mlx, mlx.scrn_x, mlx.scrn_y);
		mlx.data = (unsigned char*)mlx_get_data_addr(mlx.image,
			&mlx.bpp, &mlx.ll, &mlx.end);
		ray_caster(&mlx);
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.image, 0, 0);
		mlx_hook(mlx.win, 2, 0, hook_keydown, &mlx);
		mlx_hook(mlx.win, 17, 0, my_exit, &mlx);
		mlx_loop(mlx.mlx);
	}
	else
		ft_putendl("Usage: <./Program_Name> <Path_to_Map>");
	return (0);
}
