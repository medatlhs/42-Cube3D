/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:16:01 by moait-la          #+#    #+#             */
/*   Updated: 2025/03/20 16:06:18 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	render_ceilling(t_cube cube, int x, int wall_top_px)
{
	int	k;

	k = -1;
	while (++k < wall_top_px)
	{
		my_pixel_put(&cube, x, k,
			get_color(cube.map->c[0], cube.map->c[1], cube.map->c[2], 255));
	}
}

void	render_floor(t_cube cube, int x, int wall_bot_px)
{
	while (++wall_bot_px < HEIGHT)
	{
		my_pixel_put(&cube, x, wall_bot_px,
			get_color(cube.map->f[0], cube.map->f[1], cube.map->f[2], 255));
	}
}

void	render_stripe(t_cube cube, int colom, int top_px, int bot_px)
{
	int				wall_height;
	int				texture_x;
	int				texture_y;
	uint32_t		*texture_px;
	mlx_texture_t	*mytexture;

	mytexture = get_texture(cube, cube.ray[colom]);
	wall_height = HEIGHT * 100 / cube.ray[colom].distance;
	texture_x = get_texture_x(mytexture, cube, colom);
	texture_px = (uint32_t *)mytexture->pixels;
	while (top_px <= bot_px)
	{
		texture_y = get_texture_y(mytexture, &cube, top_px, wall_height);
		my_pixel_put(&cube, colom, top_px,
			abgr_to_rgba(
				texture_px[texture_y * mytexture->width + texture_x]));
		top_px++;
	}
}

void	render3d_scene(t_cube cube)
{
	int	wall_height;
	int	wall_top_px;
	int	wall_bot_px;
	int	colom;

	colom = -1;
	while (++colom < NUM_RAYS)
	{
		wall_height = HEIGHT * 100 / cube.ray[colom].distance;
		wall_top_px = (HEIGHT / 2) - (wall_height / 2);
		wall_bot_px = (HEIGHT / 2) + (wall_height / 2);
		if (wall_top_px < 0)
			wall_top_px = 0;
		if (wall_bot_px >= HEIGHT)
			wall_bot_px = HEIGHT - 1;
		render_stripe(cube, colom, wall_top_px, wall_bot_px);
		render_ceilling(cube, colom, wall_top_px);
		render_floor(cube, colom, wall_bot_px);
	}
}
