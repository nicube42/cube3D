/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:27:51 by ndiamant          #+#    #+#             */
/*   Updated: 2023/11/09 13:47:29 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_ray_direction(t_rc *rc, int x, int w)
{
	rc->camera_x = 2 * x / (double)w - 1;
	rc->ray_dir_x = rc->dir_x + rc->plane_x * rc->camera_x;
	rc->ray_dir_y = rc->dir_y + rc->plane_y * rc->camera_x;
}

void	calculate_delta_dist(t_rc *rc)
{
	rc->delta_dist_x = fabs((1 / rc->ray_dir_x));
	rc->delta_dist_y = fabs((1 / rc->ray_dir_y));
}

void	calculate_side_dist(t_rc *rc)
{
	rc->map_x = (int)rc->pos_x;
	rc->map_y = (int)rc->pos_y;
	if (rc->ray_dir_x < 0)
	{
		rc->step_x = -1;
		rc->side_dist_x = (rc->pos_x - rc->map_x) * rc->delta_dist_x;
	}
	else
	{
		rc->step_x = 1;
		rc->side_dist_x = (rc->map_x + 1.0 - rc->pos_x) * rc->delta_dist_x;
	}
	if (rc->ray_dir_y < 0)
	{
		rc->step_y = -1;
		rc->side_dist_y = (rc->pos_y - rc->map_y) * rc->delta_dist_y;
	}
	else
	{
		rc->step_y = 1;
		rc->side_dist_y = (rc->map_y + 1.0 - rc->pos_y) * rc->delta_dist_y;
	}
}

void	dda_algorithm(t_rc *rc)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		prep_dda(rc);
		if (rc->worldmap[rc->map_x][rc->map_y] > 0)
			hit = 1;
		if (rc->worldmap[rc->map_x][rc->map_y] == 2)
		{
			if (rc->doors[rc->map_x][rc->map_y].state == 1)
				hit = 1;
			else
				hit = 0;
		}
	}
}

void	raycasting(t_rc *rc, t_data *img, t_sprite sprite[])
{
	int			x;
	int			w;
	t_sprite	door_tex;

	x = -1;
	w = SCREEN_WIDTH;
	door_tex.img = mlx_xpm_file_to_image(img->mlx,
			rc->door_file, &door_tex.width, &door_tex.height);
	door_tex.data = mlx_get_data_addr(door_tex.img,
			&door_tex.bpp, &door_tex.size_line, &door_tex.endian);
	while (++x < w)
	{
		calculate_ray_direction(rc, x, w);
		calculate_delta_dist(rc);
		calculate_side_dist(rc);
		dda_algorithm(rc);
		if (rc->worldmap[rc->map_x][rc->map_y] == 2)
			door_case(rc, img, x, &door_tex);
		else if (rc->worldmap[rc->map_x][rc->map_y] > 0)
			wall_case(rc, img, x, sprite);
	}
}
