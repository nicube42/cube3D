/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:26:59 by ndiamant          #+#    #+#             */
/*   Updated: 2023/11/08 14:18:07 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#include <stdlib.h>

void	exit_error(const char *error_str, int error_num, t_pars pars);

t_door	**initialize_doors(int **worldmap, int map_width,
	int map_height, t_nest *nest)
{
	t_door	**doors;
	int		y;
	int		x;

	y = -1;
	doors = malloc(map_height * sizeof(t_door *));
	if (!doors)
		exit_error("[init 0] Malloc error", 1, nest->pars);
	while (++y < map_height)
	{
		doors[y] = malloc(map_width * sizeof(t_door));
		if (!doors[y])
			free_door(y, doors, nest);
		x = -1;
		while (++x < map_width)
		{
			if (worldmap[y][x] == 2)
				doors[y][x] = (t_door){x, y, 1, 0.0};
			else
				doors[y][x] = (t_door){0, 0, 0, 0.0};
		}
	}
	return (doors);
}

void	init_struct(t_nest *nest)
{
	nest->rc.pos_x = nest->pars.pos_num_line + 0.5;
	nest->rc.pos_y = nest->pars.pos_num_column + 0.5;
	transform_orientation_y(nest);
	nest->keys.backward = 0;
	nest->keys.forward = 0;
	nest->keys.turn_left = 0;
	nest->keys.turn_right = 0;
	nest->keys.rotate_left = 0;
	nest->keys.rotate_right = 0;
	nest->keys.lock_cam = 0;
	nest->keys.action = 0;
	nest->rc.doors = initialize_doors
		(nest->rc.worldmap, nest->pars.len_line, nest->pars.nb_lines, nest);
	nest->rc.nb_lines = nest->pars.len_line;
	nest->rc.len_line = nest->pars.nb_lines;
	nest->rc.ceiling_color = nest->pars.celling_color;
	nest->rc.floor_color = nest->pars.floor_color;
	nest->rc.door_file = nest->pars.door_file;
}

void	init_mlx(t_data *img, t_sprite sprite[], t_pars *pars)
{
	int			i;
	char		*sprite_files[4];

	sprite_files[NORTH] = pars->north_file;
	sprite_files[SOUTH] = pars->south_file;
	sprite_files[EAST] = pars->east_file;
	sprite_files[WEST] = pars->weast_file;
	i = -1;
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT, "Cub3d");
	img->img = mlx_new_image(img->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	while (++i <= 3)
	{
		sprite[i].img = mlx_xpm_file_to_image(img->mlx,
				(char *)sprite_files[i], &sprite[i].width, &sprite[i].height);
		sprite[i].data = mlx_get_data_addr(sprite[i].img,
				&sprite[i].bpp, &sprite[i].size_line, &sprite[i].endian);
	}
}

void	init_gun2(t_nest *nest)
{
	nest->as.sprite[2].data = mlx_get_data_addr(nest->as.sprite[2].img,
			&nest->as.sprite[2].bpp, &nest->as.sprite[2].size_line,
			&nest->as.sprite[2].endian);
	nest->as.sprite[3].img = mlx_xpm_file_to_image(nest->img.mlx,
			"gun/03_frame.xpm", &nest->as.sprite[3].width,
			&nest->as.sprite[3].height);
	nest->as.sprite[3].data = mlx_get_data_addr(nest->as.sprite[1].img,
			&nest->as.sprite[3].bpp, &nest->as.sprite[3].size_line,
			&nest->as.sprite[3].endian);
	nest->as.sprite[4].img = mlx_xpm_file_to_image(nest->img.mlx,
			"gun/04_frame.xpm", &nest->as.sprite[4].width,
			&nest->as.sprite[4].height);
	nest->as.sprite[4].data = mlx_get_data_addr(nest->as.sprite[4].img,
			&nest->as.sprite[4].bpp, &nest->as.sprite[4].size_line,
			&nest->as.sprite[4].endian);
}

void	init_gun(t_nest *nest)
{
	nest->as.max_sprites = 4;
	nest->as.current_sprite = 0;
	nest->as.sprite[0].img = mlx_xpm_file_to_image(nest->img.mlx,
			"gun/00_frame.xpm", &nest->as.sprite[0].width,
			&nest->as.sprite[0].height);
	nest->as.sprite[0].data = mlx_get_data_addr(nest->as.sprite[0].img,
			&nest->as.sprite[0].bpp, &nest->as.sprite[0].size_line,
			&nest->as.sprite[0].endian);
	nest->as.sprite[1].img = mlx_xpm_file_to_image(nest->img.mlx,
			"gun/01_frame.xpm", &nest->as.sprite[1].width,
			&nest->as.sprite[1].height);
	nest->as.sprite[1].data = mlx_get_data_addr(nest->as.sprite[1].img,
			&nest->as.sprite[1].bpp, &nest->as.sprite[1].size_line,
			&nest->as.sprite[1].endian);
	nest->as.sprite[2].img = mlx_xpm_file_to_image(nest->img.mlx,
			"gun/02_frame.xpm", &nest->as.sprite[2].width,
			&nest->as.sprite[2].height);
	init_gun2(nest);
}
