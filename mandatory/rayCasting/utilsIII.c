/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsIII.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:27:05 by moait-la          #+#    #+#             */
/*   Updated: 2025/03/18 20:42:48 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

float	normalize(float angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle = angle + (2 * M_PI);
	return (angle);
}

int	get_pixel(t_cube *cube, int colom, bool flag)
{
	if (flag)
	{
		if (cube->ray[colom].ray_angle > M_PI
			&& cube->ray[colom].ray_angle < 2 * M_PI)
			return (-1);
	}
	else
		if (cube->ray[colom].ray_angle > M_PI / 2
			&& cube->ray[colom].ray_angle < 3 * (M_PI / 2))
			return (-1);
	return (0);
}

void	clear_image(t_cube *cube)
{
	ft_memset(cube->img->pixels, 0, cube->img->width * cube->img->height * 4);
}

void	free_all(t_cube *cube)
{
	int	i;

	i = -1;
	while (++i < WIDTH)
		ft_free(cube->ray[i].horiz_hitp, cube->ray[i].verti_hitp);
}
