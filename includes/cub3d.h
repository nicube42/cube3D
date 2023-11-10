/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:32:08 by ndiamant          #+#    #+#             */
/*   Updated: 2023/11/09 14:29:33 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include "parsing.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define RGB_RED 0xFF0000
# define RGB_GREEN 0x00FF00
# define RGB_BLUE  0x0000FF
# define RGB_WHITE 0xFFFFFF
# define RGB_BLACK 0x000000
# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3
# define WALL 1
# define GROUND 0
# define BLANK 3
# define DOOR 2
# define MINIMAP_SCALE 20
# define BUFFER_DISTANCE 1
# define SWORD_SIZE 10

typedef struct s_door
{
	int		x;
	int		y;
	int		state;
	float	position;
}	t_door;

typedef struct s_rc
{
	int				len_line;
	int				nb_lines;
	unsigned long	ceiling_color;
	unsigned long	floor_color;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	int				step_x;
	int				step_y;
	int				map_x;
	int				map_y;
	int				side;
	double			perp_wall_dist;
	int				line_height;
	int				draw_start;
	int				draw_end;
	char			*door_file;
	t_door			**doors;
	int				**worldmap;
}					t_rc;

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_sprite
{
	void	*img;
	char	*data;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}				t_sprite;

typedef struct s_keys
{
	int	forward;
	int	backward;
	int	turn_left;
	int	turn_right;
	int	rotate_left;
	int	rotate_right;
	int	lock_cam;
	int	action;
}	t_keys;

typedef struct s_animated_sprite
{
	t_sprite	sprite[5];
	int			current_sprite;
	int			max_sprites;
}	t_animated_sprite;

typedef struct s_pars
{
	int				fd_cub;
	char			*north_file;
	char			*south_file;
	char			*east_file;
	char			*weast_file;
	char			*door_file;
	unsigned long	celling_color;
	unsigned long	floor_color;
	int				celling_set;
	int				floor_set;
	int				**wonder_map;
	int				len_line;
	int				nb_lines;
	char			*str_to_free;
	int				pos_num_column;
	int				pos_num_line;
	int				orientation;
}				t_pars;

typedef struct s_nest
{
	t_rc				rc;
	t_data				img;
	t_keys				keys;
	t_sprite			sprite[4];
	t_animated_sprite	as;
	t_pars				pars;
}				t_nest;

void	raycasting(t_rc *rc, t_data *img, t_sprite sprite[]);
int		continuous_move(t_nest *nest);
void	calculate_distance_from_wall(t_rc *rc);
void	calculate_line_height(t_rc *rc);
void	print_pixels(t_rc *rc, t_data *img, int x);
void	select_texture(t_rc *rc, t_data *img, t_sprite sprites[], int x);
int		key_press(int keycode, t_nest *nest);
int		key_release(int keycode, t_nest *nest);
int		mouse_click_hook(int button, int x, int y, t_nest *nest);
int		mouse_move_hook(int x, int y, t_nest *nest);
void	rotate_left(int keycode, double rot_speed, t_rc *rc);
void	rotate_right(int keycode, double rot_speed, t_rc *rc);
void	draw_minimap(t_data *img, t_rc *rc);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_hud_animated_sprite(t_data *img,
			t_animated_sprite *animated_sprite, int x, int y);
void	init_gun(t_nest *nest);
void	init_mlx(t_data *img, t_sprite sprite[], t_pars *pars);
void	init_struct(t_nest *nest);
void	calculate_ray_direction(t_rc *rc, int x, int w);
void	calculate_delta_dist(t_rc *rc);
void	calculate_side_dist(t_rc *rc);
int		get_sprite_pixel_color(t_sprite *sprite, int x, int y);
void	print_textures(t_rc *rc, t_data *img, t_sprite *selected_sprite, int x);
int		action(t_rc *rc);
void	door_case(t_rc *rc, t_data *img, int x, t_sprite *door_tex);
void	wall_case(t_rc *rc, t_data *img, int x, t_sprite sprite[]);
void	free_door(int y, t_door **doors, t_nest *nest);
void	prep_dda(t_rc *rc);
void	transform_orientation_y(t_nest *nest);
void	free_pars(t_pars pars);
void	free_all(t_nest *nest);

#endif
