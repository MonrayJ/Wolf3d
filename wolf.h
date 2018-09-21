/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjacobs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 11:53:16 by mjacobs           #+#    #+#             */
/*   Updated: 2018/08/27 11:55:00 by mjacobs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "get_next_line/get_next_line.h"

# define ABS(x)		(((x) < 0) ? -(x) : (x))
# define POS_NEG(x)	(((x) < 0) ? -1 : 1)

typedef struct	s_mlx
{
	double			raydir_x;
	double			raydir_y;
	double			side_x;
	double			side_y;
	double			dlta_x;
	double			dlta_y;
	double			perp_wall;
	int				side;

	double			start_x;
	double			start_y;
	double			dir_x;
	double			dir_y;
	double			o_dir_x;
	double			cplane_x;
	double			cplane_y;
	double			camera_x;

	int				box_x;
	int				box_y;
	int				step_x;
	int				step_y;

	int				hit;

	int				line_h;
	int				draw_start;
	int				draw_end;
	int				color;

	double			move;
	double			rotate;

	int				scrn_x;
	int				scrn_y;
	int				m_h;
	int				m_w;

	void			*mlx;
	void			*win;
	double			**map;
	void			*image;
	unsigned char	*data;
	int				bpp;
	int				ll;
	int				end;
}				t_mlx;

void			ft_start(t_mlx *mlx);
void			initial(t_mlx *mlx);
void			ft_get_size(int fd, int *w, int *h);
double			**malloc_2d(double **map, int m_hm, int m_w);
double			**ft_map(char ***str, int m_h, int m_w);
double			**read_file(int fd, int m_h, int m_w);
void			ft_raydir(t_mlx *mlx);
void			ft_abs(t_mlx *mlx);
void			ft_step_side(t_mlx *mlx);
void			ft_dda(t_mlx *mlx);
void			ft_perp_dist(t_mlx *mlx);
void			ft_draw_range(t_mlx *mlx);
void			ft_verline(t_mlx *mlx, int x);
void			ft_caster(t_mlx *mlx);
void			ft_forward(t_mlx *mlx);
void			ft_backward(t_mlx *mlx);
void			ft_right(t_mlx *mlx);
void			ft_left(t_mlx *mlx);
void			ray_caster(t_mlx *mlx);
int				hook_keydown(int key, t_mlx *mlx);
int				my_exit(int key, t_mlx *mlx);
void			clear_image(t_mlx *mlx);
void			put_pixel_image(t_mlx *mlx, int x, int y, int c);

#endif
