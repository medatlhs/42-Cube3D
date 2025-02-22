#include "../include/cube.h"

void	getHorizInter(t_cube *cube, int colom)
{
	cube->ray[colom].yInter = floor(cube->player->y / cube->map->sqaureFactorY) * cube->map->sqaureFactorY;
	if (cube->ray[colom].facingDown == true)
		cube->ray[colom].yInter += cube->map->sqaureFactorY;
	cube->ray[colom].xInter = cube->player->x + (cube->ray[colom].yInter - cube->player->y) / (tan(cube->ray[colom].rayAngle));

	float	xstep, ystep;
	ystep = cube->map->sqaureFactorY;
	if (cube->ray[colom].facingUp == true && ystep > 0)
		ystep *= -1;
	xstep = ystep / (tan(cube->ray[colom].rayAngle));
	if (cube->ray[colom].facingLeft && xstep > 0)
		xstep *= -1;
	else if (cube->ray[colom].facingRight && xstep < 0)
		xstep *= -1;

	float	posX, posY;
	posX = cube->ray[colom].xInter;
	posY = cube->ray[colom].yInter;
	while (posX > 0 && posY > 0 && posX < WIDTH && posY < HEIGHT)
	{
		// getPixel => -1 for up 1 for down
		if (!wallCheck(cube, posX, posY + getPixel(cube, colom, true)))
			break ;
		posX += xstep;
		posY += ystep;
	}
	// draw_x_sign(cube, posX, posY, 10, 0x0000FF);
	cube->ray[colom].horizHitP->x = posX;
	cube->ray[colom].horizHitP->y = posY;
}

void getVertInter(t_cube *cube, int colom)
{
	cube->ray[colom].xInter = floor(cube->player->x / cube->map->sqaureFactorX) * cube->map->sqaureFactorX;
	if (cube->ray[colom].facingRight == true)
		cube->ray[colom].xInter += cube->map->sqaureFactorX;
	cube->ray[colom].yInter = cube->player->y + (cube->ray[colom].xInter - cube->player->x) * (tan(cube->ray[colom].rayAngle));

	float xstep, ystep;
	xstep = cube->map->sqaureFactorX;
	if (cube->ray[colom].facingLeft == true && xstep > 0)
		xstep *= -1;
	ystep = xstep * (tan(cube->ray[colom].rayAngle));
	if (cube->ray[colom].facingUp && ystep > 0)
		ystep *= -1;
	else if (cube->ray[colom].facingDown && ystep < 0)
		ystep *= -1;

	float posX, posY;
	posX = cube->ray[colom].xInter;
	posY = cube->ray[colom].yInter;
	while (posX > 0 && posY > 0 && posX < WIDTH && posY < HEIGHT)
	{
		if (!wallCheck(cube, posX + getPixel(cube, colom, false), posY))
			break ;
		posX += xstep;
		posY += ystep;
	}
	cube->ray[colom].vertiHitP->x = posX;
	cube->ray[colom].vertiHitP->y = posY;
}

void    render_3dscene(t_cube data)
{
    int i = -1;
    while (++i < NUM_RAYS)
    {
        float perpDistance = data.ray[i].distance * cos(data.ray[i].rayAngle - (data.player->degree * (PI/180)));
        // float distanceProjPlane = (WIDTH / 2) / tan(HEIGHT / 2);
        float distanceProjPlane = (WIDTH / 2) / tan((FOV * PI / 180) / 2);
        float projectedWallHeight = (data.map->sqaureFactorY / perpDistance) * distanceProjPlane;

        int wallStripHeight = (int)projectedWallHeight;

        int wallTopPixel = (HEIGHT / 2) - (wallStripHeight / 2);
        int wallBottomPixel = (HEIGHT / 2) + (wallStripHeight / 2);

        if (wallTopPixel < 0)
            wallTopPixel = 0;
        if (wallBottomPixel >= HEIGHT)
            wallBottomPixel = HEIGHT - 2;
        int k = wallTopPixel;

        while (k <= wallBottomPixel)
        {
			if (data.ray[i].closestHit == HORIZONTAL)
				myPixelPut(&data, i, k, 0xFFFFFF);
			else
				myPixelPut(&data, i, k, 0xD3D3D3);
			k++;
        }
    }
}

void	initRayData(t_cube *cube, float rayAngle, int colom)
{
	cube->ray[colom].closestHit = UNKNOWN;
	cube->ray[colom].rayAngle = rayAngle;
	cube->ray[colom].horizHitP = (t_point *)ft_malloc(sizeof(t_point));
	cube->ray[colom].vertiHitP = (t_point *)ft_malloc(sizeof(t_point));
}

void	castAllRays(t_cube *cube)
{
	float	firstRayAngle;
	float	angleInc;
	int		colom;

	firstRayAngle = (cube->player->degree - FOV/2) * (PI / 180);
	firstRayAngle = normalize(firstRayAngle);
	angleInc = (FOV * PI/180) / (float)WIDTH;
	colom = -1;
	while (++colom < WIDTH)
	{
		initRayData(cube, firstRayAngle, colom);
		setRayDirection(cube, colom);
		getHorizInter(cube, colom);
		getVertInter(cube, colom);
		getClosestHit(cube, colom);
		firstRayAngle += angleInc;
		ft_free(cube->ray[colom].horizHitP, cube->ray[colom].vertiHitP);
	}
}
