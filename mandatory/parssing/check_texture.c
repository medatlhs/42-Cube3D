/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahlao <achahlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:45:01 by achahlao          #+#    #+#             */
/*   Updated: 2025/03/20 20:49:49 by achahlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

static int	get_index_texture(char *str)
{
	int		i;
	char	*textures[5];

	textures[0] = "NO ";
	textures[1] = "SO ";
	textures[2] = "WE ";
	textures[3] = "EA ";
	textures[4] = NULL;
	i = -1;
	while (textures[++i])
	{
		if (!ft_strncmp(str, textures[i], 3))
			return (i);
	}
	return (-1);
}

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

int	check_texture(char **map)
{
	int	index_texture;
	int	count_textures[4];
	int	i;

	(1) && (ft_bzero(count_textures, 16), i = -1);
	while (map[++i])
	{
		index_texture = get_index_texture(map[i]);
		if (index_texture >= 0)
			count_textures[index_texture]++;
		else if (!(ft_strncmp(map[i], "F ", 2) == 0 \
			|| ft_strncmp(map[i], "C ", 2) == 0 || check_espace(map[i]) == 1))
			break ;
	}
	return (check_count(count_textures));
}
	// for(int j= 0; j < 4; j++)
	// {
	// 	printf("%d~~~~~~~~~> %d\n",j,count_textures[j]);
	// }