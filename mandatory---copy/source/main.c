/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moait-la <moait-la@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:13:07 by moait-la          #+#    #+#             */
/*   Updated: 2025/03/13 13:07:34 by moait-la         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	loadSpirites(t_cube *cube)
{
	char	*paths[SPRITES];

	paths[0]= "/Users/moait-la/Desktop/cuby/assets/sprites/01.png";
	paths[1] = "/Users/moait-la/Desktop/cuby/assets/sprites/02.png";
	paths[2] = "/Users/moait-la/Desktop/cuby/assets/sprites/03.png";
	paths[3] = "/Users/moait-la/Desktop/cuby/assets/sprites/04.png";
	paths[4] = "/Users/moait-la/Desktop/cuby/assets/sprites/05.png";
	paths[5] = "/Users/moait-la/Desktop/cuby/assets/sprites/06.png";
	paths[6] = "/Users/moait-la/Desktop/cuby/assets/sprites/07.png";
	int k = -1;
	while (++k < SPRITES)
		cube->sprite->spirites[k] = mlx_load_png(paths[k]);
	k = -1;
	while (++k < SPRITES)
		cube->sprite->images[k] = mlx_texture_to_image(cube->window, cube->sprite->spirites[k]);
}

void	loadCrosshair(t_cube *cube)
{
	cube->sprite->crosshair = mlx_load_png("/Users/moait-la/Desktop/cuby/assets/sprites/crosshair.png");
	cube->sprite->crosshair_img = mlx_texture_to_image(cube->window, cube->sprite->crosshair);
	mlx_image_to_window(cube->window, cube->sprite->crosshair_img, WIDTH/2, HEIGHT/2);
	cube->sprite->cross_loaded = true;
}

void	sprite_to_window(t_cube *cube)
{
	int	k;

	if (cube->sprite->loaded == false)
	{
		k = -1;
		while (++k < SPRITES)
		{
			mlx_image_to_window(cube->window, cube->sprite->images[k], (WIDTH
				- (cube->sprite->spirites[k]->width + 200)),
					(HEIGHT - cube->sprite->spirites[k]->height));
		}
		cube->sprite->loaded = true;
	}
}

void	shoot(t_cube *cube, int *passed_frames, int *current_sprite, int *passed_sprites)
{
	(*passed_frames)++;
	if ((*passed_frames) > 1)
	{
		(*passed_frames) = 0;
		cube->sprite->images[*current_sprite]->enabled = false;
		(*current_sprite) = (*current_sprite + 1) % SPRITES;
		cube->sprite->images[*current_sprite]->enabled = true;
		(*passed_sprites)++;
	}
	if ((*passed_sprites) == SPRITES)
	{
		cube->sprite->fired = false;
		(*passed_sprites) = 0;
	}
}

void	renderSprite(t_cube *cube)
{
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
		shoot(cube, &passed_frames, &current_sprite, &passed_sprites);
}

void	render_frame(void	*param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	clear_image(cube);
	update_position(cube);
	cast_all_rays(cube);
	render3d_scene(*cube);
	
	// bonus::
	sprite_to_window(cube);
	renderSprite(cube);
	if (cube->sprite->cross_loaded == false)
		loadCrosshair(cube);
	
	free_all(cube);
}
void	*handle_mouse(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	if (button == 0)
		cube->sprite->fired = true;
	return (NULL);
}

void	*handle_cursor(double xpos, double ypos, void* param)
{
	t_cube	*cube;
	int		deltax;

	cube = (t_cube *)param;
	cube->player->new_mouse_x = xpos;
	cube->player->mouse_moved = true;
	// deltax = xpos - cube->player->last_mouse_x;
	// cube->player->degree += deltax * 0.003; 
	// cube->player->new_mouse_x = xpos;
	return (NULL);
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

	//bonus::
	mlx_set_cursor_mode(cube.window, MLX_MOUSE_HIDDEN);
	cube.player->mouse_moved = false;
	cube.sprite->fired = false;
	cube.sprite->loaded = false;
	cube.sprite->cross_loaded = false;
	loadSpirites(&cube);
	mlx_mouse_hook(cube.window, (void *)handle_mouse, &cube);
	cube.player->last_mouse_x = WIDTH/2;
	mlx_cursor_hook(cube.window, (void *)handle_cursor, &cube);
	

	initStartingValues(&cube);
	setupHooks(&cube);
	return (0);
}
