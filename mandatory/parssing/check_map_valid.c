/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahlao <achahlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:12:12 by achahlao          #+#    #+#             */
/*   Updated: 2025/03/10 01:17:17 by achahlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parssing.h"
#include "get_nextline_/get_next_line.h"
#include "../../libft/libft.h"


// static int	is_charcters(char c)
// {
// 	return (c == '0' || c == '1' || c == 'S'
// 		|| c == 'N' || c == 'W' || c == 'E'
// 		|| (c == 32));
// }

// static int	get_index_player(char c)
// {
// 	char	*str;
// 	int		i;

// 	i = -1;
// 	str = "NWES";
// 	while (str[++i])
// 	{
// 		if (ft_strchr(str, c))
// 			return (i);
// 	}
// 	return (-1);
// }

// static int	count_player_charcters(int count_player)
// {
// 	if (count_player != 1)
// 		return (ft_putstr_fd("Error:\n\t==>invalid player\n", 2), 0);
// 	return (1);
// }

// int	ft_check_charcters(char **map, char **(*fun2)(char **map))
// {
// 	int		i;
// 	int		j;
// 	char	**walls;
// 	int		player;
// 	int		index;

// 	walls = fun2(map);
// 	if (!walls)
// 		return (0);
// 	(1) && (i = -1, player = 0);
// 	while (walls[++i])
// 	{
// 		j = -1;
// 		while (walls[i][++j])
// 		{
// 			index = get_index_player(walls[i][j]);
// 			if (!is_charcters(walls[i][j]))
// 				return (ft_putstr_fd("Error:\n\t==>invalid charcters \n"
// 						, 2), 0);
// 			else if (index >= 0)
// 				player++;
// 		}
// 	}
// 	return (count_player_charcters(player));
// }














void trim_new_lines(char **map, int index)
{
	while (map[index])
	{
		if (map[index][ft_strlen(map[index]) - 1] == '\n')
			map[index][ft_strlen(map[index]) - 1] = '\0';
		index++;
	}
}
static int contains_only_whitespace(char *str)
{
	size_t i = 0;

	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	return (i == ft_strlen(str));
}

char **extract_map_interior(char **map)
{
	int i = 0;
	int j;

	while (map[i])
	{
		if (!contains_only_whitespace(map[i]) && ft_strncmp(map[i], "NO ", 3) &&
			ft_strncmp(map[i], "SO ", 3) && ft_strncmp(map[i], "WE ", 3) &&
			ft_strncmp(map[i], "EA ", 3) && ft_strncmp(map[i], "F ", 2) &&
			ft_strncmp(map[i], "C ", 2))
			break;
		i++;
	}
	j = i - 1;
	while (map[++j])
	{
		if (map[j][0] == '\n')
			return (ft_putstr_fd("Error:\n\t==>invaliiiiid charcters \n"
					, 2), NULL);
	}
	trim_new_lines(map, i);
	return (&map[i]);
}



static int is_valid_character(char c)
{
	return (c == '0' || c == '1' || c == 'S' || c == 'N' || c == 'W' || c == 'E' || c == 32);
}

static int identify_player_index(char c)
{
	char *characters = "NWES";
	int i = 0;

	while (characters[i])
	{
		if (c == characters[i])
			return (i);
		i++;
	}
	return (-1);
}

static int validate_player_count(int player_count)
{
	if (player_count != 1)
	{
		ft_putstr_fd("Error:\n\t==>invalid player\n", 2);
		return (0);
	}
	return (1);
}

void afficher_tableau(char **str)
{
    int i = 0;

    while (str && str[i])
    {
        printf("%s  ---------%zu\n", str[i], ft_strlen(str[i]));
        i++;
    }
}


void	free_map(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}
int validate_characters(char **map)
{
	int i, j, player_count = 0;
	char **walls;
	printf("-----------------------------------------------------------------------------------------\n");
	
	// afficher_tableau(map);
	printf("-----------------------------------------------------------------------------------------\n");
	walls = extract_map_interior(map);
	printf("maaaap seul\n");
	// afficher_tableau(walls);
	printf("-----------------------------------------------------------------------------------------\n");

	if (!walls)
		return (0);
	i = 0;
	while (walls[i])
	{
		j = 0;
		while (walls[i][j])
		{
			if (!is_valid_character(walls[i][j]))
			{
				ft_putstr_fd("Error:\n\t==>invalid characters \n", 2);
				return (0);
			}
			if (identify_player_index(walls[i][j]) >= 0)
				player_count++;
			j++;
		}
		i++;
	}
	return (validate_player_count(player_count) && verifier_murs(walls));
}

// static int contains_only_whitespace(char *str)
// {
// 	size_t i = 0;

// 	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
// 		i++;
// 	return (i == ft_strlen(str));
// }


