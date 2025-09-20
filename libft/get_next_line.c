/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:21:17 by ilnassi           #+#    #+#             */
/*   Updated: 2025/01/27 15:19:02 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_release(char *s1, const char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	return (temp);
}

char	*ft_fetch_and_store(int fd, char *str)
{
	char	*buf;
	ssize_t	line;

	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	line = 1;
	while (!ft_strchr(str, '\n') && line > 0)
	{
		line = read(fd, buf, BUFFER_SIZE);
		if (line == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[line] = '\0';
		str = ft_strjoin_release(str, buf);
		if (!str)
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	return (str);
}

char	*ft_obtain_line(char *buf)
{
	int		i;
	char	*line;

	i = 0;
	if (!buf || buf[i] == '\0')
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	line = (char *)ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_buffer_update(char *buf)
{
	int		i;
	int		j;
	char	*update;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
		return (free(buf), NULL);
	update = (char *)ft_calloc(ft_strlen(buf) - i, sizeof(char));
	if (!update)
		return (free(buf), NULL);
	i++;
	j = 0;
	while (buf[i])
		update[j++] = buf[i++];
	free(buf);
	return (update);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_fetch_and_store(fd, buf);
	if (buf == NULL)
		return (NULL);
	line = ft_obtain_line(buf);
	buf = ft_buffer_update(buf);
	if (!line)
	{
		free(buf);
		buf = NULL;
	}
	return (line);
}
/*
int	main(void)
{
	int	fd;
	char		*line;

	fd = open("prova.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
