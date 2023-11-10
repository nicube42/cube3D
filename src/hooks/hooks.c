/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:23:42 by ndiamant          #+#    #+#             */
/*   Updated: 2023/11/08 10:59:19 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <stdio.h>

void	move_forward(int keycode, double move_speed, t_rc *rc)
{
	double	new_x;
	double	new_y;

	new_x = rc->pos_x + rc->dir_x * (move_speed + BUFFER_DISTANCE);
	new_y = rc->pos_y + rc->dir_y * (move_speed + BUFFER_DISTANCE);
	if (keycode == 13)
	{
		if (rc->worldmap[(int)new_x][(int)(rc->pos_y)] == 0
			|| rc->doors[(int)new_x][(int)(rc->pos_y)].state == 2)
			rc->pos_x += rc->dir_x * move_speed;
		if (rc->worldmap
			[(int)(rc->pos_x)][(int)(new_y)] == 0
			|| rc->doors[(int)rc->pos_x][(int)new_y].state == 2)
			rc->pos_y += rc->dir_y * move_speed;
	}
}

void	move_backward(int keycode, double move_speed, t_rc *rc)
{
	double	new_x;
	double	new_y;

	new_x = rc->pos_x - rc->dir_x * (move_speed + BUFFER_DISTANCE);
	new_y = rc->pos_y - rc->dir_y * (move_speed + BUFFER_DISTANCE);
	if (keycode == 1)
	{
		if (rc->worldmap
			[(int)new_x][(int)(rc->pos_y)] == 0
			|| rc->doors[(int)new_x][(int)(rc->pos_y)].state == 2)
		rc->pos_x -= rc->dir_x * move_speed;
		if (rc->worldmap
			[(int)(rc->pos_x)][(int)new_y] == 0
			|| rc->doors[(int)rc->pos_x][(int)new_y].state == 2)
			rc->pos_y -= rc->dir_y * move_speed;
	}
}

void	move_left(int keycode, double move_speed, t_rc *rc)
{
	double	new_x;
	double	new_y;

	new_x = rc->pos_x - rc->dir_y * (move_speed + BUFFER_DISTANCE);
	new_y = rc->pos_y + rc->dir_x * (move_speed + BUFFER_DISTANCE);
	if (keycode == 0)
	{
		if (rc->worldmap[(int)new_x]
			[(int)(rc->pos_y)] == 0
			|| rc->doors[(int)new_x][(int)(rc->pos_y)].state == 2)
			rc->pos_x -= rc->plane_x * move_speed;
		if (rc->worldmap[(int)(rc->pos_x)]
				[(int)new_y] == 0
				|| rc->doors[(int)rc->pos_x][(int)new_y].state == 2)
			rc->pos_y -= rc->plane_y * move_speed;
	}
}

void	move_right(int keycode, double move_speed, t_rc *rc)
{
	double	new_x;
	double	new_y;

	new_x = rc->pos_x + rc->dir_y * (move_speed + BUFFER_DISTANCE);
	new_y = rc->pos_y - rc->dir_x * (move_speed + BUFFER_DISTANCE);
	if (keycode == 2)
	{
		if (rc->worldmap[(int)new_x]
			[(int)(rc->pos_y)] == 0
			|| rc->doors[(int)new_x][(int)(rc->pos_y)].state == 2)
			rc->pos_x += rc->plane_x * move_speed;
		if (rc->worldmap[(int)(rc->pos_x)]
				[(int)new_y] == 0
				|| rc->doors[(int)rc->pos_x][(int)new_y].state == 2)
			rc->pos_y += rc->plane_y * move_speed;
	}
}

int	continuous_move(t_nest *nest)
{
	double	move_speed;
	double	rot_speed;

	move_speed = 0.1;
	rot_speed = 0.1;
	if (nest->keys.forward)
		move_forward(13, move_speed, &nest->rc);
	if (nest->keys.backward)
		move_backward(1, move_speed, &nest->rc);
	if (nest->keys.turn_left)
		move_left(0, move_speed, &nest->rc);
	if (nest->keys.turn_right)
		move_right(2, move_speed, &nest->rc);
	if (nest->keys.rotate_right)
		rotate_right(124, rot_speed, &nest->rc);
	if (nest->keys.rotate_left)
		rotate_left(123, rot_speed, &nest->rc);
	raycasting(&nest->rc, &nest->img, nest->sprite);
	draw_minimap(&nest->img, &nest->rc);
	draw_hud_animated_sprite(&nest->img, &nest->as, 720, 435);
	mlx_put_image_to_window(nest->img.mlx, nest->img.mlx_win,
		nest->img.img, 0, 0);
	return (0);
}
