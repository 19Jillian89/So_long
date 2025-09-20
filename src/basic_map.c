/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <ilnassi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:56:19 by ilnassi           #+#    #+#             */
/*   Updated: 2025/08/30 12:17:20 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Reads the entire contents of the map file (.ber) line by line with get_next,
concatenates it, and saves it as a single string*/
static char	*read_content(int fd)
{
	char	*line;
	char	*content;
	char	*tmp;

	content = ft_calloc(1, 1);
	if (!content)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strjoin(content, line);
		free(content);
		free(line);
		if (!tmp)
			return (NULL);
		content = tmp;
		line = get_next_line(fd);
	}
	return (content);
}

/*From the string get the "2D map"*/
static char	**map_content(char *content)
{
	char	**map;

	map = ft_split(content, '\n');
	free(content);
	return (map);
}

/*Load map from file into t_game structure *game*/
int	map_load(char *filename, t_game *game)
{
	int		fd;
	char	*content;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	content = read_content(fd);
	close(fd);
	if (!content)
		return (0);
	map = map_content(content);
	if (!map)
		return (0);
	game->map = map;
	return (1);
}

/*Calculate map dimensions (rows and columns).
I count how many rows there are, and if there are any, I take the length
of the first row as cols*/
void	set_map_size(t_game *game, char **map)
{
	int	rows;

	rows = 0;
	while (map[rows])
		rows++;
	game->rows = rows;
	if (rows > 0)
		game->cols = (int)ft_strlen(map[0]);
	else
		game->cols = 0;
}
