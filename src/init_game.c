/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumarque <lumarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:50:58 by lumarque          #+#    #+#             */
/*   Updated: 2023/09/14 18:25:00 by lumarque         ###   ########.fr       */
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

/*void	load_assets(t_game *game)
{
	game->sp = malloc(SPRITES * sizeof(t_sprite));
	if (!game->sp)
		exit_error(game, "Failed to allocate memory on sprites.");
	game->sp[W1].img = mlx_xpm_file_to_image(game->display.mlx, FW1, \
			&(game->sp[W1].width), &(game->sp[W1].height));
	game->sp[S1].img = mlx_xpm_file_to_image(game->display.mlx, FS1, \
			&(game->sp[S1].width), &(game->sp[S1].height));
	game->sp[C1].img = mlx_xpm_file_to_image(game->display.mlx, FC1, \
			&(game->sp[C1].width), &(game->sp[C1].height));
	game->sp[E1].img = mlx_xpm_file_to_image(game->display.mlx, FE1, \
			&(game->sp[E1].width), &(game->sp[E1].height));
	game->sp[P1].img = mlx_xpm_file_to_image(game->display.mlx, FP1, \
			&(game->sp[P1].width), &(game->sp[P1].height));
}

void	render_tile(t_game *game, t_point p)
{
	t_sprite	sp;

	if (game->map->tiles[p.y][p.x] == WALL)
		sp = game->sp[W1];
	else if (game->map->tiles[p.y][p.x] == COIN)
		sp = game->sp[C1];
	else if (game->map->tiles[p.y][p.x] == EXIT)
		sp = game->sp[E1];
	else if (game->map->tiles[p.y][p.x] == SPACE)
		sp = game->sp[S1];
	else if (game->map->tiles[p.y][p.x] == PLAYER)
		sp = game->sp[P1];
	mlx_put_image_to_window(game->display.mlx, game->display.win, \
		sp.img, sp.width * p.x, sp.height * p.y);
}
*/