#include "../include/cube.h"

void	checkInter_H(t_cube *cube, float Xnearest, float Ynearest, float xstep, float ystep, int colom)
{
	while (Xnearest > 0 && Ynearest > 0 && Xnearest < WIDTH && Ynearest < HEIGHT)
	{
		// getPixel => -1 for up 1 for down
		if (!wallCheck(cube, Xnearest, Ynearest + getPixel(cube, colom, true)))
			break ;
		Xnearest += xstep;
		Ynearest += ystep;
	}
	cube->ray[colom].horizHitP->x = Xnearest;
	cube->ray[colom].horizHitP->y = Ynearest;
}

void	getHorizInter(t_cube *cube, int colom)
{
    float   Xnearest;
    float   Ynearest;

	Ynearest = floor(cube->player->y / CELL_SIZE) * CELL_SIZE;
	if (cube->ray[colom].facingDown == true)
		Ynearest += CELL_SIZE;
	Xnearest = cube->player->x + (Ynearest - cube->player->y) / (float)(tan(cube->ray[colom].rayAngle));

	float	xstep, ystep;
	ystep = CELL_SIZE;
	if (cube->ray[colom].facingUp == true)
		ystep *= -1;
	xstep = ystep /(float)(tan(cube->ray[colom].rayAngle));
	if (cube->ray[colom].facingLeft && xstep > 0)
		xstep *= -1;
	if (cube->ray[colom].facingRight && xstep < 0)
		xstep *= -1;

	checkInter_H(cube, Xnearest, Ynearest, xstep, ystep, colom);
}

void	checkInter_V(t_cube *cube, float Xnearest, float Ynearest, float xstep, float ystep, int colom)
{
	while (Xnearest > 0 && Ynearest > 0 && Xnearest < WIDTH && Ynearest < HEIGHT)
	{
		if (!wallCheck(cube, Xnearest + getPixel(cube, colom, false), Ynearest))
			break ;
		Xnearest += xstep;
		Ynearest += ystep;
	}
	cube->ray[colom].vertiHitP->x = Xnearest;
	cube->ray[colom].vertiHitP->y = Ynearest;
}

void getVertInter(t_cube *cube, int colom)
{
	float	Xnearest;
    float   Ynearest;

    Xnearest = floor(cube->player->x / CELL_SIZE) * CELL_SIZE;
	if (cube->ray[colom].facingRight)
    	Xnearest += CELL_SIZE;
	Ynearest = cube->player->y + (Xnearest - cube->player->x) * (tan(cube->ray[colom].rayAngle));

	float xstep, ystep;
	xstep = CELL_SIZE;
	if (cube->ray[colom].facingLeft == true)
		xstep *= -1;
	ystep = xstep * (tan(cube->ray[colom].rayAngle));
	if (cube->ray[colom].facingUp && ystep > 0)
		ystep *= -1;
	if (cube->ray[colom].facingDown && ystep < 0)
		ystep *= -1;

	checkInter_V(cube, Xnearest, Ynearest, xstep, ystep, colom);
}

// void	getHorizInter(t_cube *cube, int colom)
// {
// 	cube->ray[colom].yInter = floor(cube->player->y / CELL_SIZE) * CELL_SIZE;
// 	if (cube->ray[colom].facingDown == true)
// 		cube->ray[colom].yInter += CELL_SIZE;
// 	cube->ray[colom].xInter = cube->player->x + (cube->ray[colom].yInter - cube->player->y) / (float)(tan(cube->ray[colom].rayAngle));

// 	float	xstep, ystep;
// 	ystep = CELL_SIZE;
// 	if (cube->ray[colom].facingUp == true)
// 		ystep *= -1;
// 	xstep = ystep /(float)(tan(cube->ray[colom].rayAngle));
// 	if (cube->ray[colom].facingLeft && xstep > 0)
// 		xstep *= -1;
// 	if (cube->ray[colom].facingRight && xstep < 0)
// 		xstep *= -1;

// 	float	posX, posY;
// 	posX = cube->ray[colom].xInter;
// 	posY = cube->ray[colom].yInter;
// 	while (posX > 0 && posY > 0 && posX < WIDTH && posY < HEIGHT)
// 	{
// 		// getPixel => -1 for up 1 for down
// 		if (!wallCheck(cube, posX, posY + getPixel(cube, colom, true)))
// 			break ;
// 		posX += xstep;
// 		posY += ystep;
// 	}

// 	cube->ray[colom].horizHitP->y = posY;
// 	cube->ray[colom].horizHitP->x = posX;
// }

// void getVertInter(t_cube *cube, int colom)
// {
//     cube->ray[colom].xInter = floor(cube->player->x / CELL_SIZE) * CELL_SIZE;
// 	if (cube->ray[colom].facingRight)
//     	cube->ray[colom].xInter += CELL_SIZE;
// 	cube->ray[colom].yInter = cube->player->y + (cube->ray[colom].xInter - cube->player->x) * (tan(cube->ray[colom].rayAngle));

// 	float xstep, ystep;
// 	xstep = CELL_SIZE;
// 	if (cube->ray[colom].facingLeft == true)
// 		xstep *= -1;
// 	ystep = xstep * (tan(cube->ray[colom].rayAngle));
// 	if (cube->ray[colom].facingUp && ystep > 0)
// 		ystep *= -1;
// 	if (cube->ray[colom].facingDown && ystep < 0)
// 		ystep *= -1;

// 	float posX, posY;
// 	posX = cube->ray[colom].xInter;
// 	posY = cube->ray[colom].yInter;
// 	while (posX > 0 && posY > 0 && posX < WIDTH && posY < HEIGHT)
// 	{
// 		if (!wallCheck(cube, posX + getPixel(cube, colom, false), posY))
// 			break ;
// 		posX += xstep;
// 		posY += ystep;
// 	}
// 	cube->ray[colom].vertiHitP->x = posX;
// 	cube->ray[colom].vertiHitP->y = posY;
// }
