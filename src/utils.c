/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumarque <lumarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:27:04 by lumarque          #+#    #+#             */
/*   Updated: 2023/09/21 17:37:25 by lumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_error(t_game *game, char *msg)
{
	clean_game(game);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit (EXIT_FAILURE);
}

void	check_filename(char *file)
{
	size_t	i;

	i = ft_strlen(file);
	if (i <= 4)
		exit_error(NULL, "Invalid file name.");
	else if (!ft_strnstr((file + i - 4), ".ber", 4))
		exit_error(NULL, "Invalid file extension.");
}

