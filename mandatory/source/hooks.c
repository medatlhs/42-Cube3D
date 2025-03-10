#include "../include/cube.h"

void	checkRelease(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		((t_cube *)(param))->player->moveFront = false;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		((t_cube *)(param))->player->moveBack = false;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		((t_cube *)(param))->player->rotateRight = false;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		((t_cube *)(param))->player->rotateLeft = false;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		((t_cube *)(param))->player->moveRight = false;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		((t_cube *)(param))->player->moveLeft = false;
}

void	escape(t_cube *cube)
{
	ft_free(cube->map, cube->player, cube->ray);
	ft_free(cube->texture, NULL, NULL);
	ft_putstr_fd("closed!\n", 1);
	exit(0);
}
void	ft_close(void* param)
{
	t_cube *cube;

	cube = (t_cube *)param;
	printf("here\n");
	ft_free(cube->map, cube->player, cube->ray);
	ft_free(cube->texture->we, cube->texture, NULL);
	ft_putstr_fd("closed!\n", 1);
	exit(0);
}

void	keyPress(mlx_key_data_t keydata, void *param)
{
	printf("%d\n", keydata.key);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		escape((t_cube *)param);
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		((t_cube *)(param))->player->moveFront = true;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		((t_cube *)(param))->player->moveBack = true;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		((t_cube *)(param))->player->rotateRight = true;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		((t_cube *)(param))->player->rotateLeft = true;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		((t_cube *)(param))->player->moveRight = true;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		((t_cube *)(param))->player->moveLeft = true;
	else
		checkRelease(keydata, param);
}


