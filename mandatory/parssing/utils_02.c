/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahlao <achahlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:49:01 by achahlao          #+#    #+#             */
/*   Updated: 2025/03/20 20:50:30 by achahlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int	obtenir_largeur_max(char **carte, int *hauteur)
{
	int	i;
	int	largeur_max;
	int	longueur;

	(1) && (i = 0, largeur_max = 0);
	if (!carte || !carte[0])
		return (-1);
	while (carte[i])
	{
		longueur = ft_strlen(carte[i]);
		if (longueur > largeur_max)
			largeur_max = longueur;
		i++;
	}
	*hauteur = i;
	return (largeur_max);
}

int	*char_to_int(char **numbers_char)
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

int	*get_colors(char **map, char *str)
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

int	get_max_line(char **map, int *size)
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
