/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_setting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <ilnassi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:54:13 by ilnassi           #+#    #+#             */
/*   Updated: 2025/09/13 02:05:23 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*"Draw" the player sprite based on the key pressed*/
void	movement_key(t_game *game, int col, int row)
{
	if (game->keycode == KEY_W || game->keycode == KEY_UP)
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.player_up, col * TILE_SIZE, row * TILE_SIZE);
	else if (game->keycode == KEY_S || game->keycode == KEY_DOWN)
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.player_down, col * TILE_SIZE, row * TILE_SIZE);
	else if (game->keycode == KEY_A || game->keycode == KEY_LEFT)
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.player_left, col * TILE_SIZE, row * TILE_SIZE);
	else if (game->keycode == KEY_D || game->keycode == KEY_RIGHT)
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.player_right, col * TILE_SIZE, row * TILE_SIZE);
}

/*If the player reaches the exit, I check to see if they've collected 
everything. If so, I win; otherwise, no + msg*/
static void	handle_exit(t_game *game)
{
	if (game->collectible_count == 0)
		exit_game(game, "Well done! You won!");
	else
		ft_printf("You can't exit yet, collectibles remaining!\n");
}

/*function that moves the player and manages what happens in a cell*/
void	ft_move(t_game *game, int x, int y)
{
	char	target;

	target = game->map[y][x];
	if (target == 'C')
		game->collectible_count--;
	else if (target == 'E')
	{
		handle_exit(game);
		return ;
	}
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = x;
	game->player_y = y;
	game->map[y][x] = 'P';
	game->moves++;
	ft_printf("Count step: %d\n", game->moves);
}

/*Function that reads keyboard input and moves the player*/
void	player_movement(t_game *game, int keycode)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	game->keycode = keycode;
	if (keycode == 119 || keycode == 65362)
		new_y--;
	else if (keycode == 115 || keycode == 65364)
		new_y++;
	else if (keycode == 97 || keycode == 65361)
		new_x--;
	else if (keycode == 100 || keycode == 65363)
		new_x++;
	if (game->map[new_y][new_x] == '1')
		return ;
	ft_move(game, new_x, new_y);
	draw_map(game, game->map, game->moves);
	movement_key(game, game->player_x, game->player_y);
}
