#include "../include/cube.h"

void	initStartingValues(t_cube *cube)
{
	cube->player->x = WIDTH/2;
	cube->player->y = HEIGHT/2;
	cube->player->degree = 90;
	cube->player->fov = 60;
	cube->player->moveFront = 0;
	cube->player->moveBack = 0;
	cube->player->moveRight = 0;
	cube->player->rotateRight = 0;
	cube->player->moveLeft = 0;
	cube->player->rotateLeft = 0;
	cube->player->speed = 7;
	cube->mybool = 1;
}

void	*ft_malloc(unsigned long size)
{
	void	*ptr;

	ptr = (void *)malloc(size);
	if (!ptr)
		ft_error("Error Malloc failed\n");
	return (ptr);
}

void	allocations(t_cube *cube)
{
	cube->map = (t_map *)ft_malloc(sizeof(t_map));
	cube->player = (t_player *)ft_malloc(sizeof(t_player));
	cube->ray = (t_ray *)ft_malloc(sizeof(t_ray) * WIDTH);
	cube->texture = (t_texture *)ft_malloc(sizeof(t_texture));
	cube->sprite = (t_sprite *)ft_malloc(sizeof(t_sprite));
}

void	setRayDirection(t_cube *cube, int colom)
{
	cube->ray[colom].facingDown = cube->ray[colom].rayAngle > 0 && cube->ray[colom].rayAngle < M_PI;
	cube->ray[colom].facingUp = !cube->ray[colom].facingDown;
	cube->ray[colom].facingRight = cube->ray[colom].rayAngle < (M_PI/2) || cube->ray[colom].rayAngle > (3*M_PI)/2;
	cube->ray[colom].facingLeft = !cube->ray[colom].facingRight;
}

void ft_free(void *ptr, void *ptr2, void *ptr3)
{
    if (ptr)
	{
        free(ptr);
        ptr = NULL;
    }
    if (ptr2)
	{
        free(ptr2);
        ptr2 = NULL;
    }
	if (ptr3)
	{
		free(ptr3);
        ptr3 = NULL;
	}
}