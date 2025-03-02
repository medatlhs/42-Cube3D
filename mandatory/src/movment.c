#include "../include/cube.h"

void	updatePosition(t_cube *cube)
{
	if (cube->player->moveFront == true)
		moveForward(cube);
	else if (cube->player->moveBack == true)
		moveBack(cube);
	if (cube->player->moveRight == true)
		moveSides(cube, 1);
	else if (cube->player->moveLeft == true)
		moveSides(cube, -1);
	if (cube->player->rotateRight == true)
		cube->player->degree += 2;
	else if (cube->player->rotateLeft == true)
		cube->player->degree -= 2;
}

int	wallCheck(t_cube *cube, int	newX, int newY)
{
	int	gridPositionX;
	int	gridPositionY;

	if (newX < 0 || newX < 0)
		return (1);
	gridPositionX = floor(newX/CELL_SIZE);
	gridPositionY = floor(newY/CELL_SIZE);
	if (cube->map->map[gridPositionY][gridPositionX])
		return (0);
	return (1);
}

void moveSides(t_cube *cube, int direction)
{
    float   degreeRad;
    float   strafeAngle;
    float   newX;
    float   newY;

    degreeRad = cube->player->degree * (PI / 180.0);
    strafeAngle = degreeRad + (direction * (PI / 2.0));
    newX = cube->player->x + (cos(strafeAngle) * cube->player->speed);
    newY = cube->player->y + (sin(strafeAngle) * cube->player->speed);
    if (!wallCheck(cube, newX, newY))
        return;
    cube->player->x = newX;
    cube->player->y = newY;
}


void	moveForward(t_cube *cube)
{
	float	degreeRad;
	float	newX;
	float	newY;

	degreeRad = cube->player->degree * (PI/180);
	newX = cube->player->x + (cos(degreeRad) * cube->player->speed);
	newY = cube->player->y + (sin(degreeRad) * cube->player->speed);
	if (!wallCheck(cube, newX-1, newY-1))
		return ;
	cube->player->x = newX;
	cube->player->y = newY;
}

void	moveBack(t_cube *cube)
{
	float	degreeRad;
	float	newX;
	float	newY;

	degreeRad = cube->player->degree * (PI/180);
	newX = cube->player->x - (cos(degreeRad) * cube->player->speed);
	newY = cube->player->y - (sin(degreeRad) * cube->player->speed);
	if (!wallCheck(cube, newX -1, newY-1))
		return ;
	cube->player->x = newX;
	cube->player->y = newY;
}
