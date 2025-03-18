/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:35:27 by moait-la          #+#    #+#             */
/*   Updated: 2025/03/13 16:18:04 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	init_ray_data(t_cube *cube, float rayAngle, int colom)
{
	cube->ray[colom].horiz_hitp = (t_point *)ft_malloc(sizeof(t_point));
	cube->ray[colom].verti_hitp = (t_point *)ft_malloc(sizeof(t_point));
	cube->ray[colom].ray_angle = rayAngle;
	cube->ray[colom].closest_hit = UNKNOWN;
}

void	cast_all_rays(t_cube *cube)
{
	float	first_ray_ang;
	float	angle_inc;
	int		colom;

	first_ray_ang = (cube->player->degree - (cube->player->fov / 2));
	first_ray_ang = first_ray_ang * (M_PI / (float)180);
	angle_inc = (cube->player->fov * (M_PI / 180)) / (float)WIDTH;
	colom = -1;
	while (++colom < WIDTH)
	{
		first_ray_ang = normalize(first_ray_ang);
		init_ray_data(cube, first_ray_ang, colom);
		set_ray_direction(cube, colom);
		get_horiz_inter(cube, colom);
		get_verti_inter(cube, colom);
		get_closest_hit(cube, colom);
		first_ray_ang += angle_inc;
	}
}
