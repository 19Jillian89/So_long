/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <ilnassi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:59:31 by ilnassi           #+#    #+#             */
/*   Updated: 2025/09/17 18:03:13 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Free up the memory of textures loaded by MinilibX, to avoid
memory leaks when I close the game*/
void	free_textures(t_game *game)
{
	if (game->textures.wall)
		mlx_destroy_image(game->mlx, game->textures.wall);
	if (game->textures.floor)
		mlx_destroy_image(game->mlx, game->textures.floor);
	if (game->textures.player_up)
		mlx_destroy_image(game->mlx, game->textures.player_up);
	if (game->textures.player_down)
		mlx_destroy_image(game->mlx, game->textures.player_down);
	if (game->textures.player_left)
		mlx_destroy_image(game->mlx, game->textures.player_left);
	if (game->textures.player_right)
		mlx_destroy_image(game->mlx, game->textures.player_right);
	if (game->textures.collectible)
		mlx_destroy_image(game->mlx, game->textures.collectible);
	if (game->textures.exit)
		mlx_destroy_image(game->mlx, game->textures.exit);
}

/*Function that checks whether the map is valid, images are loaded, and the
structure is initialized*/
int	validate_game(t_game *game, char *filename)
{
	if (!map_load(filename, game))
		return (0);
	set_map_size(game, game->map);
	if (!check_valid_map(game))
		return (0);
	if (!open_image(game))
		return (0);
	if (!init_game(game))
		return (0);
	return (1);
}

/*Closes the game, freeing up memory and resources*/
int	exit_game(t_game *game, char *msg)
{
	if (msg)
		ft_printf("%s\n", msg);
	depurate(game);
	exit(EXIT_SUCCESS);
	return (0);
}
