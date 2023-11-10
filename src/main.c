/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndiamant <ndiamant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:27:53 by ndiamant          #+#    #+#             */
/*   Updated: 2023/11/08 14:04:35 by ndiamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_pars	parsing(int argc, char const **argv);

int	close_program(t_nest *nest)
{
	free_all(nest);
	exit(0);
	return (0);
}

int	main(int argc, const char **argv)
{
	t_nest	nest;

	nest.pars = parsing(argc, argv);
	(void) nest;
	nest.rc.worldmap = nest.pars.wonder_map;
	init_struct(&nest);
	init_mlx(&nest.img, nest.sprite, &nest.pars);
	init_gun(&nest);
	mlx_hook(nest.img.mlx_win, 17, 0, close_program, &nest);
	mlx_hook(nest.img.mlx_win, 2, 1L << 0, key_press, &nest);
	mlx_hook(nest.img.mlx_win, 3, 1L << 1, key_release, &nest);
	mlx_loop_hook(nest.img.mlx, continuous_move, &nest.rc);
	mlx_hook(nest.img.mlx_win, 4, 0, mouse_click_hook, &nest);
	mlx_hook(nest.img.mlx_win, 6, 0, mouse_move_hook, &nest.rc);
	mlx_loop(nest.img.mlx);
	free_all(&nest);
}
