/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:16:01 by moait-la          #+#    #+#             */
/*   Updated: 2025/03/13 16:18:37 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	render_ceilling(t_cube cube, int x, int wallTopPixel)
{
	int	k;

	k = -1;
	while (++k < wallTopPixel)
		my_pixel_put(&cube, x, k, get_color(50, 50, 50, 255));
}

void	render_floor(t_cube cube, int x, int wallBottomPixel)
{
	while (++wallBottomPixel < HEIGHT)
	{
		if (x % 2 == 0)
			my_pixel_put(&cube, x, wallBottomPixel, get_color(150, 150, 150, 255));
		else
			my_pixel_put(&cube, x, wallBottomPixel, get_color(0, 0, 0, 255));
	}
}

void	render_stripe(t_cube cube, int colom, int top_px, int bot_px)
{
	int			wall_height;
	int			pixel_pos;
	int			texture_x;
	float		texture_y;
	uint32_t	*texture_px;

	wall_height = HEIGHT * 100 / cube.ray[colom].distance;
	texture_x = get_texture_x(cube, colom);
	texture_px = (uint32_t *)cube.texture->we->pixels;
	while (top_px <= bot_px)
	{
		texture_y = get_texture_y(cube.texture->we, &cube, top_px, wall_height);
		pixel_pos = (texture_y * cube.texture->we->width) + texture_x;
		my_pixel_put(&cube, colom, top_px, reverse_bytes(texture_px[pixel_pos]));
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
