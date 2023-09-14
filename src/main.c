/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumarque <lumarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:17:47 by lumarque          #+#    #+#             */
/*   Updated: 2023/09/14 16:59:09 by lumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300



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

int	render(t_game *game)
{
    /* if window has been destroyed, we don't want to put the pixel ! */
    if (game->win_ptr != NULL)
        mlx_pixel_put(game->mlx_ptr, game->win_ptr, 
            WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, RED_PIXEL);
    return (0);
}

void init_game(char *file)
{
	t_game game;

	ft_bzero(&game, sizeof(t_game));
	read_map(&game, file);
	check_map(&game);
	launch_mlx(&game, game.map);
	load_assets(&game);
	render_map(&game, game.map);
	mlx_hook(game.mlx_ptr, ON_KEYPRESS, KEYPRESS_MASK, check_keypress, &game);
	mlx_hook(game.mlx_ptr, ON_CLOSE, CLOSE_MASK, quit_game, &game);
	mlx_loop_hook(game.mlx_ptr, render_move, &game);
	mlx_loop(game.mlx_ptr);
	
	
	game.mlx_ptr = mlx_init();
	if (game.mlx_ptr == NULL)
	    return (MLX_ERROR);
	game.win_ptr = mlx_new_window(game.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
									"my window");
	if (game.win_ptr == NULL)
	{
		free(game.win_ptr);
		return (MLX_ERROR);
    }

}


int	main(void)
{
	t_game so_long;

	init_game(so_long);
	
    /* Setup hooks */ 
    mlx_loop_hook(data.mlx_ptr, &render, &data);
    mlx_hook(data.win_ptr, ON_KEYPRESS, KEYPRESS_MASK, &handle_keypress, &data);

    mlx_loop(data.mlx_ptr);

    /* we will exit the loop if there's no window left, and execute this code */
    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr);
}