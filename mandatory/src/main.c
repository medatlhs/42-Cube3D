#include "../include/cube.h"

void	clearImage(t_cube *cube)
{
	ft_memset(cube->img->pixels, 0, cube->img->width * cube->img->height * 4);
}

void	render(void	*param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	clearImage(cube);
	updatePosition(cube);
	// renderMapGrid(cube);
	// renderPlayer(cube);
	// castRay(cube); // removed
	castAllRays(cube);
	render_3dscene(*cube);
}

// void mouse(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
// {
//     t_cube *cube = (t_cube *)param;
// 	int x, y;
// 	mlx_get_mouse_pos(cube->window, &x, &y);
// 	printf("mouse position: (%d,%d)\n", x, y);
// }

int main()
{
	t_cube cube;

	cube.window = mlx_init(WIDTH, HEIGHT, "CUBE3D", false);
	if (!cube.window)
		ft_error("Error Creating Window\n");

	cube.img = mlx_new_image(cube.window, WIDTH, HEIGHT);
	if (!cube.img)
		ft_error("Error Allocating Img Buffer\n");

	allocations(&cube);
	getMap(&cube);
	initStartingValues(&cube);
	getSquareFactor(&cube);

	mlx_key_hook(cube.window, keyPress, &cube);
	// mlx_mouse_hook(cube.window, mouse, &cube);
	mlx_loop_hook(cube.window, render, &cube);
	mlx_image_to_window(cube.window, cube.img, 0, 0);

	mlx_loop(cube.window);

    return 0;
}
