/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumarque <lumarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:17:47 by lumarque          #+#    #+#             */
/*   Updated: 2023/09/21 18:56:24 by lumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

void	init_game(char *file)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	read_map(&game, file);
	check_map(&game);
	launch_mlx(&game, game.map);
	load_img(&game);
	render_map(&game, game.map);
	mlx_hook(game.mlx_ptr, ON_KEYPRESS, KEYPRESS_MASK, &handle_keypress, &game);
	mlx_hook(game.mlx_ptr, ON_CLOSE, CLOSE_MASK, endgame, &game);
	mlx_loop_hook(game.mlx_ptr, render_move, &game);
	mlx_loop(game.mlx_ptr);
	game.mlx_ptr = mlx_init();
	if (game.mlx_ptr == NULL)
		return (MLX_ERROR);
	game.win_ptr = mlx_new_window(game.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, \
	"my window");
	if (game.win_ptr == NULL)
	{
		free(game.win_ptr);
		return (MLX_ERROR);
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_error(NULL, "Invalid number of arguments.");
	check_filename(av[1]);
	init_game(av[1]);
}
