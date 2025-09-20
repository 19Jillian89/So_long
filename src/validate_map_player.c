/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_player.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:06:53 by ilnassi           #+#    #+#             */
/*   Updated: 2025/09/16 14:17:31 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Count how many 'P' 'C' "E' there are*/
static void	count_pce(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			if (game->map[y][x] == 'C')
				game->collectible_count++;
			else if (game->map[y][x] == 'E')
				game->exit_count++;
			else if (game->map[y][x] == 'P')
				game->player_count++;
			x++;
		}
		y++;
	}
}

/*Check that there is at least one collectible, one exit, and one player*/
static int	validate_pce(t_game *game)
{
	if (game->collectible_count < 1)
		return (ft_printf("Not enough collectibles\n"), 0);
	if (game->exit_count != 1)
		return (ft_printf("Invalid Exit\n"), 0);
	if (game->player_count != 1)
		return (ft_printf("Invalid Player\n"), 0);
	return (1);
}

/*Reset the counters and call the functions that count and validate pce
P → (player), C → (collectibles)E →>(exit)*/
int	check_pce(t_game *game)
{
	game->collectible_count = 0;
	game->exit_count = 0;
	game->player_count = 0;
	count_pce(game);
	return (validate_pce(game));
}

/*Call all map validation functions in order:
rectangularity, walls, PCE, characters, and path*/
int	check_valid_map(t_game *game)
{
	if (!check_rectangle(game, game->rows))
		return (0);
	if (!check_all_walls(game, game->rows))
		return (0);
	if (!check_pce(game))
		return (0);
	if (!check_valid_chars(game))
		return (0);
	if (!check_path(game))
		return (0);
	return (1);
}

/*Scan the map and report error if it finds invalid characters*/
int	check_valid_chars(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			if (game->map[y][x] != '0' && game->map[y][x] != '1'
				&& game->map[y][x] != 'C' && game->map[y][x] != 'E'
				&& game->map[y][x] != 'P')
			{
				ft_printf("Error\nInvalid char '%c' in map\n",
					game->map[y][x]);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
