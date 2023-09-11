/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumarque <lumarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 13:25:56 by lumarque          #+#    #+#             */
/*   Updated: 2023/09/07 18:06:12 by lumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>//open, O_RDONLY
# include <unistd.h>//read, close, write
# include <stdlib.h>//malloc
# include <stdio.h>//printf
# include <stdbool.h>//bool
# include "/nfs/homes/lumarque/Github/42_so_long/libs/minilibx-linux/mlx.h"

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

typedef struct s_map
{
	char	**tiles;
	int	cols;
	int	rows;
	int	coins;
	int	exit;
	int	player;
}			t_map;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;




#endif