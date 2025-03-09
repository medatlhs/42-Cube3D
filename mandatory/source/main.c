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

void	render(void	*param)
{
	t_cube	*cube;

	cube = (t_cube *)param;
	clearImage(cube);
	updatePosition(cube);
	castAllRays(cube);
	render3Dscene(*cube);
	freeAll(cube);
}
void f()
{
	system("leaks cube");
}

int main()
{
	t_cube cube;
	atexit(f);

	cube.window = mlx_init(WIDTH, HEIGHT, "CUBE3D", false);
	if (!cube.window)
		ft_error("Error Creating Window\n");

	cube.img = mlx_new_image(cube.window, WIDTH, HEIGHT);
	if (!cube.img)
		ft_error("Error Allocating Img Buffer\n");

	allocations(&cube);
	loatTextures(&cube);
	getMap(&cube);
	initStartingValues(&cube);

	mlx_key_hook(cube.window, keyPress, &cube);
	mlx_close_hook(cube.window, ft_close, &cube);
	mlx_loop_hook(cube.window, render, &cube);
	mlx_image_to_window(cube.window, cube.img, 0, 0);

	mlx_loop(cube.window);

    return 0;
}
