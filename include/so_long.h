/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumarque <lumarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:25:56 by lumarque          #+#    #+#             */
/*   Updated: 2023/09/21 19:09:30 by lumarque         ###   ########.fr       */
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
#include <X11/X.h>
#include <X11/keysym.h>
# include "../libs/minilibx-linux/mlx.h"


int	exit_error(t_game *so_long, char *msg);
void	check_filename(char *file);
t_map	*create_map(int cols, int rows);
int	get_rows(t_game *game, char *file);
void	render_map(t_game *so_long, t_map *map);
void	read_map(t_game *game, char *file);
int	endgame(t_game *game);
int	handle_keypress(int keysym, t_game *game);
int	check_tiles(t_game *game, t_map *map);

#endif