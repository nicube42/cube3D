/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:31:57 by ndiamant          #+#    #+#             */
/*   Updated: 2023/11/08 13:18:28 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	mouse_move_hook(int x, int y, t_nest *nest)
{
	static int	prev_x = -1;
	double		rotation_angle;
	double		old_dir_x;
	double		old_plane_x;

	if (nest->keys.lock_cam == 1)
	{
		if (prev_x == -1)
			prev_x = x;
		rotation_angle = -((x - prev_x) * 0.005);
		old_dir_x = nest->rc.dir_x;
		nest->rc.dir_x = nest->rc.dir_x * cos(rotation_angle)
			- nest->rc.dir_y * sin(rotation_angle);
		nest->rc.dir_y = old_dir_x * sin(rotation_angle)
			+ nest->rc.dir_y * cos(rotation_angle);
		old_plane_x = nest->rc.plane_x;
		nest->rc.plane_x = nest->rc.plane_x * cos(rotation_angle)
			- nest->rc.plane_y * sin(rotation_angle);
		nest->rc.plane_y = old_plane_x * sin(rotation_angle)
			+ nest->rc.plane_y * cos(rotation_angle);
		prev_x = x;
	}
	(void) y;
	return (0);
}

int	key_press(int keycode, t_nest *nest)
{
	if (keycode == 13)
		nest->keys.forward = 1;
	else if (keycode == 1)
		nest->keys.backward = 1;
	else if (keycode == 0)
		nest->keys.turn_left = 1;
	else if (keycode == 2)
		nest->keys.turn_right = 1;
	else if (keycode == 124)
		nest->keys.rotate_right = 1;
	else if (keycode == 123)
		nest->keys.rotate_left = 1;
	else if (keycode == 53)
	{
		free_all(nest);
		exit (0);
	}
	else if (keycode == 3)
		nest->keys.lock_cam = !nest->keys.lock_cam;
	else if (keycode == 14)
		action(&nest->rc);
	return (0);
}

int	key_release(int keycode, t_nest *nest)
{
	if (keycode == 13)
		nest->keys.forward = 0;
	else if (keycode == 1)
		nest->keys.backward = 0;
	else if (keycode == 0)
		nest->keys.turn_left = 0;
	else if (keycode == 2)
		nest->keys.turn_right = 0;
	else if (keycode == 124)
		nest->keys.rotate_right = 0;
	else if (keycode == 123)
		nest->keys.rotate_left = 0;
	return (0);
}

void	rotate_left(int keycode, double rot_speed, t_rc *rc)
{
	double	old_dir_x;
	double	old_plane_x;

	if (keycode == 123)
	{
		old_dir_x = rc->dir_x;
		rc->dir_x = rc->dir_x * cos(rot_speed) - rc->dir_y * sin(rot_speed);
		rc->dir_y = old_dir_x * sin(rot_speed) + rc->dir_y * cos(rot_speed);
		old_plane_x = rc->plane_x;
		rc->plane_x = rc->plane_x * cos(rot_speed) - rc->plane_y
			* sin(rot_speed);
		rc->plane_y = old_plane_x * sin(rot_speed)
			+ rc->plane_y * cos(rot_speed);
	}
}

void	rotate_right(int keycode, double rot_speed, t_rc *rc)
{
	double	old_dir_x;
	double	old_plane_x;

	if (keycode == 124)
	{
		old_dir_x = rc->dir_x;
		rc->dir_x = rc->dir_x * cos(-rot_speed) - rc->dir_y * sin(-rot_speed);
		rc->dir_y = old_dir_x * sin(-rot_speed) + rc->dir_y * cos(-rot_speed);
		old_plane_x = rc->plane_x;
		rc->plane_x = rc->plane_x * cos(-rot_speed)
			- rc->plane_y * sin(-rot_speed);
		rc->plane_y = old_plane_x * sin(-rot_speed)
			+ rc->plane_y * cos(-rot_speed);
	}
}
