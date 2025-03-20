/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing_final.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:30:24 by achahlao          #+#    #+#             */
/*   Updated: 2025/03/20 16:09:57 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

static char	**make_map_rectangle(char **map)
{
	int		i;
	int		max_line;
	char	**new_map;
	char	**walls;
	int		size;

	if (!*map || !map)
		return (NULL);
	walls = extract_map_interior(map);
	(1) && (max_line = get_max_line(walls, &size), i = 0);
	if (max_line < 0)
		return (ft_putstr_fd("Error:\n\t==> there is no map\n", 2), NULL);
	new_map = malloc(sizeof(char *) * (size + 1));
	if (!new_map)
		return (NULL);
	i = -1;
	while (walls[++i])
	{
		new_map[i] = add_spaces(walls[i], max_line);
		if (!new_map[i])
			return (free_mat(new_map), perror("memory problem"), NULL);
	}
	new_map[size] = NULL;
	return (new_map);
}

static int	get_index_textures(char *str)
{
	char	**split_textures;
	char	*postion;
	int		i;

	postion = "NO,WE,EA,SO";
	split_textures = ft_split(postion, ',');
	if (!split_textures)
		return (-1);
	i = -1;
	while (split_textures[++i])
	{
		if (!ft_strncmp(str, split_textures[i], 2))
			return (free_mat(split_textures), i);
	}
	return (free_mat(split_textures), -1);
}

t_txture	*parse_texture(char *line)
{
	t_txture	*texture;
	int			j;

	texture = malloc(sizeof(t_txture));
	j = 2;
	if (!texture)
		return (NULL);
	texture->key = ft_substr(line, 0, 2);
	if (!texture->key)
	{
		free(texture);
		return (NULL);
	}
	while (line[j] && line[j] == ' ')
		j++;
	texture->path = ft_strdup(&line[j]);
	if (!texture->path)
	{
		free(texture->key);
		free(texture);
		return (NULL);
	}
	texture->path[ft_strlen(texture->path) - 1] = '\0';
	return (texture);
}

t_txture	*get_textures(char **map)
{
	t_txture	*parsed_texture;
	t_txture	*textures;
	int			i;
	int			count_textures;
	int			index;

	(1) && (i = 0, count_textures = 0);
	textures = malloc(sizeof(t_txture) * 4);
	if (!textures)
		return (NULL);
	while (map[i] && count_textures < 4)
	{
		index = get_index_textures(map[i]);
		if (index != -1)
		{
			parsed_texture = parse_texture(map[i]);
			if (!parsed_texture)
				return (free(textures), NULL);
			textures[index] = *parsed_texture;
			free(parsed_texture);
			count_textures++;
		}
		i++;
	}
	return (textures);
}

int	parsing_final(char	*file, t_cube	*cub)
{
	char	**new_map;

	new_map = parsing(file);
	cub->map = malloc(sizeof(t_map));
	if (!cub->map || !new_map)
		return (free_mat(new_map), 0);
	cub->map->c = get_colors(new_map, "C ");
	if (!cub->map->c)
		return (free_mat(new_map), 0);
	cub->map->f = get_colors(new_map, "F ");
	if (!cub->map->f)
		return (free(cub->map->c),
			free_mat(new_map), 0);
	cub->map->textur = get_textures(new_map);
	if (!cub->map)
		return (free(cub->map->c), free(cub->map->f),
			free_mat(new_map), 0);
	cub->map->map = make_map_rectangle(new_map);
	if (!cub->map->map)
		return (free(cub->map->c), free(cub->map->f),
			free_mat(new_map), 0);
	cub->map->row = get_num_rows(cub->map->map);
	cub->map->colum = get_num_columns(cub->map->map[0]);
	return (free_mat(new_map), 1);
}
