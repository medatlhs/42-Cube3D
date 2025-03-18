/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:12:12 by achahlao          #+#    #+#             */
/*   Updated: 2025/03/18 16:27:55 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

char	**extract_map_interior(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		if (!contains_only_whitespace(map[i]) && ft_strncmp(map[i], "NO ", 3)
			&& ft_strncmp(map[i], "SO ", 3) && ft_strncmp(map[i], "WE ", 3)
			&& ft_strncmp(map[i], "EA ", 3) && ft_strncmp(map[i], "F ", 2)
			&& ft_strncmp(map[i], "C ", 2))
			break ;
		i++;
	}
	j = i - 1;
	while (map[++j])
	{
		if (map[j][0] == '\n')
			return (ft_putstr_fd("Error:\n\t==>invaliid charcters \n"
					, 2), NULL);
	}
	trim_new_lines(map, i);
	return (&map[i]);
}

static int	is_valid_character(char c)
{
	return (c == '0' || c == '1' || c == 'S' || c == 'N'
		|| c == 'W' || c == 'E' || c == 32);
}

static int	identify_player_index(char c)
{
	char	*characters;
	int		i;

	characters = "NWES";
	i = 0;
	while (characters[i])
	{
		if (c == characters[i])
			return (i);
		i++;
	}
	return (-1);
}

static int	validate_player_count(int player_count)
{
	if (player_count != 1)
	{
		ft_putstr_fd("Error:\n\t==>invalid player\n", 2);
		return (0);
	}
	return (1);
}

int	validate_characters(char **map)
{
	char	**walls;
	int		i;
	int		j;
	int		player_count;

	walls = extract_map_interior(map);
	(1) && (player_count = 0, i = 0);
	if (!walls)
		return (0);
	while (walls[i])
	{
		j = 0;
		while (walls[i][j])
		{
			if (!is_valid_character(walls[i][j]))
				return (ft_putstr_fd("E :\n\t=>invalid characters \n", 2), 0);
			if (identify_player_index(walls[i][j]) >= 0)
				player_count++;
			j++;
		}
		i++;
	}
	return (validate_player_count(player_count) && verifier_murs(walls));
}
