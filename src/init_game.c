/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumarque <lumarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:50:58 by lumarque          #+#    #+#             */
/*   Updated: 2023/09/14 17:57:38 by lumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

t_map	*create_map(int cols, int rows)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->tiles = ft_calloc(rows + 1, sizeof(char *));
	if (!map->tiles)
	{
		free(map);
		return (NULL);
	}
	map->pos->x = cols;
	map->pos->y = rows;
	return (map);
}

int	get_rows(t_game *game, char *file)
{
	int		fd;
	int		rows;
	char	*line;

	rows = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(game, "Couldn't open requested file.");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		rows++;
	}
	close (fd);
	return (rows);
}


void	check_map(t_game *game)
{

}

void	launch_mlx(t_game *game, t_map *map)
{

}

void	load_assets(t_game *game)
{

}

void	render_map(t_game *game, t_map *map)
{

}
void	read_map(t_game *game, char *file)
{

	int		fd;
	char	*line;
	int	i;

	i = -1;
	game->map = create_map(0, get_rows(game, file));
	if (!game->map)
		exit_error(game, "Couldn't read map.");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(game, "Couldn't open requested file.");
	while (++i < game->map->y)
	{
		line = get_next_line(fd);
		if (!line)
			exit_error(game, "Couldn't read map.");
		game->map->tiles[i] = ft_strtrim(line, "\n");
		if (!game->map->tiles[i])
			exit_error(game, "Couldn't read map.");
		free(line);
	}
	close (fd);
}