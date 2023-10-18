/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumarque <lumarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:17:47 by lumarque          #+#    #+#             */
/*   Updated: 2023/09/23 16:02:43 by lumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	init_game(char *file)
{
	t_game	game;
	ft_bzero(&game, sizeof(t_game));
	printf("bzero \n");
	read_map(&game, file);
	printf("read \n");
	check_map(&game);
	printf("check \n");
	launch_mlx(&game, game.map);
	printf("launch \n");
	load_img(&game);
	printf("load \n");
	render_map(&game, game.map);
	printf("render \n");
	mlx_hook(game.mlx_ptr, ON_KEYPRESS, KEYPRESS_MASK, handle_keypress, &game);
	printf("handle_keypress \n");
	mlx_hook(game.mlx_ptr, ON_CLOSE, CLOSE_MASK, endgame, &game);
	printf("endgame \n");
	mlx_loop_hook(game.mlx_ptr, render_move, &game);
	printf("move \n");
	mlx_loop(game.mlx_ptr);
	printf("finsh \n");
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_error(NULL, "Invalid number of arguments.");
	check_filename(av[1]);
	init_game(av[1]);
}
