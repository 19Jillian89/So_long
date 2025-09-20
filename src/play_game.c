/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:56:38 by ilnassi           #+#    #+#             */
/*   Updated: 2025/09/11 14:50:54 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Using mlx_put_image.. I "draw" the floor in each cell of the map*/
static void	put_floor(t_game *game, int col, int row)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->textures.floor, col * TILE_SIZE, row * TILE_SIZE);
}

/*Draw the right texture based on the cell contents ('1', 'P' etc)*/
static void	put_tile(t_game *game, char tile, int col, int row)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.wall, col * TILE_SIZE, row * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.collectible, col * TILE_SIZE, row * TILE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.exit, col * TILE_SIZE, row * TILE_SIZE);
	else if (tile == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.player_down, col * TILE_SIZE, row * TILE_SIZE);
		game->player_x = col;
		game->player_y = row;
	}
}

/*Using the functions above, scrolling row by row, column by column,
draw the map (floor and walls)*/
void	draw_map(t_game *game, char **map, int moves)
{
	int	row;
	int	col;

	if (!map || !game->mlx || !game->win)
		return ;
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			put_floor(game, col, row);
			put_tile(game, map[row][col], col, row);
			col++;
		}
		row++;
	}
	(void)moves;
}

/*Function to start the game. Draw the map with draw_map,
set hooks, and start the mlx_loop graphics loop*/
int	init_game(t_game *game)
{
	if (!game->mlx || !game->win || !game->map)
		return (0);
	draw_map(game, game->map, 0);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->mlx);
	return (1);
}
