/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:07:12 by moait-la          #+#    #+#             */
/*   Updated: 2025/03/20 17:34:33 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	init_startings(t_cube *cube)
{
	cube->player->fov = 60;
	cube->player->speed = 10;
	cube->player->rotate_left = 0;
	cube->player->rotate_right = 0;
	cube->player->move_right = 0;
	cube->player->move_left = 0;
	cube->player->move_back = 0;
	cube->player->move_front = 0;
}

void	*ft_malloc(unsigned long size)
{
	void	*ptr;

	ptr = (void *)malloc(size);
	if (!ptr)
		ft_error("Error Malloc failed\n");
	return (ptr);
}

void	allocations(t_cube *cube)
{
	cube->player = (t_player *)ft_malloc(sizeof(t_player));
	cube->ray = (t_ray *)ft_malloc(sizeof(t_ray) * WIDTH);
	cube->texture = (t_texture *)ft_malloc(sizeof(t_texture));
}

void	set_ray_direction(t_cube *cube, int colom)
{
	cube->ray[colom].facing_down = cube->ray[colom].ray_angle > 0
		&& cube->ray[colom].ray_angle < M_PI;
	cube->ray[colom].facing_up = !cube->ray[colom].facing_down;
	cube->ray[colom].facing_right = cube->ray[colom].ray_angle < (M_PI / 2)
		|| cube->ray[colom].ray_angle > (3 * M_PI) / 2;
	cube->ray[colom].facing_left = !cube->ray[colom].facing_right;
}

void	ft_free(void *ptr, void *ptr2)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	if (ptr2)
	{
		free(ptr2);
		ptr2 = NULL;
	}
}
