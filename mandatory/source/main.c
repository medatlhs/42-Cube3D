/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:13:07 by moait-la          #+#    #+#             */
/*   Updated: 2025/03/13 09:20:40 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	loadSpirites(t_cube *cube)
{
	char	*paths[SPRITES];

	paths[0]= "/Users/moait-la/Desktop/CUBE3D/assets/sprites/01.png";
	paths[1] = "/Users/moait-la/Desktop/CUBE3D/assets/sprites/02.png";
	paths[2] = "/Users/moait-la/Desktop/CUBE3D/assets/sprites/03.png";
	paths[3] = "/Users/moait-la/Desktop/CUBE3D/assets/sprites/04.png";
	paths[4] = "/Users/moait-la/Desktop/CUBE3D/assets/sprites/05.png";
	int k = -1;
	while (++k < SPRITES)
		cube->sprite->spirites[k] = mlx_load_png(paths[k]);
	k = -1;
	while (++k < SPRITES)
		cube->sprite->images[k] = mlx_texture_to_image(cube->window, cube->sprite->spirites[k]);
	// k = -1;
	// while (++k < SPRITES)
	// {
	// 	mlx_image_to_window(cube->window, cube->sprite->images[k], (WIDTH - (cube->sprite->spirites[k]->width + 200)),
	// 			(HEIGHT - cube->sprite->spirites[k]->height));
	// }
	// mtnsach:: need protection check here !!!!!&^&*^*&^
}

void	render_frame(void	*param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	clear_image(cube);
	update_position(cube);
	cast_all_rays(cube);
	render3d_scene(*cube);
	
	if (cube->sprite->fired == false)
	{
		int k = -1;
		while (++k < SPRITES)
		{
			mlx_image_to_window(cube->window, cube->sprite->images[k], (WIDTH - (cube->sprite->spirites[k]->width + 200)),
					(HEIGHT - cube->sprite->spirites[k]->height));
		}
	}

	static int passed_frames = 0;
	static int current_sprite = 0;
	static int passed_sprites = 0;

	if (cube->sprite->fired == false)
	{
		int i = 0;
		while (++i < SPRITES)
			cube->sprite->images[i]->enabled = false;
		cube->sprite->images[0]->enabled = true;
	}
	else
	{
		passed_frames++;
		if (passed_frames > 2)
		{
			passed_frames = 0;
			cube->sprite->images[current_sprite]->enabled = false;
			current_sprite = (current_sprite + 1) % SPRITES;
			cube->sprite->images[current_sprite]->enabled = true;
			passed_sprites++;
		}
		if (passed_sprites == SPRITES)
		{
			cube->sprite->fired = false;
			passed_sprites = 0;
		}
	}
	// free_all(cube);
}

int	main(void)
{
	t_cube	cube;
	char	*path;

	path = "/Users/moait-la/Desktop/42-Cube3D-chahlaoui/mandatory/parssing/test.cub";
	if (!parsing_final(path, &cube))
		return (1);
	init_mlx(&cube);
	allocations(&cube);
	setPLayerPosition(&cube);
	loatTextures(&cube);

	cube.sprite->fired = false;
	loadSpirites(&cube);

	initStartingValues(&cube);
	setupHooks(&cube);
	return (0);
}
