/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsII.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:11:10 by moait-la          #+#    #+#             */
/*   Updated: 2025/03/20 14:47:37 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

uint32_t	abgr_to_rgba(uint32_t c)
{
	uint32_t	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
}

int	get_color(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a << 0);
}

void	my_pixel_put(t_cube *cube, int x, int y, uint32_t color)
{
	if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
		return ;
	mlx_put_pixel(cube->img, x, y, color);
}

void	get_closest_hit(t_cube *cube, int colom)
{
	float	hroiz_dis;
	float	verti_dis;
	float	angle_rad;

	hroiz_dis = sqrt(pow(cube->ray[colom].horiz_hitp->x - cube->player->x, 2)
			+ pow(cube->ray[colom].horiz_hitp->y - cube->player->y, 2));
	verti_dis = sqrt(pow(cube->ray[colom].verti_hitp->x - cube->player->x, 2)
			+ pow(cube->ray[colom].verti_hitp->y - cube->player->y, 2));
	angle_rad = cube->player->degree * (M_PI / 180);
	if (hroiz_dis < verti_dis)
	{
		cube->ray[colom].closest_hit = HORIZONTAL;
		cube->ray[colom].distance = hroiz_dis
			* cos(cube->ray[colom].ray_angle - angle_rad);
		return ;
	}
	cube->ray[colom].closest_hit = VERTICAL;
	cube->ray[colom].distance = verti_dis
		* cos(cube->ray[colom].ray_angle - angle_rad);
}
