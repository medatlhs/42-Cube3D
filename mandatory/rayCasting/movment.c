/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:31:40 by moait-la          #+#    #+#             */
/*   Updated: 2025/03/20 16:36:18 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	update_position(t_cube *cube)
{
	if (cube->player->rotate_right == true)
		cube->player->degree += 6;
	else if (cube->player->rotate_left == true)
		cube->player->degree -= 6;
	if (cube->player->move_front == true)
		move_forward(cube);
	else if (cube->player->move_back == true)
		move_back(cube);
	else if (cube->player->move_right == true)
		move_sides(cube, 1);
	else if (cube->player->move_left == true)
		move_sides(cube, -1);
}

int	wall_check(t_cube *cube, int newX, int newY)
{
	int	grid_x;
	int	grid_y;
	int	i;

	i = -1;
	grid_x = (newX / CELL_SIZE);
	grid_y = (newY / CELL_SIZE);
	if (grid_x < 0 || grid_x >= cube->map->colum
		|| grid_y < 0 || grid_y >= cube->map->row)
		return (0);
	if (cube->map->map[grid_y][grid_x] == '1')
		return (0);
	return (1);
}

void	move_sides(t_cube *cube, int direction)
{
	float	direc_rad;
	float	new_angle;
	float	new_x;
	float	new_y;

	direc_rad = cube->player->degree * (M_PI / 180);
	new_angle = direc_rad + (direction * (M_PI / 2));
	new_x = cube->player->x + (cos(new_angle) * cube->player->speed);
	new_y = cube->player->y + (sin(new_angle) * cube->player->speed);
	if (!wall_check(cube, new_x, new_y))
		return ;
	cube->player->x = new_x;
	cube->player->y = new_y;
}

void	move_forward(t_cube *cube)
{
	float	degre_rad;
	float	new_x;
	float	new_y;

	degre_rad = cube->player->degree * (M_PI / 180);
	new_x = cube->player->x + (cos(degre_rad) * cube->player->speed);
	new_y = cube->player->y + (sin(degre_rad) * cube->player->speed);
	if (wall_check(cube, new_x, cube->player->y))
		cube->player->x = new_x;
	if (wall_check(cube, cube->player->x, new_y))
		cube->player->y = new_y;
}

void	move_back(t_cube *cube)
{
	float	degree_rad;
	float	new_x;
	float	new_y;

	degree_rad = cube->player->degree * (M_PI / 180);
	new_x = cube->player->x - (cos(degree_rad) * cube->player->speed);
	new_y = cube->player->y - (sin(degree_rad) * cube->player->speed);
	if (wall_check(cube, new_x, cube->player->y))
		cube->player->x = new_x;
	if (wall_check(cube, cube->player->x, new_y))
		cube->player->y = new_y;
}
