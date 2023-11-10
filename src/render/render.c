/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:42:10 by ndiamant          #+#    #+#             */
/*   Updated: 2023/11/09 14:39:41 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	print_pixels(t_rc *rc, t_data *img, int x)
{
	int	y;
	int	ceiling_color;
	int	floor_color;

	y = -1;
	ceiling_color = rc->ceiling_color;
	floor_color = rc->floor_color;
	while (++y < SCREEN_HEIGHT)
	{
		if (y < rc->draw_start)
			my_mlx_pixel_put(img, x, y, ceiling_color);
		else if (y >= rc->draw_end)
			my_mlx_pixel_put(img, x, y, floor_color);
	}
}

int	get_sprite_pixel_color(t_sprite *sprite, int x, int y)
{
	int	pos;
	int	color;

	if (x < 0 || x >= sprite->width || y < 0 || y >= sprite->height)
		return (0);
	pos = (y * sprite->size_line) + (x * (sprite->bpp / 8));
	color = *(int *)(sprite->data + pos);
	return (color);
}

void	print_textures(t_rc *rc, t_data *img, t_sprite *selected_sprite, int x)
{
	double		wall_x;
	int			tex_x;
	int			tex_y;
	int			color;
	int			y;

	if (rc->side == 0)
		wall_x = rc->pos_y + rc->perp_wall_dist * rc->ray_dir_y;
	else
		wall_x = rc->pos_x + rc->perp_wall_dist * rc->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)selected_sprite->width);
	if ((rc->side == 0 && rc->ray_dir_x > 0)
		|| (rc->side == 1 && rc->ray_dir_y < 0))
		tex_x = selected_sprite->width - tex_x - 1;
	y = rc->draw_start - 1;
	if (y < -1)
		y = -1;
	while (++y < SCREEN_HEIGHT && y < rc->draw_end)
	{
		tex_y = (((y - rc->draw_start) * selected_sprite->height)
				/ (rc->draw_end - rc->draw_start));
		color = get_sprite_pixel_color(selected_sprite, tex_x, tex_y);
		my_mlx_pixel_put(img, x, y, color);
	}
}

void	select_texture(t_rc *rc, t_data *img, t_sprite sprites[], int x)
{
	t_sprite	*selected_sprite;

	if (rc->side == 0)
	{
		if (rc->ray_dir_x < 0)
			selected_sprite = &sprites[NORTH];
		else
			selected_sprite = &sprites[SOUTH];
	}
	else
	{
		if (rc->ray_dir_y > 0)
			selected_sprite = &sprites[EAST];
		else
			selected_sprite = &sprites[WEST];
	}
	print_textures(rc, img, selected_sprite, x);
}
