#include "../include/cube.h"

void	clearImage(t_cube *cube)
{
	ft_memset(cube->img->pixels, 0, cube->img->width * cube->img->height * 4);
}

void	freeAll(t_cube *cube)
{
	int i = -1;
	while(++i < WIDTH)
		ft_free(cube->ray[i].horizHitP, cube->ray[i].vertiHitP, NULL);
}

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
}

void	render(void	*param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	clearImage(cube);
	updatePosition(cube);
	castAllRays(cube);
	render3Dscene(*cube);
	if (!cube->sprite->fire)
	{
		if (cube->sprite->images[0] == NULL)
		{
			cube->sprite->images[0] = mlx_texture_to_image(cube->window, cube->sprite->spirites[0]);
			if (!cube->sprite->images[0])
				return ;
			mlx_image_to_window(cube->window, cube->sprite->images[0], (WIDTH - (cube->sprite->spirites[0]->width + 200)),
				(HEIGHT - cube->sprite->spirites[0]->height));
		}
		else
		{
			int j = 0;
			if (cube->sprite->images[1] != NULL)
				while (++j < SPRITES)
					cube->sprite->images[j]->enabled = false;
			cube->sprite->images[0]->enabled = true;
		}
	}
	else // if he click on button we render our guns motion :>
	{
		if (cube->sprite->images[1] == NULL)
		{
			int k = 0;
			while (++k < SPRITES)
			{
				cube->sprite->images[k] = mlx_texture_to_image(cube->window, cube->sprite->spirites[k]);
				if (!cube->sprite->images[k])
					return (ft_error("chii haja tma\n"));
				mlx_image_to_window(cube->window, cube->sprite->images[k], (WIDTH - (cube->sprite->spirites[k]->width + 200)),
					(HEIGHT - cube->sprite->spirites[k]->height));
			}
			cube->sprite->images[0]->enabled = false;
		}
		else
		{
			cube->sprite->images[0]->enabled = false;
			int j = 0;
			while (++j < SPRITES)
			{
				cube->sprite->images[j]->enabled = true;
			}
		}
		cube->sprite->fire = false;
	}
	freeAll(cube);
}

void	*mouse(mouse_key_t button, action_t action, modifier_key_t mods, void *param)

{
	if (button == 0)
		((t_cube *)param)->sprite->fire = true;
	return NULL;
}

int main()
{
	t_cube cube;
	// atexit(f);

	cube.window = mlx_init(WIDTH, HEIGHT, "CUBE3D", false);
	if (!cube.window)
		ft_error("Error Creating Window\n");

	cube.img = mlx_new_image(cube.window, WIDTH, HEIGHT);
	if (!cube.img)
		ft_error("Error Allocating Img Buffer\n");

	// renderMiniMap(&cube);
	// return 0;
	allocations(&cube);

	cube.sprite->fire = false;
	cube.renderdBefore = false;
	int k = -1;
	while (++k < SPRITES)
	{
		cube.sprite->images[k] = NULL;
	}
	
	loadSpirites(&cube);

	loatTextures(&cube);
	getMap(&cube);
	initStartingValues(&cube);

	mlx_key_hook(cube.window, keyPress, &cube);
	mlx_close_hook(cube.window, ft_close, &cube);
	mlx_loop_hook(cube.window, render, &cube);
	// mlx_cursor_hook(cube.window, mouse, &cube);
	mlx_mouse_hook(cube.window, mouse, &cube);
	mlx_image_to_window(cube.window, cube.img, 0, 0);

	mlx_loop(cube.window);

    return 0;
}



// void renderMiniMap(t_cube *cube)
// {
//     int x, y;
//     int mapX, mapY;

//     // Ensure cube->img is initialized correctly before using it
//     if (!cube->img) {
//         return; // Avoid accessing an uninitialized image
//     }

//     // Iterate over all the rows and columns of the minimap
//     for (y = 0; y < HEIGHT; y++)
//     {
//         for (x = 0; x < WIDTH; x++)
//         {
//             // Normalize (x, y) position in minimap to map coordinates
//             mapX = (int)((float)x / WIDTH * COLOMS);  // Scale x to map width
//             mapY = (int)((float)y / HEIGHT * ROWS); // Scale y to map height

//             // Check if there is a wall at this position in the map
//             if (wallCheck(cube, mapX, mapY)) 
//             {
//                 // If it's a wall, put a pixel on the minimap (white for walls)
//                 mlx_put_pixel(cube->img, x, y, 0xFFFFFF);  // White for walls
//             }
//             else
//             {
//                 // If it's empty space, put a pixel (black for empty space)
//                 mlx_put_pixel(cube->img, x, y, 0x000000);  // Black for empty space
//             }
//         }
//     }
// }
