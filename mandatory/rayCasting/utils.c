/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:07:12 by moait-la          #+#    #+#             */
/*   Updated: 2025/03/18 16:35:23 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	init_startings(t_cube *cube)
{
	cube->player->fov = 60;
	cube->player->speed = 30;
	cube->player->rotateLeft = 0;
	cube->player->moveRight = 0;
	cube->player->moveBack = 0;
	cube->player->rotateRight = 0;
	cube->player->moveFront = 0;
	cube->player->moveLeft = 0;
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
	cube->ray[colom].facingDown = cube->ray[colom].ray_angle > 0
		&& cube->ray[colom].ray_angle < M_PI;
	cube->ray[colom].facingUp = !cube->ray[colom].facingDown;
	cube->ray[colom].facingRight = cube->ray[colom].ray_angle < (M_PI / 2)
		|| cube->ray[colom].ray_angle > (3 * M_PI) / 2;
	cube->ray[colom].facingLeft = !cube->ray[colom].facingRight;
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
