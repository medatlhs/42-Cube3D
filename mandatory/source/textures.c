/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:28:53 by moait-la          #+#    #+#             */
/*   Updated: 2025/03/13 20:58:53 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void    load_textures(t_cube *cube)
{
    cube->texture->we = mlx_load_png("/Users/moait-la/Desktop/cuby/assets/textures/texture.png");
	if (!cube->texture->we)
		ft_error("walawalawalawalawala\n");
	return ;
	printf("%s\n", cube->texture->textures[0]->path);
	int	i;
	i = -1;
	while (cube->texture->textures[++i])
	{
		if (!ft_strncmp(cube->texture->textures[i]->key, "NO", 2))
			cube->texture->no = mlx_load_png(cube->texture->textures[i]->path);
		else if (!ft_strncmp(cube->texture->textures[i]->key, "EA", 2))
			cube->texture->ea = mlx_load_png(cube->texture->textures[i]->path);
		else if (!ft_strncmp(cube->texture->textures[i]->key, "WE", 2))
			cube->texture->we = mlx_load_png(cube->texture->textures[i]->path);
		else if (!ft_strncmp(cube->texture->textures[i]->key, "SO", 2))
			cube->texture->so = mlx_load_png(cube->texture->textures[i]->path);
	}
    if (!cube->texture->no || !cube->texture->ea || !cube->texture->we || !cube->texture->so)
		ft_error("Error: failed to load textures");
}

mlx_texture_t *get_texture(t_texture texture, t_ray ray)
{
	if (ray.closest_hit == HORIZONTAL)
	{
		if (ray.ray_angle < M_PI && ray.ray_angle > 0)
			return (texture.no);
		else
			return (texture.so);
	}
	else if (ray.closest_hit == VERTICAL)
	{
		if (ray.ray_angle > M_PI/2 && ray.ray_angle < 3 * (M_PI/2) )
			return (texture.we);
		else
			return (texture.ea);
	}
	return (NULL);
}

float	get_texture_x(t_cube data, int colom)
{
	float	textureX;
	float	positionInWall;

	if (data.ray[colom].closest_hit == HORIZONTAL)
	{
		positionInWall = fmodf(data.ray[colom].horiz_hitp->x ,(float)CELL_SIZE);
		textureX = positionInWall * data.texture->we->width / (float)CELL_SIZE;
	}
	else if (data.ray[colom].closest_hit == VERTICAL)
	{
		positionInWall = fmodf(data.ray[colom].verti_hitp->y ,(float)CELL_SIZE);
		textureX = positionInWall * data.texture->we->width / (float)CELL_SIZE;
	}
	return (textureX);
}

int	get_texture_y(mlx_texture_t *texture, t_cube *cube, int y, int wallHeight)
{
	float	step;
	float	offset_y;
	int		wallTopPixel;

	wallTopPixel = (cube->window->height / 2) - (wallHeight / 2);
	step = (float)texture->height / wallHeight;
	offset_y = ((y - wallTopPixel) * step);
	if (offset_y >= texture->height)
		offset_y = texture->height - 1;
	if (offset_y < 0)
		offset_y = 0;
	return (offset_y);
}
