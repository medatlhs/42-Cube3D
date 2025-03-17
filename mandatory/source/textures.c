/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:28:53 by moait-la          #+#    #+#             */
/*   Updated: 2025/03/17 17:35:58 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	load_textures(t_cube *cube)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (!ft_strncmp(cube->map->textur[i].key, "NO", 2))
			cube->texture->no = mlx_load_png(cube->map->textur[i].path);
		else if (!ft_strncmp(cube->map->textur[i].key, "EA", 2))
			cube->texture->ea = mlx_load_png(cube->map->textur[i].path);
		else if (!ft_strncmp(cube->map->textur[i].key, "WE", 2))
			cube->texture->we = mlx_load_png(cube->map->textur[i].path);
		else if (!ft_strncmp(cube->map->textur[i].key, "SO", 2))
			cube->texture->so = mlx_load_png(cube->map->textur[i].path);
	}
	if (!cube->texture->no || !cube->texture->ea
		|| !cube->texture->we || !cube->texture->so)
		ft_error("Error: failed to load textures");
}

mlx_texture_t	*get_texture(t_cube cube, t_ray ray)
{
	if (ray.closest_hit == HORIZONTAL)
	{
		if (ray.ray_angle < M_PI && ray.ray_angle > 0)
			return (cube.texture->no);
		else
			return (cube.texture->so);
	}
	else if (ray.closest_hit == VERTICAL)
	{
		if (ray.ray_angle > (M_PI / 2) && ray.ray_angle < 3 * (M_PI / 2))
			return (cube.texture->ea);
		else
			return (cube.texture->we);
	}
	return (NULL);
}

float	get_texture_x(t_cube data, int colom)
{
	float	texture_x;
	float	pos_in_wall;

	if (data.ray[colom].closest_hit == HORIZONTAL)
		pos_in_wall = fmodf(data.ray[colom].horiz_hitp->x, (float)CELL_SIZE);
	else if (data.ray[colom].closest_hit == VERTICAL)
		pos_in_wall = fmodf(data.ray[colom].verti_hitp->y, (float)CELL_SIZE);
	texture_x = pos_in_wall * data.texture->we->width / (float)CELL_SIZE;
	return (texture_x);
}

int	get_texture_y(mlx_texture_t *texture, t_cube *cube, int y, int wallHeight)
{
	float	step;
	float	offset_y;
	int		wall_top_px;

	wall_top_px = (cube->window->height / 2) - (wallHeight / 2);
	step = (float)texture->height / wallHeight;
	offset_y = ((y - wall_top_px) * step);
	if (offset_y >= texture->height)
		offset_y = texture->height - 1;
	if (offset_y < 0)
		offset_y = 0;
	return (offset_y);
}
