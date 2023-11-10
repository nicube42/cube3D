/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:38:56 by ndiamant          #+#    #+#             */
/*   Updated: 2023/11/06 15:00:52 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <unistd.h>

typedef struct s_gun
{
	t_sprite	*current_sprite;
	float		scale;
	int			color;
	int			sprite_x;
	int			sprite_y;
	int			scaled_width;
	int			scaled_height;
	int			pixel_x;
	int			pixel_y;
}				t_gun;

int	mouse_click_hook(int button, int x, int y, t_nest *nest)
{
	int		i;

	i = -1;
	if (button == 1)
	{
		while (++i < 4)
		{
			nest->as.current_sprite++;
			draw_hud_animated_sprite(&nest->img, &nest->as, 720, 435);
			mlx_put_image_to_window(nest->img.mlx, nest->img.mlx_win,
				nest->img.img, 0, 0);
		}
		nest->as.current_sprite = 0;
	}
	(void) y;
	(void) x;
	return (0);
}

void	scale_hud(t_animated_sprite *animated_sprite, float scale, t_gun *gun)
{
	gun->current_sprite = &animated_sprite->sprite
	[animated_sprite->current_sprite];
	gun->scaled_width = (int)(gun->current_sprite->width * scale);
	gun->scaled_height = (int)(gun->current_sprite->height * scale);
}

void	print_hud(float scale, t_data *img, t_gun *gun)
{
	int	dx;
	int	dy;
	int	final_x;
	int	final_y;

	dy = -1;
	while (++dy < scale)
	{
		dx = -1;
		while (++dx < scale)
		{
			final_y = gun->sprite_y + dy - ((scale - 1) / 2);
			final_x = gun->sprite_x + dx - ((scale - 1) / 2);
			if (final_y >= 0 && final_y < SCREEN_HEIGHT && final_x
				>= 0 && final_x < SCREEN_WIDTH)
			{
				*(int *)(img->addr + (final_y * img->line_length + final_x
							* (img->bits_per_pixel / 8))) = gun->color;
			}
		}
	}
}

void	prepare_hud(t_gun *gun, int i, int j, t_data *img)
{
	gun->pixel_y = (int)(i / gun->scale);
	gun->pixel_x = (int)(j / gun->scale);
	gun->color = *(int *)(gun->current_sprite->data + (gun->pixel_y
				* gun->current_sprite->size_line
				+ gun->pixel_x * (gun->current_sprite->bpp / 8)));
	if (gun->color != 9961608)
		print_hud(gun->scale, img, gun);
}

void	draw_hud_animated_sprite(t_data *img,
	t_animated_sprite *animated_sprite, int x, int y)
{
	t_gun	gun;
	int		i;
	int		j;
	float	scale;

	scale = 10.0;
	gun.scale = scale;
	i = -1;
	scale_hud(animated_sprite, scale, &gun);
	while (++i < gun.scaled_height)
	{
		j = -1;
		while (++j < gun.scaled_width)
		{
			gun.sprite_y = y + i;
			gun.sprite_x = x + j;
			prepare_hud(&gun, i, j, img);
		}
	}
}
