/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <ilnassi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:01:09 by ilnassi           #+#    #+#             */
/*   Updated: 2025/09/17 18:03:04 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include "libft.h"

# define TILE_SIZE 64

enum	e_keys
{
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_ESC = 65307,
	KEY_UP = 65362,
	KEY_LEFT = 65361,
	KEY_DOWN = 65364,
	KEY_RIGHT = 65363
};

typedef struct s_textures
{
	void	*player_up;
	void	*player_down;
	void	*player_left;
	void	*player_right;
	void	*wall;
	void	*floor;
	void	*collectible;
	void	*exit;
}	t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	char		**map_cpy;
	int			keycode;
	int			rows;
	int			cols;
	int			tile;
	int			player_x;
	int			player_y;
	int			index;
	int			collectible_count;
	int			player_count;
	int			exit_count;
	int			moves;
	int			coll_fill_found;
	int			exit_reached;
	t_textures	textures;
}	t_game;

int		init_game(t_game *game);
int		map_load(char *filename, t_game *game);
int		open_image(t_game *game);
int		close_window(void *param);
int		key_hook(int keycode, t_game *game);
int		check_rectangle(t_game *game, int rows);
int		check_all_walls(t_game *game, int rows);
int		check_pce(t_game *game);
int		exit_game(t_game *game, char *msg);
int		check_valid_chars(t_game *game);
int		check_valid_map(t_game *game);
int		check_path(t_game *game);
int		validate_game(t_game *game, char *filename);
void	free_map(char **map);
void	handle_player_move(t_game *game, int keycode);
void	start_game(t_game *game);
void	player_movement(t_game *game, int keycode);
void	draw_map(t_game *game, char **map, int moves);
void	movement_key(t_game *game, int col, int row);
void	ft_move(t_game *game, int x, int y);
void	set_map_size(t_game *game, char **map);
void	free_map_cpy(t_game *game);
void	free_textures(t_game *game);
void	free_map_main(t_game *game);
void	depurate(t_game *game);

#endif
