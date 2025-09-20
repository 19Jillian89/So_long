/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_allocate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <ilnassi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 00:42:36 by ilnassi           #+#    #+#             */
/*   Updated: 2025/09/17 18:02:52 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Free copy of the map used in the various controls*/
void	free_map_cpy(t_game *game)
{
	int	i;

	if (game->map_cpy)
	{
		i = 0;
		while (i < game->rows)
		{
			if (game->map_cpy[i])
				free(game->map_cpy[i]);
			i++;
		}
		free(game->map_cpy);
		game->map_cpy = NULL;
	}
}

/*Generic function to free a generic map passed as a parameter*/
void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

/*Free the main map (game->map)*/
void	free_map_main(t_game *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (i < game->rows)
		{
			if (game->map[i])
				free(game->map[i]);
			i++;
		}
		free(game->map);
		game->map = NULL;
	}
}

/*Function that clears everything: clears map, copy, images, window.
Leaves everything clean when I close the game.*/
void	depurate(t_game *game)
{
	if (game->map)
		free_map_main(game);
	if (game->map_cpy)
		free_map_cpy(game);
	if (game->mlx && game->win)
	{
		free_textures(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
	}
	if (game->mlx)
		free(game->mlx);
}
