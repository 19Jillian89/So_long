/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:07:16 by ilnassi           #+#    #+#             */
/*   Updated: 2025/09/16 16:41:44 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Checks that the map is rectangular, takes the length of the first line
and compares all the others. If incorrect: Error.*/
int	check_rectangle(t_game *game, int rows)
{
	int	y;
	int	len;

	y = 0;
	if (rows <= 0)
		return (0);
	len = (int)ft_strlen(game->map[0]);
	while (y < rows)
	{
		if ((int)ft_strlen(game->map[y]) != len)
		{
			ft_printf("Error! Map lines are not the same!\n");
			return (0);
		}
		y++;
	}
	ft_printf("The map is rectangular.\n");
	return (1);
}

/*Check that the map is enclosed by walls, check that the first and last
rows are all '1', and the same goes for the column.*/
int	check_all_walls(t_game *game, int rows)
{
	int	y;
	int	x;

	x = 0;
	while (game->map[0][x])
		if (game->map[0][x++] != '1')
			return (ft_printf("Invalid! Top wall not closed.\n"), 0);
	x = 0;
	while (game->map[rows - 1][x])
		if (game->map[rows - 1][x++] != '1')
			return (ft_printf("Invalid! Bottom wall not closed.\n"), 0);
	y = 0;
	while (y < rows)
	{
		if (game->map[y][0] != '1' ||
			game->map[y][ft_strlen(game->map[y]) - 1] != '1')
			return (ft_printf("Invalid! Vertical wall not closed.\n"), 0);
		y++;
	}
	ft_printf("Hurray! The map lines are closed!\n");
	return (1);
}
