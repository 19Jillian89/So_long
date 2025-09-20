/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_the_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <ilnassi@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 00:06:22 by ilnassi           #+#    #+#             */
/*   Updated: 2025/09/13 01:37:49 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Find the player's position and count the collectibles.
I scan the entire map (y, x). If I find 'P', I save the coordinates
game->player_x and y. If I find 'C', I increment the collectible_count.*/
static void	find_position_p(t_game *game)
{
	int	y;
	int	x;

	game->collectible_count = 0;
	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_y = y;
				game->player_x = x;
			}
			if (game->map[y][x] == 'C')
				game->collectible_count++;
			x++;
		}
		y++;
	}
}

/*Create a copy of the flood fill map, so
I don't modify the original one*/
static void	map_copy(t_game *game)
{
	int	i;

	game->map_cpy = (char **)ft_calloc((game->rows + 1), sizeof(char *));
	if (!game->map_cpy)
		return ;
	i = 0;
	while (i < game->rows)
	{
		game->map_cpy[i] = ft_strdup(game->map[i]);
		if (!game->map_cpy[i])
		{
			while (--i >= 0)
				free(game->map_cpy[i]);
			free(game->map_cpy);
			game->map_cpy = NULL;
			return ;
		}
		i++;
	}
	game->map_cpy[i] = NULL;
}

/*Function that checks from the player's starting position whether it is
possible to reach collectibles and the exit*/
static void	flood_fill(t_game *game, int row, int col)
{
	if (row < 0 || col < 0 || row >= game->rows || col >= game->cols)
		return ;
	if (game->map_cpy[row][col] == '1' || game->map_cpy[row][col] == 'X')
		return ;
	if (game->map_cpy[row][col] == 'C')
		game->coll_fill_found++;
	else if (game->map_cpy[row][col] == 'E')
		game->exit_reached = 1;
	game->map_cpy[row][col] = 'X';
	flood_fill(game, row - 1, col);
	flood_fill(game, row + 1, col);
	flood_fill(game, row, col - 1);
	flood_fill(game, row, col + 1);
}

/*Check if the map is playable: call find_position(del player)
+ collectibles. Copy the map (map_copy), run floodfill.
If it fails, exit and print error, otherwise 1.*/
int	check_path(t_game *game)
{
	find_position_p(game);
	map_copy(game);
	if (!game->map_cpy)
	{
		ft_printf("Error\nMap copy failed\n");
		exit(EXIT_FAILURE);
	}
	game->coll_fill_found = 0;
	game->exit_reached = 0;
	flood_fill(game, game->player_y, game->player_x);
	if (game->coll_fill_found != game->collectible_count
		|| !game->exit_reached)
	{
		free_map_cpy(game);
		ft_printf("Error\nInvalid path in map\n");
		exit(EXIT_FAILURE);
	}
	free_map_cpy(game);
	return (1);
}
