/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:49:20 by achahlao          #+#    #+#             */
/*   Updated: 2025/03/18 16:27:55 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	afficher_tableau(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		printf("%s  ---------%zu ----------- %p\n"\
			, str[i], ft_strlen(str[i]), str[i]);
		i++;
	}
}

void	affiche_color(int *tab, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		printf("%d ----------- %p \n", tab[i], tab);
	}
	printf("\n");
}

void	print_textures(t_txture *textures)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		printf("Key: %s\n", textures[i].key);
		printf("Path: %s\n\n", textures[i].path);
		i++;
	}
}
