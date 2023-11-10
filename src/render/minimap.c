/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:18:01 by ndiamant          #+#    #+#             */
/*   Updated: 2023/11/08 10:58:41 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_player_position(t_data *img, t_rc *rc)
{
	int		dx;
	int		dy;
	int		color;
	float	transformed_player_x;
	float	transformed_player_y;

	transformed_player_x = rc->pos_y * MINIMAP_SCALE - (7 / 2);
	transformed_player_y = rc->pos_x * MINIMAP_SCALE - (7 / 2);
	color = RGB_RED;
	dy = -1;
	while (++dy < 7)
	{
		dx = -1;
		while (++dx < 7)
			my_mlx_pixel_put(img, (int)(transformed_player_x + dx),
				(int)(transformed_player_y + dy), color);
	}
}

void	print_minimap(t_data *img, t_rc *rc, int x, int y)
{
	int	color;
	int	dx;
	int	dy;

	dx = -1;
	if (rc->worldmap[x][y] == 1)
		color = RGB_BLACK;
	else if (rc->worldmap[x][y] == 2)
	{
		color = RGB_GREEN;
		if (rc->doors[x][y].state == 1)
			color = RGB_RED;
	}
	else
		color = RGB_WHITE;
	while (++dx < MINIMAP_SCALE)
	{
		dy = -1;
		while (++dy < MINIMAP_SCALE)
			my_mlx_pixel_put(img, y * MINIMAP_SCALE
				+ dx, x * MINIMAP_SCALE + dy, color);
	}
}

void	draw_minimap(t_data *img, t_rc *rc)
{
	int	x;
	int	y;

	y = -1;
	while (++y < rc->nb_lines)
	{
		x = -1;
		while (++x < rc->len_line)
			print_minimap(img, rc, x, y);
	}
	print_player_position(img, rc);
}
