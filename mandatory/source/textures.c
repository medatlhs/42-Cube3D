#include "../include/cube.h"

void    loatTextures(t_cube *cube)
{
    cube->texture->we = mlx_load_png("/Users/moait-la/Desktop/CUBE3D/assets/textures/texture.png");
	return ;
	int i = -1;
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

mlx_texture_t *getTexture(t_texture texture, t_ray ray)
{
	if (ray.closestHit == HORIZONTAL)
	{
		if (ray.rayAngle < M_PI && ray.rayAngle > 0)
			return (texture.no);
		else
			return (texture.so);
	}
	else if (ray.closestHit == VERTICAL)
	{
		if (ray.rayAngle > M_PI/2 && ray.rayAngle < 3 * (M_PI/2) )
			return (texture.we);
		else
			return (texture.ea);
	}
	return (NULL);
}

float	getTextureX(t_cube data, int colom)
{
	float textureX;
	if (data.ray[colom].closestHit == HORIZONTAL)
	{
		float positionInWall = fmodf(data.ray[colom].horizHitP->x ,(float)CELL_SIZE);
		textureX = positionInWall * data.texture->we->width / (float)CELL_SIZE;
	}
	else if (data.ray[colom].closestHit == VERTICAL)
	{
		float positionInWall = fmodf(data.ray[colom].vertiHitP->y ,(float)CELL_SIZE);
		textureX = positionInWall * data.texture->we->width / (float)CELL_SIZE;
	}
	return textureX;
}

int	getTextureY(mlx_texture_t *texture, t_cube *cube, int y, int wallHeight)
{
	double	step;
	double	offset_y;
	int		wall_t;

	wall_t = (cube->window->height / 2) - (wallHeight / 2);
	step = (double)texture->height / wallHeight;
	offset_y = ((y - wall_t) * step);
	if (offset_y >= texture->height)
		offset_y = texture->height - 1;
	if (offset_y < 0)
		offset_y = 0;
	return (offset_y);
}

