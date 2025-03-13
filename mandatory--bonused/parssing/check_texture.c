/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahlao <achahlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:45:01 by achahlao          #+#    #+#             */
/*   Updated: 2025/03/06 12:36:40 by achahlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parssing.h"
#include "get_nextline_/get_next_line.h"


char *textures[] = {
    "NO ",
    "SO ",
    "WE ",
    "EA ",
    NULL
};


// static char	**get_textures(void)
// {
// 	char	**textures;

// 	textures = malloc(sizeof(char *) * 5);
// 	if (!textures)
// 		return (NULL);
// 	textures[0] = "NO ";
// 	textures[1] = "SO ";
// 	textures[2] = "WE ";
// 	textures[3] = "EA ";
// 	textures[4] = NULL;
// 	return (textures);
// }


static int get_index_texture(char *str)
{
    int i;
	
	
    i = -1;
    while (textures[++i])
    {
        if (!ft_strncmp(str, textures[i], 3))
            return (i);
    }
    return (-1);  // Texture non trouvée
}


// static int	get_index_texture(char *str)
// {
// 	int		i;
// 	char	**textures;

// 	i = -1;
// 	textures = get_textures();
// 	if (!textures)
// 		return (-1);
// 	while (textures[++i])
// 		if (!ft_strncmp(str, textures[i], 3))
// 			return (free(textures), i);
// 	return (free(textures), -1);
// }

static int	check_count(int *tab)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		if (tab[i] > 1 || tab[i] == 0)
			return (ft_putstr_fd("Error:\n\t==>invalid textures\n", 2), 0);
	}
	return (1);
}
static int	check_espace(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == 32 || str[i] == '\t')
			return (0);
	return (1);
}

int check_texture(char **map)
{
    int i;
    int count_textures[4] = {0};
    int index_texture;

    for (i = 0; map[i] != NULL; i++)
    {
        index_texture = get_index_texture(map[i]);

        if (index_texture >= 0)
            count_textures[index_texture]++;
        else if (!(strncmp(map[i], "F ", 2) == 0 || strncmp(map[i], "C ", 2) == 0 || check_espace(map[i]) == 1))
            break;
    }
	for(int j= 0; j < 4; j++)
	{
		printf("%d~~~~~~~~~> %d\n",j,count_textures[j]);
	}
    return check_count(count_textures);
}