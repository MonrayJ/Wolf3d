/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 12:59:03 by mjacobs           #+#    #+#             */
/*   Updated: 2018/08/27 11:55:22 by mjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
**	LINE_FUNCTION DETERMINE_HIT.
*/

void	ft_dda(t_mlx *mlx)
{
	if (mlx->side_x < mlx->side_y)
	{
		mlx->side_x += mlx->dlta_x;
		mlx->box_x += mlx->step_x;
		mlx->side = 0;
	}
	else
	{
		mlx->side_y += mlx->dlta_y;
		mlx->box_y += mlx->step_y;
		mlx->side = 1;
	}
	if (mlx->map[mlx->box_y][mlx->box_x] > 0)
		mlx->hit = 1;
}

/*
**	DISTANCE_PROJECTED_ON_CAMERA.
*/

void	ft_perp_dist(t_mlx *mlx)
{
	mlx->perp_wall = (mlx->side == 0) ? (mlx->box_x - mlx->start_x +
			(1 - mlx->step_x) / 2) / mlx->raydir_x :
		(mlx->box_y - mlx->start_y + (1 - mlx->step_y) / 2) / mlx->raydir_y;
}

/*
**	CALCULATE_DRAWING_RANGE.
*/

void	ft_draw_range(t_mlx *mlx)
{
	mlx->draw_start = (mlx->line_h * -1) / 2 + mlx->scrn_y / 2;
	if (mlx->draw_start < 0)
		mlx->draw_start = 0;
	mlx->draw_end = mlx->line_h / 2 + mlx->scrn_y / 2;
	if (mlx->draw_end >= mlx->scrn_y)
		mlx->draw_end = mlx->scrn_y - 1;
}

void	ft_sky(t_mlx *mlx, int y, int x)
{
	if (mlx->map[mlx->box_y][mlx->box_x] > 2)
		if (y <= mlx->scrn_y / 2)
			put_pixel_image(mlx, x, y, 0x4e8296);
	if (mlx->map[mlx->box_y][mlx->box_x] > 2)
		if (y > mlx->scrn_y / 2)
			put_pixel_image(mlx, x, y, 0x7d5442);
	if (y < mlx->draw_start)
		put_pixel_image(mlx, x, y, 0x4e8296);
	if (y > mlx->draw_end)
		put_pixel_image(mlx, x, y, 0x7d5442);
	else
	{
		if (y <= mlx->scrn_y / 2 && y != mlx->draw_start)
			put_pixel_image(mlx, x, y, 0x4e8296);
		else if (y > mlx->scrn_y / 2 && y != mlx->draw_end)
			put_pixel_image(mlx, x, y, 0x7d5442);
	}
}

void	ft_verline(t_mlx *mlx, int x)
{
	int y;

	y = -1;
	while (++y <= mlx->scrn_y)
	{
		ft_sky(mlx, y, x);
		if (y > mlx->draw_start && y < mlx->draw_end)
		{
			if (mlx->map[mlx->box_y][mlx->box_x] == 1 && mlx->side == 1)
				put_pixel_image(mlx, x, y, mlx->color / 2);
			else if (mlx->map[mlx->box_y][mlx->box_x] == 1 && mlx->side == 0)
				put_pixel_image(mlx, x, y, mlx->color / 1.5);
			if (mlx->map[mlx->box_y][mlx->box_x] == 2 && mlx->side == 1)
				put_pixel_image(mlx, x, y, 0x665764);
			else if (mlx->map[mlx->box_y][mlx->box_x] == 2 && mlx->side == 0)
				put_pixel_image(mlx, x, y, 0x8c778b);
		}
	}
}
