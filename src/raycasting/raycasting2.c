/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:33:58 by ndiamant          #+#    #+#             */
/*   Updated: 2023/11/09 13:44:55 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_distance_from_wall(t_rc *rc)
{
	if (rc->side == 0)
		rc->perp_wall_dist = (rc->side_dist_x - rc->delta_dist_x);
	else
		rc->perp_wall_dist = (rc->side_dist_y - rc->delta_dist_y);
}

void	calculate_line_height(t_rc *rc)
{
	int	h;

	h = SCREEN_HEIGHT;
	rc->line_height = (int)(h / rc->perp_wall_dist);
	rc->draw_start = -rc->line_height / 2 + h / 2;
	rc->draw_end = rc->line_height / 2 + h / 2;
}

void	door_case(t_rc *rc, t_data *img, int x, t_sprite *door_tex)
{
	t_door	*door;

	door = &rc->doors[rc->map_x][rc->map_y];
	if (door->state == 1)
	{
		calculate_distance_from_wall(rc);
		calculate_line_height(rc);
		print_pixels(rc, img, x);
		print_textures(rc, img, door_tex, x);
	}
}

void	wall_case(t_rc *rc, t_data *img, int x, t_sprite sprite[])
{
	calculate_distance_from_wall(rc);
	calculate_line_height(rc);
	print_pixels(rc, img, x);
	select_texture(rc, img, sprite, x);
}

void	prep_dda(t_rc *rc)
{
	if (rc->side_dist_x < rc->side_dist_y)
	{
		rc->side_dist_x += rc->delta_dist_x;
		rc->map_x += rc->step_x;
		rc->side = 0;
	}
	else
	{
		rc->side_dist_y += rc->delta_dist_y;
		rc->map_y += rc->step_y;
		rc->side = 1;
	}
}
