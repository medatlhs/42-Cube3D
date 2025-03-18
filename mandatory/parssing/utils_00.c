/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:51:08 by achahlao          #+#    #+#             */
/*   Updated: 2025/03/18 16:28:07 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int	ft_prsg_atoi(const char *str)
{
	int	index;
	int	result;
	int	sign;

	(1) && (index = 0, result = 0, sign = 1);
	while (str[index] == ' ' || (str[index] >= '\t' && str[index] <= '\r'))
		index++;
	if (str[index] == '-')
		return (-1);
	else if (str[index] == '+')
		index++;
	if (str[index] == '\0')
		return (-1);
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = result * 10 + (str[index] - '0');
		if (result > 255)
			return (-1);
		index++;
	}
	if (str[index] != '\0' && str[index] != '\n')
		return (-1);
	return (sign * result);
}

void	free_mat(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

int	is_texture(char *str)
{
	return (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "SO ", 3)
		|| !ft_strncmp(str, "WE ", 3) || !ft_strncmp(str, "EA ", 3));
}

int	has_spaces_or_tabs(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == 32 || str[i] == '\t')
			return (1);
	}
	return (0);
}

int	is_textures(char *str)
{
	return (!has_spaces_or_tabs(str) || is_texture(str));
}
