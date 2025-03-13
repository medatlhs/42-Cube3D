/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsIV.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:09:18 by moait-la          #+#    #+#             */
/*   Updated: 2025/03/13 10:29:45 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	ft_error(char *errorMsj)
{
	ft_putstr_fd(errorMsj, 2);
	exit(1);
}

void	setPosition(t_cube *cube, int row, int colom, char c)
{
	cube->player->x = colom * CELL_SIZE;
	cube->player->y = row * CELL_SIZE;
	if (c == 'N')
		cube->player->degree = 270;
	else if (c == 'W')
		cube->player->degree = 180;
	else if (c == 'S')
		cube->player->degree = 90;
	else if (c == 'E')
		cube->player->degree = 0;
}

void	setPLayerPosition(t_cube *cube)
{
	int	i;
	int	k;

	i = -1;
	while (++i < cube->map->row)
	{
		k = -1;
		while (++k < cube->map->colum)
		{
			if (cube->map->map[i][k] == 'N' || cube->map->map[i][k] == 'S'
				|| cube->map->map[i][k] == 'E' || cube->map->map[i][k] == 'W')
			{
				setPosition(cube, i, k, cube->map->map[i][k]);
			}
		}
	}
}

void	setupHooks(t_cube *cube)
{
	mlx_key_hook(cube->window, key_press, cube);
	mlx_close_hook(cube->window, ft_close, cube);
	mlx_loop_hook(cube->window, render_frame, cube);
	mlx_image_to_window(cube->window, cube->img, 0, 0);
	mlx_loop(cube->window);
}

void	init_mlx(t_cube *cube)
{
	cube->window = mlx_init(WIDTH, HEIGHT, "CUBE3D", false);
	if (!cube->window)
		ft_error("Error Creating Window\n");
	cube->img = mlx_new_image(cube->window, WIDTH, HEIGHT);
	if (!cube->img)
		ft_error("Error Allocating Img Buffer\n");
}
