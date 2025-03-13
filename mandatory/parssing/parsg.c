/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 04:19:17 by achahlao          #+#    #+#             */
/*   Updated: 2025/03/13 08:42:47 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parssing.h"
#include "get_nextline_/get_next_line.h"
#include "../include/cube.h"
#include "../include/struct.h"



static int	*char_to_int(char **numbers_char)
{
	int		*numbers_int;
	int		i;
	int		j;

	numbers_int = malloc(sizeof(int) * 3);
	if (!numbers_int)
		return (NULL);
	i = -1;
	j = 1;
	while (numbers_char[++i] && j < 3)
	{
		if (i == 0)
		{
			j = 1;
			while (numbers_char[i][j] && numbers_char[i][j] != 32)
				j++;
			numbers_int[0] = ft_atoi(&numbers_char[i][j]);
			j = 1;
		}
		else
			numbers_int[j++] = ft_atoi(numbers_char[i]);
	}
	return (free_mat(numbers_char), numbers_int);
}

static int	*get_colors(char **map, char *str)
{
	int		i;
	char	**split_numbers;
	int		j;

	i = -1;
	while (map[++i])
	{
		if (!ft_strncmp(str, map[i], 2))
		{
			j = -1;
			split_numbers = ft_split(map[i], ',');
			if (!split_numbers)
				return (NULL);
			return (char_to_int(split_numbers));
		}
	}
	return (NULL);
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

static char	**get_textures(char **map)
{
	char	**textures;
	int		j;
	int		i;
	int		count_textures;
	int		index;

	textures = malloc(sizeof(char *) * 5);
	if (!textures)
		return (NULL);
	(1) && (i = -1, count_textures = 0);
	while (map[++i] && count_textures <= 4)
	{
		index = get_index_textures(map[i]);
		if (index != -1)
		{
			(1) && (j = 2, count_textures++);
			while (map[i][j] && map[i][j] == 32)
				j++;
			textures[index] = ft_strdup(&map[i][j]);
			if (!textures[index])
				return (free_mat(textures), NULL);
			textures[index][ft_strlen(textures[index]) - 1] = '\0';
		}
	}
	return (textures[count_textures] = NULL, textures);
}



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
	while ((tmp = get_next_line(fd)))
	{
		free(tmp);
		count++;
	}
	close(fd);
	return (count);
}

void print_lines(char **lines, size_t num_lines) {
	size_t i = 0;
    while ( i < num_lines) {
        printf("%s", lines[i]);
		i++;
    }
}




void free_lines(char **lines, size_t num_lines) {
    for (size_t i = 0; i < num_lines; i++) {
        free(lines[i]);
    }
    free(lines);
}


// static int is_valid_line(char *line) {
//     return (line[0] != ' ' && line[0] != '1');
// }


static void	free_index(char **map)
{
	int		i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}
















char **get_map(char *file)
{
	char	**map;
	char *line;
	int size, fd,i;
	
	printf("filesss ____> %s \n", file);
	size = get_size(file);
	
	printf("111111----> %d\n", size);
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
			return (perror("malloc"), free_index(map), close(fd), NULL);
		free(line);
		(1) && (line = get_next_line(fd), i++);
	}
	return (map[i] = NULL, close(fd), map);
}
char  **parsing(char *file)
{
		char **map;
	

		// if (ft_strncmp(file + ft_strlen(file) - 4, ".cub", 4))
		// 	return (ft_putstr_fd("Error:\n\t=>invalid extantion .cub\n", 2), NULL);
		// printf("ddddddd");
		map= get_map(file);
		if (!map)
			return (NULL);
		if (check_texture(map)
		&& check_colors(map)
		&& validate_characters(map))
			return (map);

		printf("HHHHHHHHHHHHHHH\n");

   		return (free_map(map), NULL);
}




static int	get_max_line(char **map, int *size)
{
	int		i;
	int		max_line;
	int		len;

	(1) && (i = -1, max_line = -1);
	if (!map || !map[0])
		return (-1);
	while (map[++i])
	{
		len = ft_strlen(map[i]);
		if (len > max_line)
			max_line = len;
	}
	return (*size = i, max_line);
}

static char	*add_spaces(char *str, int size)
{
	int		i;
	char	*tmp;

	tmp = malloc(sizeof(char) * (size + 1));
	if (!tmp)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		tmp[i] = str[i];
	while (i < size)
		tmp[i++] = 32;
	tmp[size] = '\0';
	return (tmp);
}


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

int get_num_columns(char *row)
{
    int columns = 0;
    while (row[columns] != '\0') // Counts until the end of the row (NULL terminator)
    {
        columns++;
    }
    return columns;
}


int get_num_rows(char **map)
{
    int rows = 0;
    while (map[rows] != NULL) // Iterates until the end of the map (NULL)
    {
        rows++;
    }
    return rows;
}

void affiche_color(int *tab, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d \n", tab[i]);
    }
    printf("\n");
}
int parsing_final(char *file , t_cube *cub)
{
    char **new_map;
	// int 

    // (void)cub;

    new_map = parsing(file);
    if (!new_map)
        return (1);
	cub->map = malloc(sizeof(t_map));
    if (!cub->map)
    {
        free_mat(new_map);
        return 1;
    }
	cub->map->C = get_colors(new_map, "C ");
	if (!cub->map->C)
		return (free_mat(new_map), 0);
	cub->map->F = get_colors(new_map, "F ");
	if (!cub->map->F)
		return (free(cub->map->C),
			free_mat(new_map), 0);
	cub->map->textures = get_textures(new_map);
	if (!cub->map->textures)
		return (free(cub->map->C), free(cub->map->F),
			free_mat(new_map), 0);
	cub->map->map = make_map_rectangle(new_map);
	if (!cub->map->map)
		return (free(cub->map->C), free(cub->map->F),
			free_mat(cub->map->textures), free_mat(new_map), 0);
	cub->map->row = get_num_rows(cub->map->map);
	cub->map->colum = get_num_columns(cub->map->map[0]);
	printf("\n\n----------------colors   F -----------------------\n");
	
	printf("\t nbr row est : %d\t\n", cub->map->row);
	printf("\n\n----------------colors   F -----------------------\n");

	printf("\t nbr row est : %d\t\n", cub->map->colum);
	printf("\n\n----------------colors   F -----------------------\n\n\n");
	affiche_color(cub->map->F,3);
	printf("\n\n----------------colors    C -----------------------\n");
	affiche_color(cub->map->C ,3);

	printf("\n\n----------------textures -----------------------\n\n\n");
	afficher_tableau(cub->map->textures);

	printf("\n\n----------------Maap   -----------------------\n\n\n");
	afficher_tableau(cub->map->map);
	return (free_mat(new_map), 1);
}




//  int main()
//  {

// 	t_cube cube;
	

	
// 	if (parsing_final("test.cub", &cube))
// 		return (1);
// 	// afficher_tableau(cube.map->map);
	
//     return 0;
// } 