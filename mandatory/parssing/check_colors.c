/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahlao <achahlao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:45:22 by achahlao          #+#    #+#             */
/*   Updated: 2025/03/02 13:58:12 by achahlao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parssing.h"
#include "get_nextline_/get_next_line.h"
#include "../../libft/libft.h"

int	ft_atoi1(const char *str)
{
	int		i;
	int		r;
	int		s;

	(1) && (i = 0, r = 0, s = 1);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
		return (-1);
	else if (str[i] == '+')
		i++;
	if (!str[i])
		return (-1);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		r = r * 10 + str[i] - '0';
		if (r > 255)
			return (-1);
		i++;
	}
	if ((str[i] && str[i] != '\n') || r > 255 || r < 0)
		return (-1);
	return (s * r);
}
void	free_mat(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

static int is_texture(char *str)
{
    return (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "SO ", 3) 
        || !ft_strncmp(str, "WE ", 3) || !ft_strncmp(str, "EA ", 3));
}

static int has_spaces_or_tabs(char *str)
{
    int i = -1;
    
    while (str[++i])
    {
        if (str[i] == 32 || str[i] == '\t')
            return 1;
    }
    return 0;
}

static int is_textures(char *str)
{
    return (!has_spaces_or_tabs(str) || is_texture(str));
}

static int	check_syntax_color(char *str)
{
	char	**rgb;
	int		i;

	i = 1;
	while (str[i] && ((str[i] >= 9 && str[i] <= 12) || str[i] == 32))
		i++;
	rgb = ft_split(&str[i], ',');
	if (!rgb)
		return (ft_putstr_fd("Error\n\t", 2),
			perror("==> malloc"), free_mat(rgb), 0);
	i = -1;
	while (rgb[++i] && i < 4)
	{
		if (((rgb[i][0] >= 9 && rgb[i][0] <= 12) || rgb[i][0] == 32)
				|| (rgb[i][0] != '\n' && ft_atoi1(rgb[i]) < 0)
				|| rgb[i][0] < '0' || rgb[i][0] > '9')
			return (ft_putstr_fd("Error : \n\t =>invsalid RGB colors\n", 2),
				free_mat(rgb), 0);
	}
	if (i != 3)
		return (ft_putstr_fd("Error : \n\t =>invdalid RGB colors\n", 2),
			free_mat(rgb), 0);
	return (free_mat(rgb), 1);
}

static int	incr_colors(int *nb1, int *nb2, char *str)
{
	int		i;
	int		virgul;

	if ((!ft_strncmp(str, "C ", 2) || !ft_strncmp(str, "F ", 2)) && (!check_syntax_color(str)))
		return (0);
	(1) && (i = -1, virgul = 0);
	while (str[++i])
		if (str[i] == ',')
			virgul++;
	if (virgul > 2)
		return (ft_putstr_fd("Error:\n\t=>invtalid RGB colors\n", 2), 0);
	if (!ft_strncmp(str, "F ", 2))
		*nb1 += 1;
	else if (!ft_strncmp(str, "C ", 2) )
		*nb2 += 1;
	return (1);
}

static int	check_count_color(int *tab)
{
	int		i;

	i = -1;
	while (++i < 2)
	{
		if (tab[i] > 1 || tab[i] == 0)
			return (ft_putstr_fd("Error:\n\t=>inevalid RGB colors\n", 2), 0);
	}
	return (1);
}


static int is_color_prefix(char *str)
{
    return (!ft_strncmp(str, "F ", 2) || !ft_strncmp(str, "C ", 2));
}


int check_colors(char **map)
{
    int colors[2];
    int i;

    i = -1;
    ft_bzero(colors, 8);
    while (map[++i])
    {
        if (!is_textures(map[i]) && !is_color_prefix(map[i]))
            break ;
        if (!incr_colors(&colors[0], &colors[1], map[i]))
            return (0);
    }
    return (check_count_color(colors));
}
