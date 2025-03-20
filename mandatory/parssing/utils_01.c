/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahlao <achahlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:48:51 by achahlao          #+#    #+#             */
/*   Updated: 2025/03/20 20:50:25 by achahlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	trim_new_lines(char **map, int index)
{
	while (map[index])
	{
		if (map[index][ft_strlen(map[index]) - 1] == '\n')
			map[index][ft_strlen(map[index]) - 1] = '\0';
		index++;
	}
}

int	contains_only_whitespace(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	return (i == ft_strlen(str));
}

int	get_num_columns(char *row)
{
	int	columns;

	columns = 0;
	while (row[columns] != '\0')
		columns++;
	return (columns);
}

int	get_num_rows(char **map)
{
	int	rows;

	rows = 0;
	while (map[rows] != NULL)
		rows++;
	return (rows);
}

char	*add_spaces(char *str, int size)
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
