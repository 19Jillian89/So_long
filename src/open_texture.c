/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:01:59 by ilnassi           #+#    #+#             */
/*   Updated: 2025/09/11 12:06:13 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Load wall and floor textures, using mlx_xpm
to read .xpm files from the assets folder*/
static int	load_tiles(t_game *game, int *w, int *h)
{
	game->textures.wall = mlx_xpm_file_to_image(game->mlx,
			"assets/WallTartan.xpm", w, h);
	game->textures.floor = mlx_xpm_file_to_image(game->mlx,
			"assets/Wooden-Floor.xpm", w, h);
	if (!game->textures.wall || !game->textures.floor)
		return (0);
	return (1);
}

/*As above, but load collectibles and exit*/
static int	load_objects(t_game *game, int *w, int *h)
{
	game->textures.collectible = mlx_xpm_file_to_image(game->mlx,
			"assets/collectable_shrimp.xpm", w, h);
	game->textures.exit = mlx_xpm_file_to_image(game->mlx,
			"assets/Exit.xpm", w, h);
	if (!game->textures.collectible || !game->textures.exit)
		return (0);
	return (1);
}

/*Load player sprites, for each direction*/
static int	load_player(t_game *game, int *w, int *h)
{
	game->textures.player_up = mlx_xpm_file_to_image(game->mlx,
			"assets/Lich_up.xpm", w, h);
	game->textures.player_down = mlx_xpm_file_to_image(game->mlx,
			"assets/Lich_down.xpm", w, h);
	game->textures.player_left = mlx_xpm_file_to_image(game->mlx,
			"assets/Lich_left.xpm", w, h);
	game->textures.player_right = mlx_xpm_file_to_image(game->mlx,
			"assets/Lich_right.xpm", w, h);
	if (!game->textures.player_up || !game->textures.player_down
		|| !game->textures.player_left || !game->textures.player_right)
		return (0);
	return (1);
}

/*Initializes MinilibX and loads textures. Opens the window and
"draws" the game*/
int	open_image(t_game *game)
{
	int	img_w;
	int	img_h;

	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx,
			game->cols * TILE_SIZE,
			game->rows * TILE_SIZE,
			"so_long");
	if (!game->win)
		return (0);
	if (!load_tiles(game, &img_w, &img_h)
		|| !load_objects(game, &img_w, &img_h)
		|| !load_player(game, &img_w, &img_h))
	{
		write(2, "Error\nFailed to load textures\n", 30);
		return (0);
	}
	return (1);
}
