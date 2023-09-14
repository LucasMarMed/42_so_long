/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumarque <lumarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:33:26 by lumarque          #+#    #+#             */
/*   Updated: 2023/09/13 16:34:57 by lumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *so_long, t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->pos->rows)
	{
		x = -1;
		while (++x < map->pos->cols)
			render_tile(so_long, (t_point){x, y});
	}
}