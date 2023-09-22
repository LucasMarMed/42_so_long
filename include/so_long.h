/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumarque <lumarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:25:56 by lumarque          #+#    #+#             */
/*   Updated: 2023/09/22 20:06:44 by lumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "utils.h"

# include <fcntl.h>//open, O_RDONLY
# include <unistd.h>//read, close, write
# include <stdlib.h>//malloc
# include <stdio.h>//printf
# include <stdbool.h>//bool
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/libft/libft.h"
# include "../libs/libft/42_get_next_line/get_next_line.h"

/*init_game*/
void	launch_mlx(t_game *game, t_map *map);
void	load_img(t_game *game);
t_img	new_sprite(void *mlx, char *path);

/*map*/
void	check_map(t_game *game);
t_map	*create_map(int cols, int rows);
int		get_rows(t_game *game, char *file);
void	render_tile(t_game *game, t_point p);
void	render_map(t_game *so_long, t_map *map);
void	read_map(t_game *game, char *file);
int		check_tiles(t_game *game, t_map *map);

int		handle_keypress(int keysym, t_game *game);
//int		check_move(t_game *game);
void	move_player(t_game *game, t_map *map);
int		render_move(t_game *game);

int		endgame(t_game *game);
void	clean_game(t_game *game);

int		exit_error(t_game *so_long, char *msg);
void	check_filename(char *file);
int		is_same_point(t_point a, t_point b);
int		flood_fill(t_map *map, t_point curr, char **path);
t_tile	get_tile(t_game *so_long, t_point p);

#endif