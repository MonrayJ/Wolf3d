/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 12:47:58 by mjacobs           #+#    #+#             */
/*   Updated: 2018/08/27 11:55:28 by mjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
**	RAY_DIRECTION.
*/

void	ft_raydir(t_mlx *mlx)
{
	mlx->raydir_x = mlx->dir_x + mlx->cplane_x * mlx->camera_x;
	mlx->raydir_y = mlx->dir_y + mlx->cplane_y * mlx->camera_x;
}

/*
**	LENGTH_FROM ONE_SIDE TO_NEXT_SIDE.
*/

void	ft_abs(t_mlx *mlx)
{
	mlx->dlta_x = ABS(1 / mlx->raydir_x);
	mlx->dlta_y = ABS(1 / mlx->raydir_y);
}

/*
**	CALCULATE_STEP AND INITIAL_SIDEDIST.
*/

void	ft_step_side(t_mlx *mlx)
{
	mlx->step_x = POS_NEG(mlx->raydir_x);
	mlx->side_x = ((mlx->raydir_x < 0) ? ((mlx->start_x - mlx->box_x) *
				mlx->dlta_x) : (mlx->box_x + 1.0 - mlx->start_x) * mlx->dlta_x);
	mlx->step_y = POS_NEG(mlx->raydir_y);
	mlx->side_y = ((mlx->raydir_y < 0) ? ((mlx->start_y - mlx->box_y) *
				mlx->dlta_y) : (mlx->box_y + 1.0 - mlx->start_y) * mlx->dlta_y);
}

void	ray_caster(t_mlx *mlx)
{
	int		x;

	x = -1;
	while (++x <= mlx->scrn_x)
	{
		mlx->hit = 0;
		mlx->camera_x = 2 * (double)x / (double)mlx->scrn_x - 1;
		ft_raydir(mlx);
		mlx->box_x = (int)mlx->start_x;
		mlx->box_y = (int)mlx->start_y;
		ft_abs(mlx);
		ft_step_side(mlx);
		while (mlx->hit == 0 && mlx->box_x < mlx->m_w - 1 && mlx->box_x > 0 &&
				mlx->box_y < mlx->m_h - 1 && mlx->box_y > 0)
			ft_dda(mlx);
		ft_perp_dist(mlx);
		mlx->line_h = (int)(mlx->scrn_y / mlx->perp_wall);
		ft_draw_range(mlx);
		ft_verline(mlx, x);
	}
}

int		my_exit(int key, t_mlx *mlx)
{
	(void)key;
	(void)mlx;
	exit(EXIT_SUCCESS);
}
