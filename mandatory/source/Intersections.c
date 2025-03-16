/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:37:44 by moait-la          #+#    #+#             */
/*   Updated: 2025/03/13 16:37:00 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	check_horiz_inter(t_cube *cube, float xstep, float ystep, int colom)
{
	float	x_nearest;
	float	y_nearest;

	x_nearest = cube->ray[colom].x_nearest;
	y_nearest = cube->ray[colom].y_nearest;
	while (x_nearest > 0 && y_nearest > 0
		&& x_nearest < WIDTH && y_nearest < HEIGHT)
	{
		// getPixel => -1 for up 1 for down
		if (!wall_check(cube, x_nearest, y_nearest
				+ get_pixel(cube, colom, true)))
			break ;
		x_nearest += xstep;
		y_nearest += ystep;
	}
	cube->ray[colom].horiz_hitp->x = x_nearest;
	cube->ray[colom].horiz_hitp->y = y_nearest;
}

void	get_horiz_inter(t_cube *cube, int colom)
{
	float	xstep;
	float	ystep;

	cube->ray[colom].y_nearest = floor(cube->player->y / CELL_SIZE) * CELL_SIZE;
	if (cube->ray[colom].facingDown == true)
		cube->ray[colom].y_nearest += CELL_SIZE;
	cube->ray[colom].x_nearest = cube->player->x
		+ (cube->ray[colom].y_nearest - cube->player->y)
		/ (float)(tan(cube->ray[colom].ray_angle));
	ystep = CELL_SIZE;
	if (cube->ray[colom].facingUp == true)
		ystep *= -1;
	xstep = ystep / (float)(tan(cube->ray[colom].ray_angle));
	if (cube->ray[colom].facingLeft && xstep > 0)
		xstep *= -1;
	if (cube->ray[colom].facingRight && xstep < 0)
		xstep *= -1;
	check_horiz_inter(cube, xstep, ystep, colom);
}

void	check_verti_inter(t_cube *cube, float xstep, float ystep, int colom)
{
	float	y_nearest;
	float	x_nearest;

	x_nearest = cube->ray[colom].x_nearest;
	y_nearest = cube->ray[colom].y_nearest;
	while (x_nearest > 0 && y_nearest > 0
		&& x_nearest < WIDTH && y_nearest < HEIGHT)
	{
		if (!wall_check(cube, x_nearest
				+ get_pixel(cube, colom, false), y_nearest))
			break ;
		x_nearest += xstep;
		y_nearest += ystep;
	}
	cube->ray[colom].verti_hitp->x = x_nearest;
	cube->ray[colom].verti_hitp->y = y_nearest;
}

void	get_verti_inter(t_cube *cube, int colom)
{
	float	xstep;
	float	ystep;

	cube->ray[colom].x_nearest = floor(cube->player->x / CELL_SIZE) * CELL_SIZE;
	if (cube->ray[colom].facingRight)
		cube->ray[colom].x_nearest += CELL_SIZE;
	cube->ray[colom].y_nearest = cube->player->y
		+ (cube->ray[colom].x_nearest - cube->player->x)
		* (tan(cube->ray[colom].ray_angle));
	xstep = CELL_SIZE;
	if (cube->ray[colom].facingLeft == true)
		xstep *= -1;
	ystep = xstep * (tan(cube->ray[colom].ray_angle));
	if (cube->ray[colom].facingUp && ystep > 0)
		ystep *= -1;
	if (cube->ray[colom].facingDown && ystep < 0)
		ystep *= -1;
	check_verti_inter(cube, xstep, ystep, colom);
}
