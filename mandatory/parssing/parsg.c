/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahlao <achahlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 04:19:17 by achahlao          #+#    #+#             */
/*   Updated: 2025/03/12 15:35:02 by achahlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parssing.h"
#include "get_nextline_/get_next_line.h"
#include "../include/cube.h"
#include "../include/struct.h"

static int	get_size(char *file)
{
	char	*tmp;
	int		count;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (0);
	}
	count = 0;
	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		count++;
		tmp = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**get_map(char *file)
{
	char	**map;
	char	*line;
	int		size;
	int		fd;
	int		i;

	size = get_size(file);
	if (!size)
		return (ft_putstr_fd("Error :\n\t==>empty file", 2), NULL);
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (perror("malloc"), NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (perror("open"), NULL);
	(1) && (line = get_next_line(fd), i = 0);
	while (line)
	{
		map[i] = ft_strdup(line);
		if (!map[i])
			return (perror("malloc"), free_mat(map), close(fd), NULL);
		free(line);
		(1) && (line = get_next_line(fd), i++);
	}
	return (map[i] = NULL, close(fd), map);
}

char	**parsing(char *file)
{
	char	**map;

	if (ft_strncmp(file + ft_strlen(file) - 4, ".cub", 4))
		return (ft_putstr_fd("Error:\n\t=>invalid extantion .cub\n", 2), NULL);
	map = get_map(file);
	if (!map)
		return (NULL);
	if (check_texture(map)
		&& check_colors(map)
		&& validate_characters(map))
		return (map);
	return (free_mat(map), NULL);
}
