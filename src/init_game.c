/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumarque <lumarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:50:58 by lumarque          #+#    #+#             */
/*   Updated: 2023/09/21 18:52:24 by lumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	launch_mlx(t_game *game, t_map *map)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		exit_error(game, "Failed to initialize mlx.");
	game->mlx_ptr = mlx_new_window(game->mlx_ptr, \
			map->pos.x * SIZE, map->pos.y * SIZE, "so_long");
	if (!game->mlx_ptr)
		exit_error(game, "Failed to create window.");
}

void	load_img(t_game *game)
{
	game->wall = new_sprite(game->mlx_ptr, WALL_PATH);
	game->floor = new_sprite(game->mlx_ptr, FLOOR_PATH);
	game->collect = new_sprite(game->mlx_ptr, COLLECT_PATH);
	game->exit = new_sprite(game->mlx_ptr, EXIT_PATH);
	game->character = new_sprite(game->mlx_ptr, CHAR_PATH);
	game->character_l = new_sprite(game->mlx_ptr, CHAR_L_PATH);
	game->character_r = new_sprite(game->mlx_ptr, CHAR_R_PATH);
	game->character_u = new_sprite(game->mlx_ptr, CHAR_U_PATH);
	return ;
}

t_img	new_sprite(void *mlx, char *path)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.x, &img.y);
	return (img);
}

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == UP || keysym == W )
			//pos->hero = y+1;
	if (keysym == DOWN || keysym == S)
			//pos->hero = y-1;
	if (keysym == LEFT || keysym == A)
			//pos->hero = x-1;
	if (keysym == RIGHT || keysym == D)
			//pos->hero = x+1;
	if (keysym == ESC)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		game->win_ptr = NULL;
	}
	return (0);
}
