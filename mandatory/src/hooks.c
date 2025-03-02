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

void	keyPress(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
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


