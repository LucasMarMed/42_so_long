/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumarque <lumarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:25:56 by lumarque          #+#    #+#             */
/*   Updated: 2023/09/21 17:35:48 by lumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>//open, O_RDONLY
# include <unistd.h>//read, close, write
# include <stdlib.h>//malloc
# include <stdio.h>//printf
# include <stdbool.h>//bool
# include "../libs/minilibx-linux/mlx.h"

#include <X11/X.h>
#include <X11/keysym.h>

#define RED_PIXEL 0xFF0000

/* Color codes for printf  */
# define DEFAULT "\033[0;39m"
# define GRAY "\033[0;90m"
# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define BLUE "\033[0;94m"
# define MAGENTA "\033[0;95m"
# define CYAN "\033[0;96m"
# define WHITE "\033[0;97m"

/* Sprite Size */
# define SIZE 32

/* Key events */
# define ON_KEYPRESS 2
# define KEYPRESS_MASK	3
# define ON_CLOSE 17
# define CLOSE_MASK	0
# define EXPOSE	12
# define EXPOSURE_MASK	32768
# define MLX_ERROR 1

/* Path images*/
# define WALL_PATH		"./img/tree.xpm"
# define FLOOR_PATH		"./img/floor.xpm"
# define COLLECT_PATH	"./img/potion.xpm"
# define EXIT_PATH		"./img/portal.xpm"
# define CHAR_PATH		"./img/link_sprites/down_1__.xpm"
# define CHAR_L_PATH	"./img/link_sprites/left_1__.xpm"
# define CHAR_R_PATH	"./img/link_sprites/right_1__.xpm"
# define CHAR_U_PATH	"./img/link_sprites/up_1__.xpm"

/* Rules map*/
typedef enum e_tile
{
	SPACE	= '0',
	WALL	= '1',
	COIN	= 'C',
	EXIT	= 'E',
	PLAYER	= 'P',
}			t_tile;

/* */
typedef struct s_draw
{
	char	**map;
	int		height;
	int		length;
	char	*line;
}	t_draw;

/* Window 
typedef struct s_mlx
{
    void	*mlx_ptr;
    void	*win_ptr;
}	t_mlx;
*/

/* keysym */
enum e_key
{
	ESC		= 65307,
	W		= 119,
	A		= 97,
	S		= 115,
	D		= 100,
	UP		= 65362,
	DOWN	= 65364,
	LEFT	= 65361,
	RIGHT	= 65363,
};

typedef struct s_img
{
	void	*ptr;
	int		*pixels;
	int		line_size;
	int		mem;
	int		x;
	int		y;
	int		movements;
}	t_img;

typedef struct s_map
{
	char	**tiles;
	t_point	pos;
	int	coins;
	int	exit;
	int	player;
}			t_map;

typedef struct s_point
{
	int	x; // cols
	int	y; // rows
}	t_point;

typedef struct s_game
{
	void	*mlx_ptr; /* Window */
	void	*win_ptr; /* Window */

	t_map		*map;
	t_point		curr;
	t_point		next;
	t_img		character;
	t_img		character_l;
	t_img		character_r;
	t_img		character_u;
	t_img		floor;
	t_img		wall;
	t_img		collect;
	t_img		exit;
	int		moves;
}					t_game;


int	exit_error(t_game *so_long, char *msg);
void	check_filename(char *file);
t_map	*create_map(int cols, int rows);
int	get_rows(t_game *game, char *file);
void	render_map(t_game *so_long, t_map *map);
void	read_map(t_game *game, char *file);
int	endgame(t_game *game);

#endif