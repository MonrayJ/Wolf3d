/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 16:18:15 by mjacobs           #+#    #+#             */
/*   Updated: 2018/08/31 12:07:33 by mjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_forward(t_mlx *mlx)
{
	if (mlx->start_y > 0 && mlx->start_x > 0 && mlx->start_x < mlx->m_w &&
			mlx->start_y < mlx->m_h)
	{
		if (mlx->map[(int)(mlx->start_y)][(int)(mlx->start_x + mlx->dir_x
				* mlx->move)] < 1)
			mlx->start_x += mlx->dir_x * mlx->move;
		if (mlx->map[(int)(mlx->start_y + mlx->dir_y
					* mlx->move)][(int)(mlx->start_x)] < 1)
			mlx->start_y += mlx->dir_y * mlx->move;
	}
}

void	ft_backward(t_mlx *mlx)
{
	if (mlx->start_y > 0 && mlx->start_x > 0 && mlx->start_x < mlx->m_w &&
			mlx->start_y < mlx->m_h)
	{
		if (mlx->map[(int)(mlx->start_y)][(int)(mlx->start_x - mlx->dir_x
					* mlx->move)] < 1)
			mlx->start_x -= mlx->dir_x * mlx->move;
		if (mlx->map[(int)(mlx->start_y - mlx->dir_y
					* mlx->move)][(int)(mlx->start_x)] < 1)
			mlx->start_y -= mlx->dir_y * mlx->move;
	}
}

void	ft_right(t_mlx *mlx)
{
	double o_dir_x;
	double o_cplane_x;

	o_cplane_x = mlx->cplane_x;
	o_dir_x = mlx->dir_x;
	mlx->dir_x = mlx->dir_x * cos(-mlx->rotate) - mlx->dir_y
		* sin(-mlx->rotate);
	mlx->dir_y = o_dir_x * sin(-mlx->rotate) + mlx->dir_y
		* cos(-mlx->rotate);
	mlx->cplane_x = mlx->cplane_x * cos(-mlx->rotate) - mlx->cplane_y
		* sin(-mlx->rotate);
	mlx->cplane_y = o_cplane_x * sin(-mlx->rotate) + mlx->cplane_y
		* cos(-mlx->rotate);
}

void	ft_left(t_mlx *mlx)
{
	double o_dir_x;
	double o_cplane_x;

	o_cplane_x = mlx->cplane_x;
	o_dir_x = mlx->dir_x;
	mlx->dir_x = mlx->dir_x * cos(mlx->rotate) - mlx->dir_y
		* sin(mlx->rotate);
	mlx->dir_y = o_dir_x * sin(mlx->rotate) + mlx->dir_y
		* cos(mlx->rotate);
	mlx->cplane_x = mlx->cplane_x * cos(mlx->rotate) - mlx->cplane_y
		* sin(mlx->rotate);
	mlx->cplane_y = o_cplane_x * sin(mlx->rotate) + mlx->cplane_y
		* cos(mlx->rotate);
}

int		hook_keydown(int key, t_mlx *mlx)
{
	clear_image(mlx);
	(void)mlx;
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 13 || key == 126)
		ft_forward(mlx);
	if (key == 1 || key == 125)
		ft_backward(mlx);
	if (key == 0 || key == 123)
		ft_right(mlx);
	if (key == 2 || key == 124)
		ft_left(mlx);
	ray_caster(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image, 0, 0);
	return (0);
}
