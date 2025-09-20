/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <ilnassi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:52:23 by ilnassi           #+#    #+#             */
/*   Updated: 2025/09/16 16:45:56 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdlib.h>
#include <mlx.h>

int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	exit_game(game, "Game close");
	return (0);
}

/*Handles the Esc and WASD/arrow keys*/
int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	else
		player_movement(game, keycode);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(2, "Error\nUsage: ./so_long maps/map.ber\n", 36);
		return (1);
	}
	ft_bzero(&game, sizeof(t_game));
	if (!validate_game(&game, argv[1]))
		exit_game(&game, "Error\nInvalid map or initialization failed");
	return (0);
}
